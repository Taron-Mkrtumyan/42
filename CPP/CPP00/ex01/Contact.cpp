#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	//std::cout << "Contact cunstructor called !!" << std::endl;
	this->_darkest_secret = "";
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	return;
}

Contact::~Contact()
{
	//std::cout << "Contact destructer called !!" << std::endl;
	return;
}

Contact& Contact::operator=(const Contact& other)
{
	if (this != &other)
	{
		this->_darkest_secret = other._darkest_secret;
		this->_first_name = other._first_name;
		this->_last_name = other._last_name;
		this->_nickname = other._nickname;
		this->_phone_number = other._phone_number;
	}
	return (*this);
}

std::string	Contact::get_darkest_secret(void) const { return (this->_darkest_secret); }
std::string	Contact::get_first_name(void) const { return (this->_first_name); }
std::string	Contact::get_last_name(void) const { return (this->_last_name); }
std::string	Contact::get_nickname(void) const { return (this->_nickname); }
std::string	Contact::get_phone_number(void) const { return (this->_phone_number); }

void	Contact::set_darkest_secret(const std::string& str) { this->_darkest_secret = str; }
void	Contact::set_first_name(const std::string& str) { this->_first_name = str; }
void	Contact::set_last_name(const std::string& str) { this->_last_name = str; }
void	Contact::set_nickname(const std::string& str) { this->_nickname = str; }
void	Contact::set_phone_number(const std::string& str) { this->_phone_number = str; }