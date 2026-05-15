#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

const char * Intern::UnknownFormException::what() const throw() { return ("Unknown form type."); }

Intern::Intern()									{}
Intern::Intern(Intern const & instance)				{ (void)instance; }
Intern & Intern::operator=(Intern const & instance)	{ (void)instance; return *this; }
Intern::~Intern() 									{}

AForm * Intern::_makeShrubberyCreationForm	(std::string const & target) { return (new ShrubberyCreationForm	(target)); }
AForm *	Intern::_makeRobotomyRequestForm	(std::string const & target) { return (new RobotomyRequestForm		(target)); }
AForm *	Intern::_makePresidentialPardonForm	(std::string const & target) { return (new PresidentialPardonForm	(target)); }


AForm *	Intern::makeForm(std::string const & name, std::string const & target)
{
	struct FormMaker
	{
		std::string	name;
		AForm * 	(Intern::*maker)(std::string const & target);
	};

	FormMaker formMakers[] = 
	{
		{"shrubbery creation",	&Intern::_makeShrubberyCreationForm},
		{"robotomy request", 	&Intern::_makeRobotomyRequestForm},
		{"presidential pardon",	&Intern::_makePresidentialPardonForm}
	};

	for (size_t i = 0; i < (sizeof(formMakers) / sizeof(FormMaker)); ++i)
	{
		if (formMakers[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*formMakers[i].maker)(target));
		}
	}
	throw Intern::UnknownFormException();
}