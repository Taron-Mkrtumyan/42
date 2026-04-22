#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl << "=========Normal===========\n" << std::endl;

	const Animal* meta = new Animal();
	std::cout << std::endl;

	const Animal* j = new Dog();
	std::cout << std::endl;
	
	const Animal* i = new Cat();
	std::cout << std::endl;


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!	
	j->makeSound();	
	meta->makeSound();

	std::cout << std::endl;


	std::cout << std::endl;
	delete meta;
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;

	std::cout << std::endl << "=========Wrong===========\n" << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	std::cout << std::endl;

	const WrongAnimal* i2 = new WrongCat();
	std::cout << std::endl;

	std::cout << i2->getType() << " " << std::endl;
	std::cout << std::endl;


	i2->makeSound(); //will not output the cat sound!
	meta2->makeSound();

	std::cout << std::endl;
	delete meta2;
	std::cout << std::endl;
	delete i2;
	std::cout << std::endl;

	return (0);
}