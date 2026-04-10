#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed")
{
	std::cout << "Zombie \"" << this->_name << "\" is born!" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Zombie \"" << name << "\" is born!" << std::endl;
}


Zombie::~Zombie()
{
    std::cout << "Zombie \"" << this->_name << "\" is dead!" << std::endl;
}


void Zombie::announce( void ) const
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


