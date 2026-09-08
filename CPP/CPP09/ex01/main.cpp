#include "RPN.hpp"

static void	printErrorMessage	(std::string const & message, std::ostream & stream);
static int	ExceptionError		(std::exception const & e);
static int	ArgumentError		();


int main(int ac, char **av)
{
	if (ac != 2)
		return (ArgumentError());

	try
	{
		RPN rpn;
		rpn.run(av[1]); 
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


static int ArgumentError()
{
	std::cerr << std::endl;

	printErrorMessage(WRONG_ARGUMENTS_MESSAGE,	std::cerr);
	printErrorMessage(USAGE_MESSAGE,			std::cerr);

	std::cerr << std::endl;


	return (EXIT_FAILURE);
}


static int ExceptionError(std::exception const & e)
{
	std::cerr << BOLD_CRIMSON "Error: " << e.what() << RESET << std::endl;

	return (EXIT_FAILURE);
}