#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & other);
		virtual ~Animal();
		
		Animal & operator=(Animal const & other);

		virtual void makeSound( void ) const;
		std::string const & getType( void ) const;
};

#endif