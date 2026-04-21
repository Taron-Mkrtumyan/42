#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		std::string _name;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & other);
		ScavTrap & operator=(ScavTrap const & other);
		~ScavTrap();

		void attack(std::string const & target);
		void guardGate();
};

std::ostream & operator<<(std::ostream & out, ScavTrap const & instance);

#endif