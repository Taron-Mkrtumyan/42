#include "AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal() : type("Unknown")
{
	std::cout << "AAnimal with " << this->type << " type is born !!" << std::endl;

	return ;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal with " << this->type << " type is born !!" << std::endl;

	return ;
}

AAnimal::AAnimal(AAnimal const & other) : type(other.type)
{
	std::cout << "AAnimal with " << this->type << " type is copyborn !!" << std::endl;

	return ;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal with " << this->type << " type passed away !!" << std::endl;

	return ;
}

AAnimal & AAnimal::operator=(AAnimal const & other)
{
	if (this != &other)
		this->type = other.type;

	return (*this);
}

std::string const & AAnimal::getType( void ) const { return (this->type); }

