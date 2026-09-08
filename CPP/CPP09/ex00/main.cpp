#include "BitcoinExchange.hpp"

void printErrorMessage(std::string const & message, std::ostream & stream)
{
	stream << message << std::endl;
	usleep(500000);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << std::endl;

		printErrorMessage(WRONG_ARGUMENTS_MESSAGE,	std::cerr);
		printErrorMessage(HELP_MESSAGE,				std::cerr);

		std::cerr << std::endl;
		return (1);
	}
	if  (std::string(av[1]) == "help")
	{
		std::cout << std::endl;

		printErrorMessage(USAGE_MESSAGE,		std::cout);
		printErrorMessage(CSV_MESSAGE,			std::cout);
		printErrorMessage(VALID_DATE_MESSAGE,	std::cout);
		printErrorMessage(VALID_VALUE_MESSAGE,	std::cout);

		std::cout << std::endl;
		return (0);
	}
	try
	{
		BitcoinExchange btc;
		btc.processInput(av[1]);
	}
	catch (std::exception const & e)
	{
		// std::cerr << BOLD_CRIMSON "Error: " << e.what() << RESET << std::endl;
		return (1);
	}


	return (0);
}