#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & other);
		DiamondTrap & operator=(DiamondTrap const & other);
		~DiamondTrap();

		void whoAmI();
		void attack(std::string const & target);
		std::string	const & getName( void ) const;
};

std::ostream & operator<<(std::ostream & out, DiamondTrap const & instance);

#endif