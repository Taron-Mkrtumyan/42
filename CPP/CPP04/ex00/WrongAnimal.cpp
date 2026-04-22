#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : type("Unknown")
{
	std::cout << "WrongAnimal with " << this->type << " type is born !!" << std::endl;

	return ;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal with " << this->type << " type is born !!" << std::endl;

	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & other) : type(other.type)
{
	std::cout << "WrongAnimal with " << this->type << " type is copyborn !!" << std::endl;

	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal with " << this->type << " type passed away !!" << std::endl;

	return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & other)
{
	if (this != &other)
	{
		this->type = other.type;
	}

	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal with " << this->type << " type is trying to make some noise !" << std::endl;

	return ;
}

std::string const & WrongAnimal::getType( void ) const { return (this->type); }

