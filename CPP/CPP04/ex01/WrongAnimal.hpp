#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & other);
		virtual ~WrongAnimal();

		WrongAnimal & operator=(WrongAnimal const & other);

		void makeSound( void ) const;
		std::string const & getType( void ) const;
};

#endif