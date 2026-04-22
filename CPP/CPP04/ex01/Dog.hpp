#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		Dog();
		Dog(Dog const & other);
		~Dog();

		Dog & operator=(Dog const & other);

		void makeSound( void ) const; //override
		void fillBrainCells( std::string idea );
		void printBrainCells( void ) const;
		Brain* getBrainAddress( void ) const;
};

#endif