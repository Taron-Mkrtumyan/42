#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

class Message
{
public:
    std::string					command;
    std::vector<std::string>	params;
};

#endif