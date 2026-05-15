#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");

		Bureaucrat brat("Elon Musk", 1);
		brat.signForm(*rrf);
		brat.executeForm(*rrf);

		delete rrf;
	}

	catch(Intern::UnknownFormException const & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException)
	{
		std::cout << "Bureaucrat grade below 150 detected !!" << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException)
	{
		std::cout << "Invalid Bureaucrat grade !!" << std::endl;
	}

	return (0);
}