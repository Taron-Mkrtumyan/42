#include "PmergeMe.hpp"

static void	printErrorMessage	(std::string 	const & message, std::ostream & stream);
static int	ArgumentError		(std::string	const & message);
static int	ExceptionError		(std::exception const & e);
static bool	are_valid_arguments	(int ac, char **av);

int main(int ac, char **av)
{
	if (ac < 2)
		return (ArgumentError(NO_ARGUMENTS_MESSAGE));

	if (!are_valid_arguments(ac, av))
		return (ArgumentError(WRONG_ARGUMENTS_MESSAGE));

	try
	{
		PmergeMe pmerge(ac, av);
		pmerge.run();
	}
	catch (std::exception const & e)
	{
		return (ExceptionError(e));
	}

	return (0);
}



static void printErrorMessage(std::string const & message, std::ostream & stream)
{
	stream << message << std::endl;
	usleep(500000);

	return ;
}


static int ArgumentError(std::string const & message)
{
	std::cerr << std::endl;

	printErrorMessage(message,			std::cerr);
	printErrorMessage(USAGE_MESSAGE,	std::cerr);

	std::cerr << std::endl;


	return (EXIT_FAILURE);
}


static int ExceptionError(std::exception const & e)
{
	std::cerr << BOLD_CRIMSON "Error: " << e.what() << RESET << std::endl;

	return (EXIT_FAILURE);
}


static bool	are_valid_arguments	(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		for (int j = 0; av[i][j]; ++j)
		{
			if (!std::isdigit(av[i][j]) || av[i][j] == '0')
				return (false);
		}
	}
	return (true);
}