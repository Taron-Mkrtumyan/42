#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie( std::string const & name );
		~Zombie();
		
		void announce( void ) const;
};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

#endif
