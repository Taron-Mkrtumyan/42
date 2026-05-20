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

		Bureaucrat brat("Elon Musk", 10);
		brat.signForm(*rrf);
		brat.executeForm(*rrf);

		delete rrf;
	}
	catch(Intern::UnknownFormException		const & e) { std::cout << "Gotchya!\t" << e.what() << std::endl; }
	catch(Bureaucrat::GradeTooLowException	const & e) { std::cout << "Gotchya!\t" << e.what() << std::endl; }
	catch(Bureaucrat::GradeTooHighException	const & e) { std::cout << "Gotchya!\t" << e.what() << std::endl; }

	return (0);
}