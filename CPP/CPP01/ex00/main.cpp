#include "Zombie.hpp"
#include <iostream>

int	main()
{
	{
		Zombie zombie1("Zombie1");
		zombie1.announce();
		zombie1.~Zombie();
	}

	std::cout << std::endl;

	Zombie* zombie2 = newZombie("Zombie2");
	zombie2->announce();
	delete zombie2;

	std::cout << std::endl;

	randomChump("Zombie3");

	return (0);
}
