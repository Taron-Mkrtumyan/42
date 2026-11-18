#ifndef SERVER_HPP
#define SERVER_HPP

#include <csignal>
#include <vector>
#include <list>
#include <poll.h>
#include <arpa/inet.h>
#include "Client.hpp"
#include "MessageParser.hpp"
#include "CommandHandler.hpp"
#include "Channel.hpp"
#include "BotHelper.hpp"

extern volatile sig_atomic_t g_serverRunning;

class Server
{
public:
    Server(int port, std::string password);
    ~Server();

    bool		init();
    void		run();
	bool		isNickInUse(std::string nick);
	bool		tryClientPassword(std::string password);
	Channel*	findChannel(const std::string& title);
	Channel&	addChannel(Client& owner, std::string title);
	void		removeChannel(Channel* channel);
	Client*		findClient(std::string client);
	bool		ircCaseEqual(const std::string& a, const std::string& b);

private:
    int                 	_serverFd;
    int                 	_port;
	std::string				_password;
    bool                	_running;
    std::list<Client>		_clients;
	std::list<Channel>		_channels;
	MessageParser  			_parser;
	CommandHandler			_commandHandler;
	BotHelper				_botHelper;

    int		createSocket();
    bool	setNonBlocking(int fd);

    void	acceptNewClients();
    void	handleClientData(Client& client);
	void	processClientMessages(Client& client);
    void	removeDisconnectedClients();
    void	handleServerEvent(short events);
    void	handleClientEvent(Client& client, short events);
	void	sendClientData(Client& client);
	bool	initBot();
};

#endif
