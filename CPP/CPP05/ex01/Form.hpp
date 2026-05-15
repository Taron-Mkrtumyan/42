#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int	const			_grade_to_sign;
		int	const			_grade_to_execute;

	public:
		class GradeTooHighException {};
		class GradeTooLowException {};

		Form();
		Form(std::string const & name, int grade_to_sign, int grade_to_execute);
		Form(Form const & other);
		Form & operator=(Form const & other);
		~Form();

		std::string const & getName() const;
		int			 		getGradeToSign() const;
		int			 		getGradeToExecute() const;
		bool				getSignState() const;

		void				beSigned(Bureaucrat const & instance);
};

std::ostream & operator<<(std::ostream & out, Form const & instance);

#endif