#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& type) : _type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

const std::string& Weapon::getType( void ) const
{
    return (this->_type);
}

void Weapon::setType(const std::string& type)
{
    this->_type = type;
	return ;
}
