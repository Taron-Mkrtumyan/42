#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(Cat const & other);
		~Cat();

		Cat & operator=(Cat const & other);

		void makeSound( void ) const; //override
		void fillBrainCells( std::string idea );
		void printBrainCells( void ) const;
		Brain* getBrainAddress( void ) const;
};

#endif