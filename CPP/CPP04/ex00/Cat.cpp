#include "Animal.hpp"
#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat with " << this->type << " type is born !!" << std::endl;

	return ;
}

Cat::Cat(Cat const & other) : Animal(other)
{
	std::cout << "Cat with " << this->type << " type is copyborn !!" << std::endl;

	return ;
}

Cat::~Cat()
{
	std::cout << "Cat with " << this->type << " type passed away !!" << std::endl;

	return ;
}

Cat & Cat::operator=(Cat const & other)
{
	if (this != &other)
	{
		this->type = other.type;
	}

	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow ~~~" << std::endl;

	return ;
}

