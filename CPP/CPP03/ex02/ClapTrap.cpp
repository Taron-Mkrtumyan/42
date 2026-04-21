#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Unnamed"), _health(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap named \"" << this->_name << "\" is born !!" << std::endl;

	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap named \"" << name << "\" is born !!" << std::endl;

	return ;
}

ClapTrap::ClapTrap(std::string name, unsigned int health, unsigned int energy, unsigned int damage) : _name(name), _health(health), _energy(energy), _damage(damage)
{
	std::cout << "ClapTrap named \"" << name << "\" is born !!" << std::endl;

	return ;
}

ClapTrap::ClapTrap(ClapTrap const & other) : _name(other._name), _health(other._health), _energy(other._energy), _damage(other._damage)
{
	std::cout << "ClapTrap named \"" << this->_name << "\" is copy born !!" << std::endl;

	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other)
{
	std::cout << "ClapTrap copy assignment operator called!" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_health = other._health;
		this->_energy = other._energy;
		this->_damage = other._damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap named \"" << this->_name << "\" is destructead !!" << std::endl;

	return ;
}

void	ClapTrap::attack(std::string const & target)
{
	if (_health == 0 || _energy == 0)
		return ;
	
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" <<  std::endl;

	--(this->_energy);

	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" <<  std::endl;

	this->_health = amount < _health ? _health - amount : 0;

	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_health == 0 || _energy == 0)
		return ;

	std::cout << "ClapTrap " << this->_name << " repaired " << amount << " points of health!" <<  std::endl;

	--(this->_energy);
	this->_health += amount;

	return ;
}

std::string	const & ClapTrap::getName( void ) const { return (this->_name); }

unsigned int	const & ClapTrap::getHealth( void ) const { return (this->_health); }
unsigned int	const & ClapTrap::getDamage( void ) const {	return (this->_damage); }
unsigned int	const & ClapTrap::getEnergy( void ) const {	return (this->_energy); }

std::ostream & operator<<(std::ostream & out, ClapTrap const & instance)
{
	out << "Name:\t" << instance.getName() << std::endl;
	out << "Health:\t" << instance.getHealth() << std::endl;
	out << "Energy:\t" << instance.getEnergy() << std::endl;
	out << "Damage:\t" << instance.getDamage() << std::endl;
	return (out);
}