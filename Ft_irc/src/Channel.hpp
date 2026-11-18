#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <vector>
#include <string>

class Client;

class Channel
{
public:
    Channel(Client& owner, std::string title);

    void        				addMember(Client& client);
    void        				removeMember(Client& client);
    void        				addOperator(Client& client);
    void        				setPassword(std::string password);
	void						addInvited(Client& client);

    std::string 				getTitle() const;
    std::string 				getTopic() const;
    std::string 				getPassword() const;

	void						setTopic(std::string topic);

    bool        				isInviteOnly() const;
    bool        				isTopicRestricted() const;
    bool        				hasPassword() const;
    bool        				hasUserLimit() const;
    bool        				hasMember(const Client& client) const;
	bool        				hasOperator(const Client& client) const;
	bool						hasInvited(const Client& client) const;

    size_t      				getUserLimit() const;
    size_t      				getMembersCount() const;
	const std::vector<Client*>&	getMembers() const;
	const Client*				getOwner() const;

	void						setInviteOnly(bool enabled);
	void						setTopicRestricted(bool enabled);
	void						removePassword();
	void						setUserLimit(size_t limit);
	void						removeUserLimit();
	void						removeOperator(Client& client);

private:
    Client*                 _owner;
    std::string             _title;
    std::string            	_topic;
    std::string				_password;
    size_t					_userLimit;
    bool                    _inviteOnly;
    bool                    _topicRestricted;
    std::vector<Client*>    _members;
    std::vector<Client*>    _operators;
	std::vector<Client*>	_invitedClients;
};

#endif