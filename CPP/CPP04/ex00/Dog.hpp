#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

#include <string>

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const & other);
		~Dog();

		Dog & operator=(Dog const & other);

		void makeSound( void ) const;
};

#endif