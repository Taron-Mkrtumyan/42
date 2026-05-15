#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & other);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & other);
		~ShrubberyCreationForm();

	public:
		void	executeAction() const;
	//	virtual void	beSigned(Bureaucrat const & instance);
};

#endif