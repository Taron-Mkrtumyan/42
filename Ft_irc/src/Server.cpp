#include "Server.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <cstdio>
#include <cstring>
#include <ostream>
#include <iostream>


Server::Server(int port, std::string password) : _serverFd(-1), _port(port), _password(password), _running(false) {}

Server::~Server()
{
    for (std::list<Client>::iterator it = _clients.begin(); it != _clients.end(); ++it)
	{
        close(it->getFd());
		it->disconnect();
	}

    if (_serverFd != -1)
	{
        close(_serverFd);
		_serverFd = -1;
	}
}

bool Server::setNonBlocking(int fd)
{
    if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1)
        return (false);

    return (true);
}

int Server::createSocket()
{
    int	fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd == -1)
    {
        perror("socket");
        return (-1);
    }

    int opt = 1;

    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
    {
        perror("setsockopt");
        close(fd);
        return (-1);
    }

    if (!setNonBlocking(fd))
    {
        perror("fcntl");
        close(fd);
        return (-1);
    }

    struct sockaddr_in	address;
    std::memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_port = htons(_port);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(fd, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        perror("bind");
        close(fd);
        return (-1);
    }

    if (listen(fd, 10) == -1)
    {
        perror("listen");
        close(fd);
        return (-1);
    }

    return (fd);
}

bool Server::init()
{
    _serverFd = createSocket();

	if (_serverFd == -1)
		return (false);

	if (!initBot())
	{
		close(_serverFd);
		_serverFd = -1;
		return (false);
	}

    _running = true;
    return (true);
}

bool Server::initBot()
{
    return (_botHelper.init(_port, _password));
}

void Server::acceptNewClients()
{
    while (true)
    {
		struct sockaddr_in		client_addr;
        socklen_t               len = sizeof(client_addr);

        int clientFd = accept(_serverFd, (struct sockaddr*)&client_addr, &len);

        if (clientFd == -1)
        {
			if (errno == EAGAIN || errno == EWOULDBLOCK)
				break;
            
			perror("accept");
            break;
        }

		char ip_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, ip_str, sizeof(ip_str));

        if (!setNonBlocking(clientFd))
        {
            perror("fcntl");
            close(clientFd);
            continue;
        }

        _clients.push_back(Client(clientFd, ip_str));

        std::cout << "New client connected: " << clientFd << " from " << ip_str << std::endl;
    }
}

void Server::processClientMessages(Client& client)
{
    std::string rawMessage;

    while (client.getNextMessage(rawMessage))
    {
        Message message;

        if (!_parser.parse(rawMessage, message))
            continue;

        _commandHandler.handle(*this, client, message);
    }
}

void Server::handleClientData(Client& client)
{
    char	buffer[1024];

    while (true)
    {
        ssize_t	bytes = recv(client.getFd(), buffer, sizeof(buffer), 0);

        if (bytes > 0)
        {
            client.addData(buffer, bytes);
            continue;
        }

        if (bytes == 0)
            client.disconnect();

        break;
    }
	processClientMessages(client);
}

void Server::handleServerEvent(short events)
{
    if (events & (POLLERR | POLLHUP | POLLNVAL))
    {
        std::cerr << "Server socket error" << std::endl;
        _running = false;
        return;
    }

    if (events & POLLIN)
        acceptNewClients();
}

void Server::handleClientEvent(Client& client, short events)
{
    if (events & (POLLERR | POLLNVAL))
    {
        client.disconnect();
        return;
    }

    if (events & POLLIN)
        handleClientData(client);

    if (client.isDisconnected())
        return;

    if (events & POLLOUT)
        sendClientData(client);

    if (events & POLLHUP)
        client.disconnect();
}

void Server::removeDisconnectedClients()
{
    std::list<Client>::iterator it = _clients.begin();

    while (it != _clients.end())
    {
        if (it->isDisconnected())
        {
            std::cout << "Client disconnected: " << it->getFd() << std::endl;

            std::vector<Channel*> channels = it->getChannels();

            for (size_t i = 0; i < channels.size(); ++i)
			{
                channels[i]->removeMember(*it);
				if (channels[i]->getMembersCount() == 0)
					removeChannel(channels[i]);
			}
            close(it->getFd());
            it = _clients.erase(it);
        }
        else
            ++it;
    }
}

void Server::sendClientData(Client& client)
{
    const std::string& buffer = client.getSendBuffer();

    if (buffer.empty())
        return;

    ssize_t sent = send(client.getFd(), buffer.c_str(), buffer.size(), MSG_NOSIGNAL);

    if (sent > 0)
        client.removeSentData(sent);
}

bool Server::isNickInUse(std::string nick)
{
    for (std::list<Client>::const_iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        if (ircCaseEqual(it->getNick(), nick))
            return (true);
    }
    return (false);
}

bool Server::ircCaseEqual(const std::string& nick1, const std::string& nick2)
{
    if (nick1.size() != nick2.size())
        return (false);

    for (size_t i = 0; i < nick1.size(); ++i)
    {
        if (std::tolower(static_cast<unsigned char>(nick1[i])) != std::tolower(static_cast<unsigned char>(nick2[i])))
            return (false);
    }
    return (true);
}

bool Server::tryClientPassword(std::string password)
{
	if (_password == password)
		return (true);
	return (false);
}

Channel* Server::findChannel(const std::string& title)
{
    for (std::list<Channel>::iterator it = _channels.begin(); it != _channels.end(); ++it)
    {
        if (it->getTitle() == title)
            return (&(*it));
    }
    return (NULL);
}

Channel& Server::addChannel(Client& owner, std::string title)
{
    _channels.push_back(Channel(owner, title));
    Channel& channel = _channels.back();
    channel.addMember(owner);
    channel.addOperator(owner);
    owner.addChannel(channel);

    return (channel);
}

void Server::removeChannel(Channel* channel)
{
    for (std::list<Channel>::iterator it = _channels.begin(); it != _channels.end(); ++it)
    {
        if (&(*it) == channel)
        {
            _channels.erase(it);
            return;
        }
    }
}

Client* Server::findClient(std::string client)
{
	for (std::list<Client>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        if (it->getNick() == client)
            return (&(*it));
    }
    return (NULL);
}

void Server::run()
{
	std::vector<struct pollfd>	pollFds;
	std::vector<Client*>		pollClients;

    while (_running && g_serverRunning)
    {
		pollFds.clear();
		pollClients.clear();

		struct pollfd serverPoll;
        serverPoll.fd = _serverFd;
        serverPoll.events = POLLIN;
        serverPoll.revents = 0;

        pollFds.push_back(serverPoll);

		struct pollfd botPoll;
		botPoll.fd = _botHelper.getFd();
		botPoll.events = POLLIN;
		botPoll.revents = 0;

		if (_botHelper.hasDataToSend())
			botPoll.events |= POLLOUT;

		pollFds.push_back(botPoll);

        for (std::list<Client>::iterator it = _clients.begin(); it != _clients.end(); ++it)
		{
			struct pollfd clientPoll;

			clientPoll.fd = it->getFd();
			clientPoll.events = POLLIN;
			clientPoll.revents = 0;

			if (!it->getSendBuffer().empty())
				clientPoll.events |= POLLOUT;

			pollFds.push_back(clientPoll);
			pollClients.push_back(&(*it));
		}

        int	ret = poll(&pollFds[0], pollFds.size(), 100);

        if (ret == -1)
        {
			if (errno == EINTR)
				continue;
			perror("poll");
			break;
        }

        if (pollFds[0].revents)
            handleServerEvent(pollFds[0].revents);
		
		if (pollFds[1].revents)
            _botHelper.handleEvent(pollFds[1].revents);

        for (size_t i = 2; i < pollFds.size(); ++i)
		{
			if (pollFds[i].revents)
				handleClientEvent(*pollClients[i - 2], pollFds[i].revents);
		}

        removeDisconnectedClients();
    }
}