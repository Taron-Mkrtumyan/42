#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	private:
		AForm *	_makeShrubberyCreationForm	(std::string const & target);
		AForm *	_makeRobotomyRequestForm	(std::string const & target);
		AForm *	_makePresidentialPardonForm	(std::string const & target);

	public:
		Intern();
		Intern(Intern const & instance);
		Intern & operator=(Intern const & instance);
		~Intern();

	public:
		class UnknownFormException : public std::exception
		{
			public:
				const char * what() const throw();
		};
	
	public:
		AForm *	makeForm(std::string const & name, std::string const & target);
};


#endif