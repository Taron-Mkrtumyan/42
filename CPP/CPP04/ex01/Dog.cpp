#include "Animal.hpp"
#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog with " << this->type << " type is born !!" << std::endl;

	this->brain = new Brain();

	return ;
}

Dog::Dog(Dog const & other) : Animal(other)
{
	std::cout << "Dog with " << this->type << " type is copyborn !!" << std::endl;

	this->brain = new Brain(*other.brain);

	return ;
}

Dog::~Dog()
{
	std::cout << "Dog with " << this->type << " type passed away !!" << std::endl;

	delete this->brain;

	return ;
}

Dog & Dog::operator=(Dog const & other)
{
	if (this != &other)
	{
		delete this->brain;
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}

	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Bark !!!" << std::endl;

	return ;
}

void Dog::fillBrainCells( std::string idea )
{
	this->brain->fillIdea(idea);

	return ;
}

void Dog::printBrainCells( void ) const
{
	this->brain->printIdeas();

	return ;
}

Brain * Dog::getBrainAddress( void ) const { return (this->brain); }
