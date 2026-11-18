#include "CommandHandler.hpp"
#include "Server.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "IRCReplies.hpp"


void CommandHandler::handle(Server& server, Client& client, const Message& message)
{
    if (message.command == "NICK")
        handleNick(server, client, message);
    else if (message.command == "USER")
        handleUser(server, client, message);
	else if (message.command == "PASS")
		handlePass(server, client, message);
    else if (message.command == "JOIN")
        handleJoin(server, client, message);
    else if (message.command == "PRIVMSG")
        handlePrivmsg(server, client, message);
    else if (message.command == "QUIT")
        handleQuit(server, client, message);
	else if (message.command == "MODE")
		handleMode(server, client, message);
	else if (message.command == "TOPIC")
		handleTopic(server, client, message);
	else if (message.command == "KICK")
		handleKick(server, client, message);
	else if (message.command == "INVITE")
		handleInvite(server, client, message);
	else
	{
		std::ostringstream	error_msg;

		error_msg << message.command << " :Unknown command";
		sendNumeric(client, IRC::ERR_UNKNOWNCOMMAND, error_msg.str());
	}
}

void	CommandHandler::sendMessage(Client& client, std::string msg)
{
	client.queueMessage(msg);
}

void CommandHandler::sendNumeric(Client& client, int code, const std::string& message)
{
    std::ostringstream	response;

    response << ":server " << std::setw(3) << std::setfill('0') \
	<< code << " " << client.getNick() << " " << message << "\r\n";

    sendMessage(client, response.str());
}

bool isValidNick(const std::string& nick)
{
    if (nick.empty() || nick.size() > 9)
        return (false);

    if (!std::isalpha(nick[0]) && std::string("[]\\`_^{|}").find(nick[0]) == std::string::npos)
        return (false);

    for (size_t i = 1; i < nick.size(); ++i)
    {
        char c = nick[i];

        if (!std::isalnum(c) && std::string("-[]\\`_^{|}").find(c) == std::string::npos)
            return (false);
    }

    return (true);
}

std::string getChannelModes(const Channel& channel)
{
    std::string			modes = "+";
    std::ostringstream	arguments;

    if (channel.isInviteOnly())
        modes += "i";

    if (channel.isTopicRestricted())
        modes += "t";

    if (channel.hasPassword())
    {
        modes += "k";
        arguments << " " << channel.getPassword();
    }

    if (channel.hasUserLimit())
    {
        modes += "l";
        arguments << " " << channel.getUserLimit();
    }

    return (modes + arguments.str());
}

bool modeNeedsArgument(char mode, bool enabled)
{
    if (mode == 'k' || mode == 'o')
        return (true);

    if (mode == 'l' && enabled)
        return (true);

    return (false);
}

bool isValidLimit(const std::string& value)
{
    if (value.empty())
        return (false);

    for (size_t i = 0; i < value.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(value[i])))
            return (false);
    }

    std::istringstream	stream(value);
    size_t				limit;

    stream >> limit;

    return (!stream.fail() && stream.eof() && limit > 0);
}

ModeValidationResult CommandHandler::validateModes(const Channel& channel, \
	const std::vector<ModeChange>& changes, Server& server, std::string& errorArgument)
{
    bool hasPassword = channel.hasPassword();

    for (size_t i = 0; i < changes.size(); ++i)
    {
        const ModeChange& change = changes[i];

        if (change.mode == 'k')
        {
            if (change.enabled)
            {
                if (hasPassword)
                    return (MODE_VALIDATION_KEYSET);

                if (change.argument.empty())
                {
                    errorArgument = change.argument;
                    return (MODE_VALIDATION_INVALID_ARGUMENT);
                }

                hasPassword = true;
            }
            else
                hasPassword = false;
        }

        else if (change.mode == 'l')
        {
            if (change.enabled)
            {
                if (!isValidLimit(change.argument))
                {
                    errorArgument = change.argument;
                    return (MODE_VALIDATION_INVALID_ARGUMENT);
                }
            }
        }

        else if (change.mode == 'o')
        {
            Client* target = server.findClient(change.argument);

            if (!target)
            {
                errorArgument = change.argument;
                return (MODE_VALIDATION_NO_SUCH_NICK);
            }

            if (!channel.hasMember(*target))
            {
                errorArgument = change.argument;
                return (MODE_VALIDATION_USER_NOT_IN_CHANNEL);
            }
        }
    }

    return (MODE_VALIDATION_SUCCESS);
}

void CommandHandler::applyModes(Channel& channel, const std::vector<ModeChange>& changes, Server& server)
{
    for (size_t i = 0; i < changes.size(); ++i)
    {
        const ModeChange& change = changes[i];

        if (change.mode == 'i')
            channel.setInviteOnly(change.enabled);

        else if (change.mode == 't')
            channel.setTopicRestricted(change.enabled);

        else if (change.mode == 'k')
        {
            if (change.enabled)
                channel.setPassword(change.argument);
            else
                channel.removePassword();
        }

        else if (change.mode == 'l')
        {
            if (change.enabled)
            {
                std::istringstream	stream(change.argument);
                size_t				limit;

                stream >> limit;
                channel.setUserLimit(limit);
            }
            else
                channel.removeUserLimit();
        }

        else if (change.mode == 'o')
        {
            Client* target = server.findClient(change.argument);

            if (change.enabled)
                channel.addOperator(*target);
            else
                channel.removeOperator(*target);
        }
    }
}

ModeParseResult CommandHandler::parseModes(const Message& message, std::vector<ModeChange>& changes, char& invalidMode)
{
    const std::string&	modestring = message.params[1];
    size_t				argIndex = 2;
    size_t				argumentModes = 0;
    bool				enabled = true;
    bool				signFound = false;
    bool				lastWasSign = false;

    for (size_t i = 0; i < modestring.size(); ++i)
    {
        char c = modestring[i];

        if (c == '+' || c == '-')
        {
            if (lastWasSign)
                return (MODE_PARSE_INVALID_SYNTAX);

            enabled = (c == '+');
            signFound = true;
            lastWasSign = true;
            continue;
        }

        if (!signFound)
            return (MODE_PARSE_INVALID_SYNTAX);

        if (c != 'i' && c != 't' && c != 'k' && c != 'l' && c != 'o')
        {
            invalidMode = c;
            return (MODE_PARSE_UNKNOWN);
        }

        lastWasSign = false;

        ModeChange change;
        change.mode = c;
        change.enabled = enabled;

        if (modeNeedsArgument(c, enabled))
        {
            ++argumentModes;

            if (argumentModes > 3)
                return (MODE_PARSE_TOO_MANY_ARGUMENTS);

            if (argIndex >= message.params.size())
                return (MODE_PARSE_MISSING_ARGUMENT);

            change.argument = message.params[argIndex];
            ++argIndex;
        }

        changes.push_back(change);
    }

    if (changes.empty() || lastWasSign)
        return (MODE_PARSE_INVALID_SYNTAX);

    return (MODE_PARSE_SUCCESS);
}

void CommandHandler::joinChannel(Server& server, Client& client, const std::string& title, const std::string& password)
{
    if (title.empty() || title.size() > 50 || title[0] != '#')
        return (sendNumeric(client, IRC::ERR_BADCHANMASK, title + " :Bad Channel Mask"));

    for (size_t i = 0; i < title.size(); ++i)
    {
        if (title[i] == ' ' || title[i] == ',' || title[i] == '\r' || title[i] == '\n' || title[i] == '\0' || title[i] == '\a')
            return (sendNumeric(client, IRC::ERR_BADCHANMASK, title + " :Bad Channel Mask"));
    }

    Channel* channel = server.findChannel(title);
    if (!channel)
        channel = &server.addChannel(client, title);

    else
    {
        if (channel->hasMember(client))
            return;

        if (channel->hasPassword() && channel->getPassword() != password)
            return (sendNumeric(client, IRC::ERR_BADCHANNELKEY, title + " :Cannot join channel (+k)"));


        if (channel->isInviteOnly() && !channel->hasInvited(client))
            return (sendNumeric(client, IRC::ERR_INVITEONLYCHAN, title + " :Cannot join channel (+i)"));

        if (channel->hasUserLimit() && channel->getMembersCount() >= channel->getUserLimit())
            return (sendNumeric(client, IRC::ERR_CHANNELISFULL, title + " :Cannot join channel (+l)"));

        channel->addMember(client);
        client.addChannel(*channel);
    }

    std::string					prefix = ":" + client.getNick() + "!" + client.getUsername() + "@" + client.getIp();
    std::string					reply = prefix + " JOIN :" + title + "\r\n";
    const std::vector<Client*>&	members = channel->getMembers();

    for (size_t i = 0; i < members.size(); ++i)
        sendMessage(*members[i], reply);

    if (!channel->getTopic().empty())
        sendNumeric(client, IRC::RPL_TOPIC, title + " :" + channel->getTopic());
    else
        sendNumeric(client, IRC::RPL_NOTOPIC, title + " :No topic is set");

    std::string	names;

    for (size_t i = 0; i < members.size(); ++i)
    {
        if (!names.empty())
            names += " ";

        if (channel->hasOperator(*members[i]))
            names += "@";

        names += members[i]->getNick();
    }

    sendNumeric(client, IRC::RPL_NAMREPLY, "= " + title + " :" + names);
    sendNumeric(client, IRC::RPL_ENDOFNAMES, title + " :End of /NAMES list");
}

void CommandHandler::handleJoinZero(Server& server, Client& client, std::string msg)
{
    std::vector<Channel*> channels = client.getChannels();

    for (size_t i = 0; i < channels.size(); ++i)
    {
        Channel* channel = channels[i];

		std::string	prefix = ":" + client.getNick() + "!" + client.getUsername() + "@" + client.getIp();
        std::string	reply = prefix + " PART " + channel->getTitle() + " :" + msg + "\r\n";

        const std::vector<Client*>& members = channel->getMembers();

        for (size_t j = 0; j < members.size(); ++j)
            sendMessage(*members[j], reply);

		channel->removeMember(client);
        client.removeChannel(*channel);

        if (channel->getMembersCount() == 0)
            server.removeChannel(channel);
    }
}

std::vector<std::string> CommandHandler::split(const std::string& str, char delimiter)
{
    std::vector<std::string> result;
    size_t start = 0;
    size_t end;

    while ((end = str.find(delimiter, start)) != std::string::npos)
    {
        result.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    result.push_back(str.substr(start));
    return (result);
}

void CommandHandler::tryRegister(Client& client)
{
	if (!client.getUsername().empty() && (!client.getNick().empty() && client.getNick() != "*") && client.hasPassword())
	{
		if (!client.isRegistered())
			sendNumeric(client, IRC::RPL_WELCOME, ":Welcome to the IRC Network " + client.getNick());
		client.registerClient();
	}
}

void CommandHandler::handleNick(Server& server, Client& client, const Message& message)
{
	if (message.params.empty())
		return (sendNumeric(client, IRC::ERR_NONICKNAMEGIVEN, ":No nickname given"));

	if (!isValidNick(message.params[0]))
		return (sendNumeric(client, IRC::ERR_ERRONEUSNICKNAME, message.params[0] + " :Erroneous nickname"));

	if (client.getNick() == message.params[0])
		return;

	if (server.isNickInUse(message.params[0]) && !server.ircCaseEqual(client.getNick(), message.params[0]))
		return (sendNumeric(client, IRC::ERR_NICKNAMEINUSE, message.params[0] + " :Nickname is already in use"));

	std::string				prefix = ":" + client.getNick() + "!" + client.getUsername() + "@" + client.getIp();
	std::string				reply = prefix + " NICK :" + message.params[0] + "\r\n";
	std::vector<Channel*>	channels = client.getChannels();
	std::set<Client*>		users;

	users.insert(&client);

    for (size_t i = 0; i < channels.size(); ++i)
    {
		const std::vector<Client*>& members = channels[i]->getMembers();

		for (size_t j = 0; j < members.size(); ++j)
		{
			if (members[j])
				users.insert(members[j]);
		}
    }

	for (std::set<Client*>::iterator it = users.begin(); it != users.end(); ++it)
		sendMessage(*(*it), reply);

	client.setNick(message.params[0]);


	if (!client.isRegistered())
		tryRegister(client);
}

void CommandHandler::handleUser(Server& server, Client& client, const Message& message)
{
	if (client.isRegistered() || !client.getUsername().empty())
        return (sendNumeric(client, IRC::ERR_ALREADYREGISTRED, ":You may not reregister"));


    if (message.params.size() != 4)
    	return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "USER :Not enough parameters"));


    const std::string& username = message.params[0];
    const std::string& mode = message.params[1];
    const std::string& unused = message.params[2];
    const std::string& realname = message.params[3];
	(void)unused;
	(void)mode;
	(void)server;

    client.setUsername(username);
    client.setRealname(realname);
    tryRegister(client);
}


void CommandHandler::handlePass(Server& server, Client& client, const Message& message)
{
	if (client.isRegistered() || client.hasPassword())
		return (sendNumeric(client, IRC::ERR_ALREADYREGISTRED, "PASS :You may not reregister"));

	if (message.params.empty())
		return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "PASS :Not enough parameters"));


	if (!server.tryClientPassword(message.params[0]))
		return (sendNumeric(client, IRC::ERR_PASSWDMISMATCH, "PASS :Password incorrect"));

	client.setPassword();
	tryRegister(client);
}

void CommandHandler::handleJoin(Server& server, Client& client, const Message& message)
{
	if (!client.isRegistered())
		return (sendNumeric(client, IRC::ERR_NOTREGISTERED, "JOIN :You have not registered"));

	if (message.params.empty())
        return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "JOIN :Not enough parameters"));

    if (message.params[0] == "0")
        return handleJoinZero(server, client, "Leaving all channels");

    std::vector<std::string> channels = split(message.params[0], ',');
    std::vector<std::string> passwords;

    if (message.params.size() > 1)
        passwords = split(message.params[1], ',');

    for (size_t i = 0; i < channels.size(); ++i)
    {
        std::string password;

        if (i < passwords.size())
            password = passwords[i];

        joinChannel(server, client, channels[i], password);
    }
}


void CommandHandler::handlePrivmsg(Server& server, Client& client, const Message& message)
{
    if (!client.isRegistered())
        return (sendNumeric(client, IRC::ERR_NOTREGISTERED, ":You have not registered"));

    if (message.params.empty() || message.params[0].empty())
        return (sendNumeric(client, IRC::ERR_NORECIPIENT, ":No recipient given (PRIVMSG)"));

    if (message.params.size() < 2 || message.params[1].empty())
        return (sendNumeric(client, IRC::ERR_NOTEXTTOSEND, ":No text to send"));

    std::vector<std::string>	recipients = split(message.params[0], ',');
    std::string					prefix = ":" + client.getNick() + "!" + client.getUsername() + "@" + client.getIp();

    for (size_t i = 0; i < recipients.size(); ++i)
    {
        if (recipients[i].empty())
            continue;

        if (recipients[i][0] == '#')
        {
            Channel* channel = server.findChannel(recipients[i]);

            if (!channel)
            {
                sendNumeric(client, IRC::ERR_NOSUCHCHANNEL, recipients[i] + " :No such channel");
                continue;
            }

            std::string					reply = prefix + " PRIVMSG " + channel->getTitle() + " :" + message.params[1] + "\r\n";
            const std::vector<Client*>&	members = channel->getMembers();

            for (size_t j = 0; j < members.size(); ++j)
            {
                if (members[j] != &client)
                    sendMessage(*members[j], reply);
            }
        }
        else
        {
            Client* target = server.findClient(recipients[i]);

            if (!target)
            {
                sendNumeric(client, IRC::ERR_NOSUCHNICK, recipients[i] + " :No such nick/channel");
                continue;
            }

            std::string reply = prefix + " PRIVMSG " + target->getNick() + " :" + message.params[1] + "\r\n";
            sendMessage(*target, reply);
        }
    }
}

void CommandHandler::handleQuit(Server& server, Client& client, const Message& message)
{
    (void)server;

    std::string prefix = ":" + client.getNick() + "!" + client.getUsername() + "@" + client.getIp();
    std::string reply = prefix + " QUIT";

    if (!message.params.empty())
        reply += " :" + message.params[0];
    else
        reply += " :Client Quit";

    reply += "\r\n";

    std::vector<Channel*>	channels = client.getChannels();
    std::set<Client*>		users;

    for (size_t i = 0; i < channels.size(); ++i)
    {
        const std::vector<Client*>& members = channels[i]->getMembers();

        for (size_t j = 0; j < members.size(); ++j)
        {
            if (members[j] != &client)
                users.insert(members[j]);
        }
    }

    for (std::set<Client*>::iterator it = users.begin(); it != users.end(); ++it)
        sendMessage(*(*it), reply);

    client.disconnect();
}

void CommandHandler::handleMode(Server& server, Client& client, const Message& message)
{
    if (!client.isRegistered())
        return (sendNumeric(client, IRC::ERR_NOTREGISTERED, "MODE :You have not registered"));

    if (message.params.empty())
        return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "MODE :Not enough parameters"));

    Channel* channel = server.findChannel(message.params[0]);
    if (!channel)
        return (sendNumeric(client, IRC::ERR_NOSUCHCHANNEL, message.params[0] + " :No such channel"));

    if (message.params.size() == 1)
        return (sendNumeric(client, IRC::RPL_CHANNELMODEIS, channel->getTitle() + " " + getChannelModes(*channel)));

    if (!channel->hasOperator(client))
        return (sendNumeric(client, IRC::ERR_CHANOPRIVSNEEDED, channel->getTitle() + " :You're not channel operator"));

    std::vector<ModeChange>	changes;
    char					invalidMode = '\0';
    ModeParseResult			parseResult = parseModes(message, changes, invalidMode);

    if (parseResult == MODE_PARSE_UNKNOWN)
    {
        std::string error(1, invalidMode);
        return (sendNumeric(client, IRC::ERR_UNKNOWNMODE, error + " :is unknown mode char to me"));
    }

    if (parseResult == MODE_PARSE_MISSING_ARGUMENT)
        return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "MODE :Not enough parameters"));

    if (parseResult == MODE_PARSE_TOO_MANY_ARGUMENTS)
        return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "MODE :Too many mode parameters"));

    if (parseResult != MODE_PARSE_SUCCESS)
        return;

    std::string				errorArgument;
    ModeValidationResult	validationResult = validateModes(*channel, changes, server, errorArgument);

    if (validationResult == MODE_VALIDATION_KEYSET)
        return (sendNumeric(client, IRC::ERR_KEYSET, channel->getTitle() + " :Channel key already set"));

    if (validationResult == MODE_VALIDATION_INVALID_ARGUMENT)
        return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "MODE :Invalid mode parameter"));

    if (validationResult == MODE_VALIDATION_NO_SUCH_NICK) 
		return (sendNumeric(client, IRC::ERR_NOSUCHNICK, errorArgument + " :No such nick"));

    if (validationResult == MODE_VALIDATION_USER_NOT_IN_CHANNEL)
        return (sendNumeric(client, IRC::ERR_USERNOTINCHANNEL, errorArgument + " " + channel->getTitle() + " :They aren't on that channel"));

    if (validationResult != MODE_VALIDATION_SUCCESS)
        return;

    applyModes(*channel, changes, server);

    std::string	prefix = ":" + client.getNick() + "!" + client.getUsername() + "@" + client.getIp();
    std::string	reply = prefix + " MODE " + channel->getTitle();

    for (size_t i = 1; i < message.params.size(); ++i)
        reply += " " + message.params[i];

    reply += "\r\n";

    const std::vector<Client*>& members = channel->getMembers();

    for (size_t i = 0; i < members.size(); ++i)
        sendMessage(*members[i], reply);
}

void CommandHandler::handleTopic(Server& server, Client& client, const Message& message)
{
    if (!client.isRegistered())
        return (sendNumeric(client, IRC::ERR_NOTREGISTERED, "TOPIC :You have not registered"));

    if (message.params.empty())
        return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "TOPIC :Not enough parameters"));


    Channel* channel = server.findChannel(message.params[0]);
	if (!channel)
        return (sendNumeric(client, IRC::ERR_NOSUCHCHANNEL, message.params[0] + " :No such channel"));

    if (!channel->hasMember(client))
        return (sendNumeric(client, IRC::ERR_NOTONCHANNEL, message.params[0] + " :You're not on that channel"));

    if (message.params.size() == 1)
    {
        if (channel->getTopic().empty())
            return (sendNumeric(client, IRC::RPL_NOTOPIC, message.params[0] + " :No topic is set"));

        return (sendNumeric(client, IRC::RPL_TOPIC, message.params[0] + " :" + channel->getTopic()));
    }

    if (channel->isTopicRestricted() && !channel->hasOperator(client))
        return (sendNumeric(client, IRC::ERR_CHANOPRIVSNEEDED, message.params[0] + " :You're not a channel operator"));

    channel->setTopic(message.params[1]);

	std::string	prefix = ":" + client.getNick() + "!" + client.getUsername() + "@" + client.getIp();
	std::string reply = prefix + " TOPIC " + channel->getTitle() + " :" + channel->getTopic() + "\r\n";
	const std::vector<Client*>&	members = channel->getMembers();

    for (size_t i = 0; i < members.size(); ++i)
		sendMessage(*members[i], reply);
}


void CommandHandler::handleKick(Server& server, Client& client, const Message& message)
{
    if (!client.isRegistered())
        return (sendNumeric(client, IRC::ERR_NOTREGISTERED, "KICK :You have not registered"));

    if (message.params.size() < 2)
        return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "KICK :Not enough parameters"));

    std::vector<std::string>	channels = split(message.params[0], ',');
    std::vector<std::string>	users = split(message.params[1], ',');

    if (channels.empty() || users.empty())
        return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "KICK :Not enough parameters"));

    if (channels.size() != 1 && channels.size() != users.size())
        return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "KICK :Invalid number of channels and users"));

    std::string reason = client.getNick();

    if (message.params.size() > 2 && !message.params[2].empty())
        reason = message.params[2];

    for (size_t i = 0; i < users.size(); ++i)
    {
        size_t		channelIndex = (channels.size() == 1) ? 0 : i;
        Channel*	channel = server.findChannel(channels[channelIndex]);

        if (!channel)
        {
            sendNumeric(client, IRC::ERR_NOSUCHCHANNEL, channels[channelIndex] + " :No such channel");
            continue;
        }

        if (!channel->hasMember(client))
        {
            sendNumeric(client, IRC::ERR_NOTONCHANNEL, channels[channelIndex] + " :You're not on that channel");
            continue;
        }

        if (!channel->hasOperator(client))
        {
            sendNumeric(client, IRC::ERR_CHANOPRIVSNEEDED, channels[channelIndex] + " :You're not a channel operator");
            continue;
        }

        Client* target = server.findClient(users[i]);

        if (!target)
        {
            sendNumeric(client, IRC::ERR_NOSUCHNICK, users[i] + " :No such nick");
            continue;
        }

        if (!channel->hasMember(*target))
        {
            sendNumeric(client, IRC::ERR_USERNOTINCHANNEL, users[i] + " " + channels[channelIndex] + " :They aren't on that channel");
            continue;
        }

        std::string	prefix = ":" + client.getNick() + "!" + client.getUsername() + "@" + client.getIp();
        std::string	reply = prefix + " KICK " + channel->getTitle() + " " + target->getNick() + " :" + reason + "\r\n";

        const std::vector<Client*>&	members = channel->getMembers();

        for (size_t j = 0; j < members.size(); ++j)
            sendMessage(*members[j], reply);

        channel->removeMember(*target);
        target->removeChannel(*channel);
    }
}

void CommandHandler::handleInvite(Server& server, Client& client, const Message& message)
{
	if (!client.isRegistered())
        return (sendNumeric(client, IRC::ERR_NOTREGISTERED, "INVITE :You have not registered"));

	if (message.params.size() < 2)
		return (sendNumeric(client, IRC::ERR_NEEDMOREPARAMS, "INVITE :Not enough parameters"));

	Client* target = server.findClient(message.params[0]);
	if (!target)
		return (sendNumeric(client, IRC::ERR_NOSUCHNICK, message.params[0] + " :No such nick"));

	Channel* channel = server.findChannel(message.params[1]);
	if (!channel)
		return (sendNumeric(client, IRC::ERR_NOSUCHCHANNEL, message.params[1] + " :No such channel"));

	if (!channel->hasMember(client))
		return (sendNumeric(client, IRC::ERR_NOTONCHANNEL, message.params[1] + " :You're not on that channel"));

	if (channel->isInviteOnly() && !channel->hasOperator(client))
		return (sendNumeric(client, IRC::ERR_CHANOPRIVSNEEDED, message.params[1] + " :You're not a channel operator"));
	
	if (channel->hasMember(*target))
		return (sendNumeric(client, IRC::ERR_USERONCHANNEL, target->getNick() + " " + message.params[1] + " :is already on channel"));
	
	channel->addInvited(*target);
	sendNumeric(client, IRC::RPL_INVITING, message.params[1] + " " + message.params[0]);

	std::string	prefix = ":" + client.getNick() + "!" + client.getUsername() + "@" + client.getIp();
    std::string reply = prefix + " INVITE " + target->getNick() + " " + channel->getTitle() + "\r\n";
	sendMessage(*target, reply);
}