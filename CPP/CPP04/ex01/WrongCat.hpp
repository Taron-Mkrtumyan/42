#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#include <string>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const & other);
		~WrongCat();

		WrongCat & operator=(WrongCat const & other);

		void makeSound( void ) const;
};

#endif