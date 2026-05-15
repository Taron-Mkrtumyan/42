#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other) : AForm(other), _target(other._target)
{
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << "\033[32m" << "Zaphod Beeblebrox granted pardon for " << this->_target << "." << "\033[0m" << std::endl;

	return ;
}

// void PresidentialPardonForm::beSigned(Bureaucrat const & brat)
// {
// 	try
// 	{
// 		AForm::beSigned(brat);
// 	}
// 	catch (AForm::GradeTooLowException)
// 	{
// 		std::cout << "\033[31m" << " Presidential Pardon failed..." << "\033[0m" << std::endl;
// 		std::cout	<< brat.getName() << " couldn't sign " << this->getName() 
// 					<< " because " << "their grade was not high enough !!" << std::endl;
// 	}

// 	return ;
// }

// void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
// {
// 	if (executor.getGrade() > this->getGradeToExecute())
// 		throw(AForm::GradeTooLowException());

// 	std::cout << "\033[32m" << "Zaphod Beeblebrox granted pardon for " << this->_target << "." << "\033[0m" << std::endl;

// 	return ;
// }