#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
	std::cout << "Brain with empty ideas is born !!" << std::endl;

	return ;
}

Brain::Brain(Brain const & other)
{
	std::cout << "Brain filled with other ideas is copyborn !!" << std::endl;

	*this = other;

	return ;
}

Brain::~Brain()
{
	std::cout << "Brain passed away !!" << std::endl;

	return ;
}

Brain & Brain::operator=(Brain const & other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}

	return (*this);
}

void Brain::fillIdea(std::string idea)
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = idea;

	return ;
}

void Brain::printIdeas(void) const
{
	for (int i = 0; i < 100; ++i)
		std::cout << this->ideas[i] << ' ';
	std::cout << std::endl;

	return ;
}