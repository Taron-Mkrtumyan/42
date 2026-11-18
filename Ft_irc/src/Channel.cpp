#include "Channel.hpp"
#include "Client.hpp"
#include <algorithm>

Channel::Channel(Client& owner, std::string title)
    : _owner(&owner), _title(title), _userLimit(0),
      _inviteOnly(false), _topicRestricted(false) 
{
	_operators.push_back(&owner);
}

void Channel::addMember(Client& client)
{
    if (!hasMember(client))
        _members.push_back(&client);
}

void Channel::removeMember(Client& client)
{
    std::vector<Client*>::iterator	it;

    it = std::find(_members.begin(), _members.end(), &client);
    if (it != _members.end())
        _members.erase(it);

    it = std::find(_operators.begin(), _operators.end(), &client);
    if (it != _operators.end())
        _operators.erase(it);
}

void Channel::addOperator(Client& client)
{
    if (hasMember(client) && std::find(_operators.begin(), _operators.end(), &client) == _operators.end())
        _operators.push_back(&client);
}

void Channel::removeOperator(Client& client)
{
	std::vector<Client*>::iterator	it;

	it = std::find(_operators.begin(), _operators.end(), &client);
	if (it != _operators.end())
		_operators.erase(it);
}

void Channel::setPassword(std::string password)
{
    _password = password;
}

std::string Channel::getTitle() const
{
    return (_title);
}

std::string Channel::getTopic() const
{
    return (_topic);
}

std::string Channel::getPassword() const
{
    return (_password);
}

bool Channel::isInviteOnly() const
{
    return (_inviteOnly);
}

bool Channel::isTopicRestricted() const
{
    return (_topicRestricted);
}

bool Channel::hasPassword() const
{
    return (!_password.empty());
}

bool Channel::hasUserLimit() const
{
    return (_userLimit > 0);
}

bool Channel::hasMember(const Client& client) const
{
    if (std::find(_members.begin(), _members.end(), &client) != _members.end())
        return (true);
    return (false);
}

bool Channel::hasOperator(const Client& client) const
{
    if (std::find(_operators.begin(), _operators.end(), &client) != _operators.end())
        return (true);
    return (false);
}

size_t Channel::getUserLimit() const
{
    return (_userLimit);
}

size_t Channel::getMembersCount() const
{
    return (_members.size());
}
const std::vector<Client*>& Channel::getMembers() const
{
    return (_members);
}

const Client* Channel::getOwner() const
{
    return (_owner);
}

void Channel::setTopic(std::string topic)
{
	_topic = topic;
}

void Channel::setInviteOnly(bool enabled)
{
    _inviteOnly = enabled;
}

void Channel::setTopicRestricted(bool enabled)
{
    _topicRestricted = enabled;
}


void Channel::removePassword()
{
    _password.clear();
}

void Channel::setUserLimit(size_t limit)
{
    _userLimit = limit;
}

void Channel::removeUserLimit()
{
    _userLimit = 0;
}

bool Channel::hasInvited(const Client& client) const
{
	if (std::find(_invitedClients.begin(), _invitedClients.end(), &client) != _invitedClients.end())
        return (true);
    return (false);
}

void Channel::addInvited(Client& client)
{
	if (!hasInvited(client))
		_invitedClients.push_back(&client);
}