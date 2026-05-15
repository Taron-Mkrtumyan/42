#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat brat("Elon Musk", 2);
		std::cout << brat << std::endl;
		
		brat.decrementGrade();
		std::cout << brat << std::endl;

		brat.incrementGrade();
		brat.incrementGrade();
		//brat.incrementGrade();
		std::cout << brat << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException)
	{
		std::cout << "Grade below 150 detected !!" << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException)
	{
		std::cout << "Grade above 1 detected !!" << std::endl;
	}
	return (0);
}