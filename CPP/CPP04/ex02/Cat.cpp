#include "AAnimal.hpp"
#include "Cat.hpp"

#include <iostream>

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat with " << this->type << " type is born !!" << std::endl;

	this->brain = new Brain();

	return ;
}

Cat::Cat(Cat const & other) : AAnimal(other)
{
	std::cout << "Cat with " << this->type << " type is copyborn !!" << std::endl;

	this->brain = new Brain(*other.brain);

	return ;
}

Cat::~Cat()
{
	std::cout << "Cat with " << this->type << " type passed away !!" << std::endl;

	delete this->brain;

	return ;
}

Cat & Cat::operator=(Cat const & other)
{
	if (this != &other)
	{
		delete this->brain;
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}

	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow ~~~" << std::endl;

	return ;
}

void Cat::fillBrainCells( std::string idea )
{
	this->brain->fillIdea(idea);

	return ;
}

void Cat::printBrainCells( void ) const
{
	this->brain->printIdeas();

	return ;
}

Brain * Cat::getBrainAddress( void ) const { return (this->brain); }