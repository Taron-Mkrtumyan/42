#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		unsigned int _health;
		unsigned int _energy;
		unsigned int _damage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int health, unsigned int energy, unsigned int damage);
		ClapTrap(ClapTrap const & other);
		ClapTrap & operator=(ClapTrap const & other);
		~ClapTrap();

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string	const & getName() const;
		unsigned int const & getHealth() const;
		unsigned int const & getEnergy() const;
		unsigned int const & getDamage() const;
};

std::ostream & operator<<(std::ostream & out, ClapTrap const & instance);

#endif
