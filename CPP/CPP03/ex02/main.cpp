#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
	// ClapTrap _1("Clap");
	// std::cout << std::endl;

	// ScavTrap _2("Scav");
	// std::cout << std::endl;

	FragTrap _3("Frag");

	// std::cout << std::endl << _1 << std::endl;
	// std::cout << std::endl << _2 << std::endl;
	std::cout << std::endl << _3 << std::endl;

	// _1.attack("Him");
	// _2.attack("Her");
	_3.attack("Them");

	// std::cout << std::endl << _1 << std::endl;
	// std::cout << std::endl << _2 << std::endl;
	std::cout << std::endl << _3 << std::endl;

	// _1.beRepaired(1);
	// _2.beRepaired(2);
	_3.beRepaired(3);
	
	// std::cout << std::endl << _1 << std::endl;
	// std::cout << std::endl << _2 << std::endl;
	std::cout << std::endl << _3 << std::endl;

	// _1.takeDamage(100);
	// _2.takeDamage(100);
	_3.takeDamage(100);

	// std::cout << std::endl << _1 << std::endl;
	// std::cout << std::endl << _2 << std::endl;
	std::cout << std::endl << _3 << std::endl;

	// _2.guardGate();
	// std::cout << std::endl;
	
	_3.highFivesGuys();
	std::cout << std::endl;
	
	return (0);
}
