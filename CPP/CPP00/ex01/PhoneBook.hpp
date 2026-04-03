#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "ex01.hpp"
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contact_arr[MAX_CONTACT];
	int		_counter;
	bool	_is_valid_name(const std::string& str);
	bool	_is_valid_number(const std::string& str);
	void	_display_phonebook(void) const;

public:
	PhoneBook(void);
	~PhoneBook(void);
	RETURN_VALUE	add_contact( void );
	RETURN_VALUE	search_contact( void );
};

#endif
