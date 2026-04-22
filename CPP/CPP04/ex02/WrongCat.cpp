#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat with " << this->type << " type is born !!" << std::endl;

	return ;
}

WrongCat::WrongCat(WrongCat const & other) : WrongAnimal(other)
{
	std::cout << "WrongCat with " << this->type << " type is copyborn !!" << std::endl;

	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat with " << this->type << " type passed away !!" << std::endl;

	return ;
}

WrongCat & WrongCat::operator=(WrongCat const & other)
{
	if (this != &other)
	{
		this->type = other.type;
	}

	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "Meow ~~~" << std::endl;

	return ;
}

