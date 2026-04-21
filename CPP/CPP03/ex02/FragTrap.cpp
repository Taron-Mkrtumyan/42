#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Unnamed", 100, 100, 30)
{
	std::cout << "FragTrap named \"" << this->_name << "\" is born !!" << std::endl;

	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap named \"" << name << "\" is born !!" << std::endl;

	return ;
}

FragTrap::FragTrap(FragTrap const & other) : ClapTrap(other)
{
	std::cout << "FragTrap named \"" << this->_name << "\" is copy born !!" << std::endl;

	return ;
}

FragTrap & FragTrap::operator=(FragTrap const & other)
{
	std::cout << "FragTrap copy assignment operator called!" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_health = other._health;
		this->_energy = other._energy;
		this->_damage = other._damage;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap named \"" << this->_name << "\" asks anyone to give a high five 🙌, please" << std::endl;

	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap named \"" << this->_name << "\" is destructead !!" << std::endl;

	return ;
}

std::ostream & operator<<(std::ostream & out, FragTrap const & instance)
{
	out << "Name:\t" << instance.getName() << std::endl;
	out << "Health:\t" << instance.getHealth() << std::endl;
	out << "Energy:\t" << instance.getEnergy() << std::endl;
	out << "Damage:\t" << instance.getDamage() << std::endl;
	return (out);
}