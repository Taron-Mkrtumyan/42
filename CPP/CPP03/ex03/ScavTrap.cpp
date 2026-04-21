#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), _name("Unnamed")
{
	std::cout << "ScavTrap named \"" << this->_name << "\" is born !!" << std::endl;

	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20), _name(name)
{
	std::cout << "ScavTrap named \"" << name << "\" is born !!" << std::endl;

	return ;
}

ScavTrap::ScavTrap(ScavTrap const & other) : ClapTrap(other), _name(other._name)
{
	std::cout << "ScavTrap named \"" << this->_name << "\" is copy born !!" << std::endl;

	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other)
{
	std::cout << "ScavTrap copy assignment operator called!" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_health = other._health;
		this->_energy = other._energy;
		this->_damage = other._damage;
	}
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap named \"" << this->_name << "\" is in Gate kepper mode" << std::endl;

	return ;
}

void	ScavTrap::attack(std::string const & target)
{
	if (_health == 0 || _energy == 0)
		return ;
	
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" <<  std::endl;

	--(this->_energy);

	return ;
}


ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap named \"" << this->_name << "\" is destructead !!" << std::endl;

	return ;
}

std::ostream & operator<<(std::ostream & out, ScavTrap const & instance)
{
	out << "Name:\t" << instance.getName() << std::endl;
	out << "Health:\t" << instance.getHealth() << std::endl;
	out << "Energy:\t" << instance.getEnergy() << std::endl;
	out << "Damage:\t" << instance.getDamage() << std::endl;
	return (out);
}