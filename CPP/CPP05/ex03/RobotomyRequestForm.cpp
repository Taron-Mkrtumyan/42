#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other) : AForm(other), _target(other._target)
{
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

// void RobotomyRequestForm::beSigned(Bureaucrat const & brat)
// {
// 	try
// 	{
// 		AForm::beSigned(brat);
// 	}
// 	catch (AForm::GradeTooLowException)
// 	{
// 		std::cout << "\033[31m" << " Robotomy failed..." << "\033[0m" << std::endl;
// 		std::cout	<< brat.getName() << " couldn't sign " << this->getName() << " because " << "their grade was not high enough !!" << std::endl;
// 	}
				
// 	return ;
// }

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "\033[32m" << "Bzzzzzz... " << this->_target << " has been robotomized successfully. (50% of the time)" << "\033[0m" << std::endl;

	return ;
}

// void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
// {
// 	if (this->getSignState() == false)
// 	{
// 		std::cout << "The form is not signed !!" << std::endl;
// 		return ;
// 	}

// 	if (executor.getGrade() > this->getGradeToExecute())
// 		throw(AForm::GradeTooLowException());

// 	return ;
// }