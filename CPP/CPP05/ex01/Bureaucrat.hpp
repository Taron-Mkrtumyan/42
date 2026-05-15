#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		class GradeTooHighException {};
		class GradeTooLowException {};

	public:
		Bureaucrat();
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & other);
		Bureaucrat & operator=(Bureaucrat const & other);
		~Bureaucrat();

	public:
		std::string const & 	getName() const;
		int			 			getGrade() const;

	public:
		void 					incrementGrade();
		void 					decrementGrade();
		void					signForm(Form & form);
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & instance);

#endif