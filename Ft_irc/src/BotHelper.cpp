#include "BotHelper.hpp"


BotHelper::BotHelper() : _fd(-1) {}

BotHelper::~BotHelper()
{
    if (_fd != -1)
	{
        close(_fd);
		_fd = -1;
	}
}

bool BotHelper::setNonBlocking(int fd)
{
    if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1)
        return (false);

    return (true);
}

int BotHelper::getFd() const
{
    return (_fd);
}

bool BotHelper::hasDataToSend() const
{
    return (!_sendBuffer.empty());
}

bool BotHelper::init(int port, const std::string& password)
{
    _fd = socket(AF_INET, SOCK_STREAM, 0);

    if (_fd == -1)
    {
        perror("bot socket");
        return (false);
    }

	struct sockaddr_in	address;
    std::memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (connect(_fd, (struct sockaddr*)&address, sizeof(address)) == -1)
    {
        perror("bot connect");
        close(_fd);
		_fd = -1;
        return (false);
    }

    if (!setNonBlocking(_fd))
    {
        perror("bot fcntl");
        close(_fd);
		_fd = -1;
        return (false);
    }



    _sendBuffer = "PASS " + password + "\r\n" + "NICK HelperBot\r\n" + "USER helper 0 * :42 Helper Bot\r\n";
	std::srand(std::time(NULL));
    return (true);
}

void BotHelper::handleMessage(const std::string& message)
{
	size_t prefixEnd = message.find(' ');
	if (prefixEnd == std::string::npos)
		return;

	std::string	prefix = message.substr(0, prefixEnd);
	size_t		commandStart = message.find(' ', prefixEnd + 1);

	if (commandStart == std::string::npos)
		return;

	std::string	command = message.substr(prefixEnd + 1, commandStart - prefixEnd - 1);
	size_t		targetStart = commandStart + 1;
	size_t		targetEnd = message.find(' ', targetStart);

	if (targetEnd == std::string::npos)
		return;

	std::string target = message.substr(targetStart, targetEnd - targetStart);

	if (command == "INVITE")
	{
		size_t		channelStart = targetEnd + 1;
		std::string	channel = message.substr(channelStart);

		if (!channel.empty() && channel[0] == '#')
			_sendBuffer += "JOIN " + channel + "\r\n";

		return;
	}

	if (command != "PRIVMSG")
		return;

	size_t textStart = message.find(':', targetEnd);
	if (textStart == std::string::npos)
		return;

	std::string	text = message.substr(textStart + 1);
	size_t		nickEnd = prefix.find('!');
	std::string	sender = prefix.substr(1, nickEnd - 1);
	std::string	replyTarget = target[0] == '#' ? target : sender;


	if (text == "!help")
		_sendBuffer += "PRIVMSG " + replyTarget + " :Available commands: !help, !ping, !rand, !date, !coin, !8ball\r\n";
	else if (text == "!ping")
		_sendBuffer += "PRIVMSG " + replyTarget + " :" + "pong!\r\n";
	else if (text == "!rand")
	{
		std::ostringstream oss;
		oss << std::rand() % 101;
		_sendBuffer += "PRIVMSG " + replyTarget + " :" + oss.str() + "\r\n";
	}
	else if (text == "!date")
	{
		std::time_t	now = std::time(NULL);
		std::string	date = std::ctime(&now);
		date.erase(date.find('\n'));
		_sendBuffer += "PRIVMSG " + replyTarget + " :" + date + "\r\n";
	}
	else if (text == "!coin")
	{
		_sendBuffer += "PRIVMSG " + replyTarget;
		if (std::rand() % 2 == 0)
			_sendBuffer += " :Heads!\r\n";
		else
			_sendBuffer += " :Tails!\r\n";
	}
	else if (text == "!8ball")
	{
		const char *answers[] = {"Yes!", "No!", "Definitely!", "I don't think so.", "Maybe.", \
			"Ask again later.", "Without a doubt!", "Very unlikely.", "The future is unclear."
		};

		int index = std::rand() % 9;
		_sendBuffer += "PRIVMSG " + replyTarget + " :" + answers[index] + "\r\n";
	}
}

void BotHelper::handleEvent(short events)
{
    if (events & (POLLERR | POLLNVAL))
    {
        close(_fd);
		_fd = -1;
        return;
    }

    if (events & POLLIN)
        handleRead();

    if (_fd == -1)
        return;

    if (events & POLLOUT)
        handleWrite();

    if (_fd != -1 && (events & POLLHUP))
	{
        close(_fd);
		_fd = -1;
	}
}

void BotHelper::handleRead()
{
    char buffer[1024];

    while (true)
    {
        ssize_t bytes = recv(_fd, buffer, sizeof(buffer), 0);

        if (bytes > 0)
        {
            _recvBuffer.append(buffer, bytes);

            size_t pos;

            while ((pos = _recvBuffer.find("\r\n")) != std::string::npos)
            {
                std::string message = _recvBuffer.substr(0, pos);
                _recvBuffer.erase(0, pos + 2);
                handleMessage(message);
            }

            continue;
        }

        if (bytes == 0)
        {
            close(_fd);
			_fd = -1;
            return;
        }

        return;
    }
}

void BotHelper::handleWrite()
{
    while (!_sendBuffer.empty())
    {
        ssize_t sent = send(_fd, _sendBuffer.c_str(), _sendBuffer.size(), MSG_NOSIGNAL);

        if (sent > 0)
        {
            _sendBuffer.erase(0, sent);
            continue;
        }

        if (sent == 0)
            return;

        return;
    }
}