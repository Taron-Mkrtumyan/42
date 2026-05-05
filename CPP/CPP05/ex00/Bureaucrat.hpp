#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		class GradeTooHighException {}; //: public std::exception
			//{
			// public:
			// 	const char* what() const noexcept override;
			//};

		class GradeTooLowException {}; //: public std::exception
			//{
			// public:
			// 	const char* what() const noexcept override;
			//};

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
};

std::ostream & operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif