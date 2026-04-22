#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

#include <string>

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & other);
		~Cat();

		Cat & operator=(Cat const & other);

		void makeSound( void ) const; //override
};

#endif