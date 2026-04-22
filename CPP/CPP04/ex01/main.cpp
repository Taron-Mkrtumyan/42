#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main()
{
	const Animal* j = new Dog();
	std::cout << std::endl;
	
	const Animal* i = new Cat();
	std::cout << std::endl;

	j->makeSound();
	i->makeSound();

	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;
	
	std::cout << std::endl << "======================" << std::endl << std::endl;

	Cat original;
	original.fillBrainCells("Some thoughts...");
	std::cout << std::endl;

	Cat copy = original;
	std::cout << std::endl;

	original.printBrainCells();
	std::cout << std::endl;
	copy.printBrainCells();
	
	std::cout << std::endl;

	std::cout << std::endl << original.getBrainAddress() << std::endl;
	std::cout << copy.getBrainAddress() << std::endl << std::endl;

	return (0);
}