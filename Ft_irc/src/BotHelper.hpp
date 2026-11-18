#ifndef BOTHELPER_HPP
#define BOTHELPER_HPP

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

class BotHelper
{
public:
	BotHelper();
	~BotHelper();

	bool				init(int port, const std::string& password);
	int					getFd() const;
	bool				hasDataToSend() const;
	void				handleEvent(short events);


private:
	int			_fd;
	std::string	_sendBuffer;
	std::string	_recvBuffer;

	void		handleMessage(const std::string& message);
	bool		setNonBlocking(int fd);
	void		handleRead();
	void		handleWrite();
};

#endif