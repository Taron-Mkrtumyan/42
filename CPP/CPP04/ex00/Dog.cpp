#include "Animal.hpp"
#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog with " << this->type << " type is born !!" << std::endl;

	return ;
}

Dog::Dog(Dog const & other) : Animal(other)
{
	std::cout << "Dog with " << this->type << " type is copyborn !!" << std::endl;

	return ;
}

Dog::~Dog()
{
	std::cout << "Dog with " << this->type << " type passed away !!" << std::endl;

	return ;
}

Dog & Dog::operator=(Dog const & other)
{
	if (this != &other)
	{
		this->type = other.type;
	}

	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Bark !!!" << std::endl;

	return ;
}

