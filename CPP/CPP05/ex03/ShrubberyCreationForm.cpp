#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other) : AForm(other), _target(other._target)
{
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile ((this->_target + "_shrubbery").c_str());

    if (!outfile.is_open()) 
	{
        std::cerr << "Error: Could not create the <target>_shrubbery file." << std::endl;
		return ;
	}
	outfile << "                      _\n                    .(o)`---.--...__.-.__\n                  .\'.\' \'-.-..--._.--._.(o)`---...-.____\n                .\'.\' | |              | |\'--._..--\'-.(o)---...._____\n              .\'.\' .\'| |              |.| | | |  |`---.`--..--._.-.(o)\n            .\'.\' .\' ||.|              | | | | |  ||          || | |-|\n          .\'.\' .\'   || |              | | . | |  ||          || | | |\n        .\'.\'|.\'     || |              | | | | |  ||          || | | |\n       \'.\'_|||      || |              | | | | |  ||          || | | |\n           |||      || | _ _ _ _ _ _  | | | / |  ||          || | | |\n           |||      .| || | | | | | | | |  .  \'  \'-----....._|\' | | |\n           |||    .\' | || | | | | | | |.|\'\'  ----....   ____    \' | |\n           |||  .\'   |>][<| | | | | | | |---  ..    --  ...   --  | |\n           |||.\'    .|.|| | | | | | | | |-..__    _          __ ..| |\n           ||    .\'  | || | | | | | | | |          \'\'\'-----. _ -- | |\n           ||.\'      | || | | | | | | ||| ..  -  -...          .. | |\n           ||     .\' | || | | | | | | | |--..____  ... \'\'\'\'\'\'\'\'-  | |\n           ||  .\'    |>][<| | | | | | | |              --  __ ....| |\n           ||\'    .\' | || | | | | | | | |---  .  .....__  ..      | |\n           || .\' \' .\'| ||_|_|_|_|_|_| | |. ___            .-. \'-\' | |\n           ||   .\'   | |_____________/(o)__  ....  \'\'\'\'  /(o) ... | |\n           ||.\'   .\' (o)=====]======[ //(o)=============/ //==(o)=\'=|\n           ||  .\'  .\'        |      |//      |   |     / //   // /.\'\n           ||(o)\\'     \\     |      |/       /  /     / //   //`/\n     _ LGB || \\ \\     |    =|======|=       | /     /`//   // /\n      `-._.||==\\.\\=====\\    |      |   .\'   | |====/ //===// /\n          `-.   \\ \\    |`-. |      |      | / /   / //   //`/\n-._   `-.    `-. \\ \\   |   =|======|=     || |   / //   //./       _.--\n   `-..         `.\\`\\  \\    |      |     . \'./  /`//   .\\ /  .. --\'\n       `..   `-.  `\\ \\ |`.  |      |  .\' \'  |  / //   //\\-`\'\n          `-.       \\`\\|   =|======|=       \\ / // .-\'   \\  .-`   .`\n             `.  `.  \\/. -\' |      |         / //-\'    .` \\       _.-\'\n              `.      // \\   |      |  .\'  \' /`// `         \\ _..-\'\n                \\    //.\\/. =|======|=      / //       `   _.``\n                 `. //  // \\ |      |      / //  .-`   _.\'\n                   \'/  // \\  |      |  .\' / //      _.\'\n                    `.//    =|======|=   / //   .-\'\n                     \'/  `.  |      |   /.//  .\'\n                      `. .   |      |  /-// .\'\n                        `.  =|======|=/ // /\n                          \\  |      |/ //  |\n                          |  |      |`//  /\n                          \\ =|======|=/ .\'\n                           | |    / |/  .|\n                           \\ |   / /|  .\'\\\n                           |=|======|= | |\n                           | |      |  | |\n                           |           | |\n------------------------------------------------" << std::endl;
	outfile.close();

	std::cout <<  "\033[32m" << "Shrubbery " << this->getName() << " has been created in \"" << this->_target << "_shrubbery\" file." << "\033[0m" << std::endl;
	
	return ;
}

// void	ShrubberyCreationForm::beSigned(Bureaucrat const & instance)
// {
// 	try
// 	{
// 		AForm::beSigned(instance);
// 	}
// 	catch (AForm::GradeTooLowException)
// 	{
// 		std::cout << "\033[31m" << " Shrubbery failed..." << "\033[0m" << std::endl;
// 		std::cout	<< instance.getName() << " couldn't sign " << this->getName() 
// 					<< " because " << "their grade was not high enough !!" << std::endl;
// 		return ;
// 	}

// 	return ;
// }
