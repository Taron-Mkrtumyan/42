#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : 
			_name("undefined"), 
			_is_signed(false), 
			_grade_to_sign(1), 
			_grade_to_execute(150) 
{ 
	return ; 
}

Form::Form(std::string const & name, int grade_to_sign, int grade_to_execute) : 
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

Form::Form(Form const & other) : 
								_name(other._name), 
								_is_signed(false),
								_grade_to_sign(other._grade_to_sign), 
								_grade_to_execute(other._grade_to_execute) 
{ 
	return ; 
}

Form:: ~Form() { return ; }


Form & Form::operator=(Form const & other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return (*this);
}

std::string const & Form::getName() const { return (this->_name); }
bool				Form::getSignState() const { return(this->_is_signed); }
int 				Form::getGradeToSign() const { return (this->_grade_to_sign); }
int 				Form::getGradeToExecute() const { return (this->_grade_to_execute); }

void	Form::beSigned(Bureaucrat const & instance)
{
	if (instance.getGrade() > Form::getGradeToSign())
		throw(Form::GradeTooLowException());

	this->_is_signed = true;
	std::cout << instance.getName() << " signed " << this->getName() << '.' << std::endl;

	return ;
}

std::ostream & operator<<(std::ostream & out, Form const & instance)
{
	out << "\nForm name: " << instance.getName()
		<< "\nForm grade to sign: " << instance.getGradeToSign()
		<< "\nForm grade to execute: " << instance.getGradeToExecute()
		<< "\nForm sign state: " << instance.getSignState()
		<< std::endl;

	return (out);
}

