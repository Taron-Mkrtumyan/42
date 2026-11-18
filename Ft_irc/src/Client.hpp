#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>

class Channel;

class Client
{
public:
    Client(int fd, std::string ip);

    int								getFd() const;
    const std::string&				getBuffer() const;
    bool							isDisconnected() const;

    void							addData(const char *data, int bytes);
    void							disconnect();
    bool							getNextMessage(std::string& message);
    void							queueMessage(const std::string& message);
    const std::string&				getSendBuffer() const;
    void							removeSentData(size_t bytes);
    void							setPassword();
    bool							hasPassword();
    bool							isRegistered();
    void							registerClient();
    void							setNick(std::string nick);
    void							setUsername(std::string username);
    void							setRealname(std::string realname);
    std::string						getNick() const;
    std::string						getUsername() const;
    std::string						getRealname() const;
    void							addChannel(Channel& channel);
    bool							inChannel(const Channel& channel) const;
	const std::vector<Channel*>&	getChannels() const;
	void 							removeChannel(Channel& channel);
	std::string						getIp();

private:
    int						_fd;
	std::string				_ip;
    std::string				_buffer;
    bool					_disconnected;
    std::string				_nick;
    std::string				_username;
    std::string				_realname;
    bool					_hasPassword;
    bool					_registered;
    std::string				_sendBuffer;
    std::vector<Channel*>	_channels;
};

#endif