#include "Client.hpp"
#include "Channel.hpp"
#include <algorithm>

Client::Client(int fd, std::string ip) : _fd(fd), _ip(ip), _disconnected(false), _nick("*"), \
    _realname(""), _hasPassword(false), _registered(false) {}

int Client::getFd() const
{
    return (_fd);
}

const std::string& Client::getBuffer() const
{
    return (_buffer);
}

bool Client::isDisconnected() const
{
    return (_disconnected);
}

void Client::addData(const char *data, int bytes)
{
    _buffer.append(data, bytes);
}

void Client::disconnect()
{
    _disconnected = true;
}

bool Client::getNextMessage(std::string& message)
{
    size_t pos = _buffer.find("\r\n");

    if (pos == std::string::npos)
        return (false);

    message = _buffer.substr(0, pos);
    _buffer.erase(0, pos + 2);

    return (true);
}

void Client::setNick(std::string nick)
{
    _nick = nick;
}

std::string Client::getNick() const
{
    return (_nick);
}

void Client::setUsername(std::string username)
{
    _username = username;
}

std::string Client::getUsername() const
{
    return (_username);
}

void Client::setRealname(std::string realname)
{
    _realname = realname;
}

std::string Client::getRealname() const
{
    return (_realname);
}

void Client::queueMessage(const std::string& message)
{
    _sendBuffer += message;
}

const std::string& Client::getSendBuffer() const
{
    return (_sendBuffer);
}

void Client::removeSentData(size_t bytes)
{
    if (bytes >= _sendBuffer.size())
        _sendBuffer.clear();
    else
        _sendBuffer.erase(0, bytes);
}

bool Client::isRegistered()
{
    return (_registered);
}

void Client::registerClient()
{
    _registered = true;
}

void Client::setPassword()
{
    _hasPassword = true;
}

bool Client::hasPassword()
{
    return (_hasPassword);
}

void Client::addChannel(Channel& channel)
{
    _channels.push_back(&channel);
}

bool Client::inChannel(const Channel& channel) const
{
    if (std::find(_channels.begin(), _channels.end(), &channel) != _channels.end())
        return (true);
    return (false);
}

const std::vector<Channel*>& Client::getChannels() const
{
    return (_channels);
}

void Client::removeChannel(Channel& channel)
{
    for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
    {
        if (*it == &channel)
        {
            _channels.erase(it);
            return;
        }
    }
}

std::string Client::getIp()
{
	return (_ip);
}