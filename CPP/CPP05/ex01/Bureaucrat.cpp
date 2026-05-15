#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

Bureaucrat::Bureaucrat() : _name("undefined"), _grade(150) { return ; }

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();

	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) : _name(other._name), _grade(other._grade) { return ; }
Bureaucrat:: ~Bureaucrat() { return ; }


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

std::string const & Bureaucrat::getName() const { return (this->_name); }
int 				Bureaucrat::getGrade() const { return (this->_grade);}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	_grade --;
	return ;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	_grade ++;
	return ;
}

void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(Form::GradeTooLowException)
	{
		std::cout	<< this->_name << " couldn't sign " << form.getName() 
					<< " because their grade was not high enough !!" << std::endl;
	}

	return ;
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & instance)
{
	out << instance.getName() << ", bureaucrat grade " << instance.getGrade() << std::endl;

	return (out);
}

