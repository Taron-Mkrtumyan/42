#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int	const			_grade_to_sign;
		int	const			_grade_to_execute;

	public:
		class GradeTooHighException {};
		class GradeTooLowException {};
		class FormNotSignedException {};
		class FormAlreadySignedException {};

	public:
		AForm();
		AForm(std::string const & name, int grade_to_sign, int grade_to_execute);
		AForm(AForm const & other);
		AForm & operator=(AForm const & other);
		virtual ~AForm();

	public:
		std::string const & getName() const;
		int			 		getGradeToSign() const;
		int			 		getGradeToExecute() const;
		bool				getSignState() const;

	public:
		void			beSigned(Bureaucrat const & instance);
		void			execute(Bureaucrat const & executor) const;
		virtual void	executeAction() const = 0;
};

std::ostream & operator<<(std::ostream & out, AForm const & instance);

#endif