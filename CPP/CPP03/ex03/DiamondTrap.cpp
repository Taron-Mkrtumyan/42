#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Unnamed_clap_name", 100, 50 ,30), ScavTrap("Unnamed"), FragTrap("Unnamed"), _name("Unnamed")
{
	std::cout << "DiamondTrap named \"" << this->_name << "\" is born !!" << std::endl;

	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap named \"" << name << "\" is born !!" << std::endl;

	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap named \"" << this->_name << "\" is copy born !!" << std::endl;

	return ;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap named \"" << this->_name << "\"" << std::endl;
	std::cout << "I inherited from ClapTrap named \"" << ClapTrap::getName() << "\"" << std::endl;

	return ;
}

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);

	return ;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & other)
{
	std::cout << "DiamondTrap copy assignment operator called!" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_health = other._health;
		this->_energy = other._energy;
		this->_damage = other._damage;
	}

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap named \"" << this->_name << "\" is destructead !!" << std::endl;

	return ;
}

std::string	const & DiamondTrap::getName( void ) const { return (this->_name); }

std::ostream & operator<<(std::ostream & out, DiamondTrap const & instance)
{
	out << "Name:\t" << instance.getName() << std::endl;
	out << "Health:\t" << instance.getHealth() << std::endl;
	out << "Energy:\t" << instance.getEnergy() << std::endl;
	out << "Damage:\t" << instance.getDamage() << std::endl;

	return (out);
}