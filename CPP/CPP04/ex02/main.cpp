#include <iostream>

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const AAnimal* meta = new AAnimal(); // Unable to create an instance of an abstract class
	// std::cout << std::endl;

	const AAnimal* j = new Dog();
	std::cout << std::endl;
	
	const AAnimal* i = new Cat();
	std::cout << std::endl;


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!	
	j->makeSound();	
	// meta->makeSound();

	std::cout << std::endl;


	// std::cout << std::endl;
	// delete meta;
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;


	return (0);
}