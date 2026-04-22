#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <string>

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const & other);
		virtual ~AAnimal();
		
		AAnimal & operator=(AAnimal const & other);

		virtual void makeSound( void ) const = 0;
		std::string const & getType( void ) const;
};

#endif