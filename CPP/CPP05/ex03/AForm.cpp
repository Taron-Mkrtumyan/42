#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : 
			_name("undefined"), 
			_is_signed(false), 
			_grade_to_sign(1), 
			_grade_to_execute(150) 
{ 
	return ; 
}

AForm::AForm(std::string const & name, int grade_to_sign, int grade_to_execute) : 
																			_name(name), 
																			_is_signed(false),
																			_grade_to_sign(grade_to_sign),
																			_grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();

	return ;
}

AForm::AForm(AForm const & other) : 
								_name(other._name), 
								_is_signed(false),
								_grade_to_sign(other._grade_to_sign), 
								_grade_to_execute(other._grade_to_execute) 
{ 
	return ; 
}

AForm:: ~AForm() { return ; }


AForm & AForm::operator=(AForm const & other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;

	return (*this);
}

std::string const & AForm::getName() const { return (this->_name); }
bool				AForm::getSignState() const { return(this->_is_signed); }
int 				AForm::getGradeToSign() const { return (this->_grade_to_sign); }
int 				AForm::getGradeToExecute() const { return (this->_grade_to_execute); }

void	AForm::beSigned(Bureaucrat const & instance)
{
	if (this->_is_signed == true)
		throw(AForm::FormAlreadySignedException());
	if (instance.getGrade() > this->_grade_to_sign)
		throw(AForm::GradeTooLowException());

	this->_is_signed = true;
	std::cout << instance.getName() << " signed " << this->getName() << '.' << std::endl;

	return ;
}

void	AForm::executeAction() const //virtual = 0
{
	return ;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->_is_signed == false)
		throw(AForm::FormNotSignedException());
	if (executor.getGrade() > this->_grade_to_execute)
		throw(AForm::GradeTooLowException());

	executeAction();
	
	std::cout << executor.getName() << " executed " << this->_name << std::endl;

	return ;
}

std::ostream & operator<<(std::ostream & out, AForm const & instance)
{
	out << std::endl << "AForm name: "				<< instance.getName()
		<< std::endl << "AForm grade to sign: "	<< instance.getGradeToSign()
		<< std::endl << "AForm grade to execute: "	<< instance.getGradeToExecute()
		<< std::endl << "AForm sign state: "		<< instance.getSignState()
		<< std::endl;

	return (out);
}

