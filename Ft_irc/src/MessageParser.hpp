#ifndef MESSAGEPARSER_HPP
#define MESSAGEPARSER_HPP

#include <string>
#include "Message.hpp"

class MessageParser
{
public:
    bool	parse(const std::string& rawMessage, Message& message);
};

#endif