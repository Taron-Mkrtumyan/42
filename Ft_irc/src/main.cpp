#include "Server.hpp"

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <csignal>

volatile sig_atomic_t g_serverRunning = 1;

static void handleSignal(int)
{
	g_serverRunning = 0;
}

bool isNumber(const char *port)
{
    if (!port || !*port)
        return (false);

    for (int i = 0; port[i]; i++)
    {
        if (!isdigit(static_cast<unsigned char>(port[i])))
            return (false);
    }
    return (true);
}

bool isCorrectPort(const char *str)
{
	if (!isNumber(str))
		return (false);

	int port = std::atoi(str);
	if (port < 1024 || port > 65535)
    	return (false);
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 3 || !isCorrectPort(argv[1]))
	{
		std::cout << "./ircserv <port> <password>" << std::endl;
		return (1);
	}

	std::signal(SIGINT, handleSignal);
	std::signal(SIGQUIT, handleSignal);

    Server server(std::atoi(argv[1]), argv[2]);

    if (!server.init())
        return (1);

    std::cout << "IRC Server started on port " << argv[1] << std::endl;
    server.run();

    return (0);
}