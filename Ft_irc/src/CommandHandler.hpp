#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

#include "Message.hpp"
#include "Client.hpp"
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <cctype>


enum ModeParseResult
{
    MODE_PARSE_SUCCESS,
    MODE_PARSE_UNKNOWN,
    MODE_PARSE_MISSING_ARGUMENT,
    MODE_PARSE_INVALID_SYNTAX,
    MODE_PARSE_TOO_MANY_ARGUMENTS
};

enum ModeValidationResult
{
    MODE_VALIDATION_SUCCESS,
    MODE_VALIDATION_KEYSET,
    MODE_VALIDATION_INVALID_ARGUMENT,
    MODE_VALIDATION_NO_SUCH_NICK,
    MODE_VALIDATION_USER_NOT_IN_CHANNEL
};

struct ModeChange
{
    char		mode;
    bool		enabled;
    std::string	argument;
};

class Server;

class CommandHandler
{
public:
    void						handle(Server& server, Client& client, const Message& message);
	void						sendMessage(Client& client, std::string msg);
	void						sendNumeric(Client& client, int code, const std::string& message);

private:
    void						handleNick(Server& server, Client& client, const Message& message);
    void						handleUser(Server& server, Client& client, const Message& message);
	void						handlePass(Server& server, Client& client, const Message& message);
    void						handleJoin(Server& server, Client& client, const Message& message);
    void						handlePrivmsg(Server& server, Client& client, const Message& message);
    void						handleQuit(Server& server, Client& client, const Message& message);
	void						handleMode(Server& server, Client& client, const Message& message);
	void						handleTopic(Server& server, Client& client, const Message& message);
	void						handleKick(Server& server, Client& client, const Message& message);
	void						handleInvite(Server& server, Client& client, const Message& message);

	void						tryRegister(Client& client);
	std::vector<std::string>	split(const std::string& str, char delimiter);
	void						joinChannel(Server& server, Client& client, const std::string& title, const std::string& key);
	void						handleJoinZero(Server& server, Client& client, std::string msg);
	ModeParseResult				parseModes(const Message& message, std::vector<ModeChange>& changes, char& invalidMode);
	ModeValidationResult		validateModes(const Channel& channel, const std::vector<ModeChange>& changes, Server& server, std::string& errorArgument);
	void						applyModes(Channel& channel, const std::vector<ModeChange>& changes, Server& server);
};

#endif