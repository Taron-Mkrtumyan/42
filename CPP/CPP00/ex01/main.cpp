#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "ex01.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	line = "";

	std::cout << INFO_MASSAGE << std::endl;
	while (line != "EXIT")
	{
		std::cout << "> ";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			break;
		}
		if (line == "ADD")
		{
			if (phonebook.add_contact() == CTRL_D)
			{
				std::cout << std::endl;
				break;
			}
		}
		else if (line == "SEARCH")
		{
			RETURN_VALUE	ret = phonebook.search_contact();

			if (ret == CTRL_D)
			{
				std::cout << std::endl;
				break;
			}
			if (ret == FALSE)
				std::cout << WRONG_SEARCH_MESSAGE;
		}
	}
	return (0);
}
