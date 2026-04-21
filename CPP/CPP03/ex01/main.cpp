#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
	ClapTrap _1("Clap");
	std::cout << std::endl;

	ScavTrap _2("Scav");

	std::cout << std::endl << _1 << std::endl;
	std::cout << std::endl << _2 << std::endl;

	_1.attack("Him");
	_2.attack("Them");

	std::cout << std::endl << _1 << std::endl;
	std::cout << std::endl << _2 << std::endl;

	_1.beRepaired(1);
	_2.beRepaired(2);
	
	std::cout << std::endl << _1 << std::endl;
	std::cout << std::endl << _2 << std::endl;

	_1.takeDamage(100);
	_2.takeDamage(100);

	std::cout << std::endl << _1 << std::endl;
	std::cout << std::endl << _2 << std::endl;

	_2.guardGate();

	std::cout << std::endl;
	
	return (0);
}
