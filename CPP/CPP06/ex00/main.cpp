#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
	// std::cout << BOLD_CRIMSON << av[1] << RESET << std::endl;
	if (ac != 2)
		std::cerr	<< BOLD_CRIMSON << "Error: Wrong number of arguments !!" << RESET
					<< std::endl
					<< "Usage: ./convert <literal>" << std::endl;
	else
		ScalarConverter::convert(av[1]);

	return ( 0 );
}