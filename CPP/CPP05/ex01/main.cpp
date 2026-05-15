#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Form form("Form A", 50, 100);
		std::cout << form << std::endl;
		Bureaucrat brat("Elon Musk", 50);
		std::cout << brat << std::endl;
		
		brat.signForm(form);
		std::cout << form << std::endl;
	}

	catch(Bureaucrat::GradeTooLowException)
	{
		std::cout << "Bureaucrat grade above 150 detected !!" << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException)
	{
		std::cout << "Bureaucrat grade below 1 detected !!" << std::endl;
	}
	catch(Form::GradeTooHighException)
	{
		std::cout << "Form grade below 1 detected !!" << std::endl;
	}
	catch(Form::GradeTooLowException)
	{
		std::cout << "Form grade above 150 detected !!" << std::endl;
	}
	return (0);
}