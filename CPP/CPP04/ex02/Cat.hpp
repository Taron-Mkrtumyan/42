#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

#include <string>

class Cat : public AAnimal
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