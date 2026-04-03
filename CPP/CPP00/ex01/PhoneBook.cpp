#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	//std::cout << "PhoneBook cunstructor called !!" << std::endl;
	this->_counter = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "PhoneBook destructer called !!" << std::endl;
	return;
}

bool	PhoneBook::_is_valid_name(const std::string& str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]))
			return (false);
	}
	return (true);
}

bool	PhoneBook::_is_valid_number(const std::string& str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && str[i] == '+')
			continue;
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

RETURN_VALUE	PhoneBook::add_contact(void)
{
	Contact		contact;
	std::string	str;

	str.clear();
	while(!_is_valid_name(str))
	{
		std::cout << BRIGHT_MAGENTA "First name: " RESET;
		if (!getline(std::cin, str))
			return (CTRL_D);
	}
	contact.set_first_name(str);

	str.clear();
	while(!_is_valid_name(str))
	{
		std::cout << BRIGHT_MAGENTA "Last name: " RESET;
		if (!getline(std::cin, str))
			return (CTRL_D);
	}
	contact.set_last_name(str);

	str.clear();
	while (str.empty())
	{
		std::cout << BRIGHT_MAGENTA "Nickname: " RESET;
		if (!getline(std::cin, str))
			return (CTRL_D);
	}
	contact.set_nickname(str);

	str.clear();
	while(!_is_valid_number(str))
	{
		std::cout << BRIGHT_MAGENTA "Phone Number: " RESET;
		if (!getline(std::cin, str))
			return (CTRL_D);
	}
	contact.set_phone_number(str);

	str.clear();
	while (str.empty())
	{
		std::cout << BRIGHT_MAGENTA "Darkest secret: " RESET;
		if (!getline(std::cin, str))
			return (CTRL_D);
	}
	contact.set_darkest_secret(str);

	this->_contact_arr[this->_counter % MAX_CONTACT] = contact;
	this->_counter++;
	return (TRUE);
}

void	PhoneBook::_display_phonebook(void) const
{
	std::string line (44, '-');
	std::cout	<< std::right << line << std::endl
				<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl
				<< line << std::endl;

	for (int i = 0; i < std::min(this->_counter, MAX_CONTACT); i++)
	{
		std::string first_name = this->_contact_arr[i].get_first_name();
		std::string last_name = this->_contact_arr[i].get_last_name();
		std::string nickname = this->_contact_arr[i].get_nickname();

		if (first_name.length() > LENGTH_LIMIT)
		{
			first_name.resize(LENGTH_LIMIT);
			first_name[LENGTH_LIMIT - 1] = '.';
		}
		if (last_name.length() > LENGTH_LIMIT)
		{
			last_name.resize(LENGTH_LIMIT);
			last_name[LENGTH_LIMIT - 1] = '.';
		}
		if (nickname.length() > LENGTH_LIMIT)
		{
			nickname.resize(LENGTH_LIMIT);
			nickname[LENGTH_LIMIT - 1] = '.';
		}

		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << first_name << "|"
				  << std::setw(10) << last_name << "|"
				  << std::setw(10) << nickname << "|"
				  << std::endl;
	}
	std::cout << line << std::endl;
	return ;
}

RETURN_VALUE	PhoneBook::search_contact( void )
{
	std::string	str;

	if (this->_counter == 0)
	{
		std::cout <<  BRED "PhoneBook is empty !!" RESET << std::endl;
		return (TRUE);
	}
	_display_phonebook();
	std::cout << BRIGHT_MAGENTA "Index: " RESET;
	if (!getline(std::cin, str))
		return (CTRL_D);
	if (str.empty() || str.length() != 1 || !isdigit(str[0]) || str[0] >= MAX_CONTACT +'0')
		return (FALSE);
	int index = str[0] - '0';
	if (index >= this->_counter)
		return (FALSE);
	Contact contact = this->_contact_arr[index];

	std::cout << BWHITE "First name: "		RESET << "\t" << contact.get_first_name()		<< std::endl;
	std::cout << BWHITE "Last name: "		RESET << "\t" << contact.get_last_name()		<< std::endl;
	std::cout << BWHITE "Nickname: " 		RESET << "\t" << contact.get_nickname()		<< std::endl;
	std::cout << BWHITE "Phone Number: " 	RESET << "\t" << contact.get_phone_number()	<< std::endl;
	std::cout << BWHITE "Darkest secret: "	RESET << "\t" << contact.get_darkest_secret()	<< std::endl;

	return (TRUE);
}
