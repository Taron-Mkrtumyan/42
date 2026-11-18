#include "MessageParser.hpp"

bool MessageParser::parse(const std::string& rawMessage, Message& message)
{
    size_t	pos = 0;

    while (pos < rawMessage.size() && rawMessage[pos] == ' ')
        pos++;

    size_t	commandEnd = rawMessage.find(' ', pos);
    if (commandEnd == std::string::npos)
    {
        message.command = rawMessage.substr(pos);
        return (!message.command.empty());
    }

    message.command = rawMessage.substr(pos, commandEnd - pos);
    pos = commandEnd + 1;

    while (pos < rawMessage.size())
    {
        while (pos < rawMessage.size() && rawMessage[pos] == ' ')
            pos++;

        if (pos >= rawMessage.size())
            break;

        if (rawMessage[pos] == ':')
        {
            message.params.push_back(rawMessage.substr(pos + 1));
            break;
        }

        size_t paramEnd = rawMessage.find(' ', pos);

        if (paramEnd == std::string::npos)
        {
            message.params.push_back(rawMessage.substr(pos));
            break;
        }

        message.params.push_back(rawMessage.substr(pos, paramEnd - pos));
        pos = paramEnd + 1;
    }

    return (!message.command.empty());
}