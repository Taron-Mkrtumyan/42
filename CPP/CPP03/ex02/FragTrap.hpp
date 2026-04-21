#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & other);
		FragTrap & operator=(FragTrap const & other);
		~FragTrap();

		void highFivesGuys(void);
};

std::ostream & operator<<(std::ostream & out, FragTrap const & instance);

#endif