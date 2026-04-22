#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Unknown")
{
	std::cout << "Animal with " << this->type << " type is born !!" << std::endl;

	return ;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal with " << this->type << " type is born !!" << std::endl;

	return ;
}

Animal::Animal(Animal const & other) : type(other.type)
{
	std::cout << "Animal with " << this->type << " type is copyborn !!" << std::endl;

	return ;
}

Animal::~Animal()
{
	std::cout << "Animal with " << this->type << " type passed away !!" << std::endl;

	return ;
}

Animal & Animal::operator=(Animal const & other)
{
	if (this != &other)
	{
		this->type = other.type;
	}

	return (*this);
}

void Animal::makeSound( void ) const
{
	std::cout << "Animal with " << this->type << " type is trying to make some noise !" << std::endl;

	return ;
}

std::string const & Animal::getType( void ) const { return (this->type); }

