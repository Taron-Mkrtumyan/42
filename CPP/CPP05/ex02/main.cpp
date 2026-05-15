#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	try
	{
		ShrubberyCreationForm	form1("Target 1");
		RobotomyRequestForm		form2("Target 2");
		PresidentialPardonForm	form3("Target 3");
		
		std::cout << form1 << form2 << form3 << std::endl; 
		
		Bureaucrat brat("Elon Musk", 5);

		brat.signForm(form1);
		brat.signForm(form2);
		brat.signForm(form3);
		
		std::cout << form1 << form2 << form3 << std::endl; 
		
		brat.executeForm(form1);
		brat.executeForm(form2);
		brat.executeForm(form3);
		
		std::cout << std::endl;
		 
		brat.decrementGrade();
		brat.signForm(form3);
		brat.executeForm(form3);
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