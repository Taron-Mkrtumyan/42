#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{

public:
	Contact(void);
	~Contact(void);

	std::string get_darkest_secret( void ) const;
	std::string get_first_name( void ) const;
	std::string get_last_name( void ) const;
	std::string get_nickname( void ) const;
	std::string get_phone_number( void ) const;

	void set_darkest_secret(const std::string& str);
	void set_first_name(const std::string& str);
	void set_last_name(const std::string& str);
	void set_nickname(const std::string& str);
	void set_phone_number(const std::string& str);

	Contact& operator=(const Contact& other);
private:
	std::string _darkest_secret;
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
};

#endif
