#include "Zombie.hpp"
#include <iostream>

int	main()
{
	int number_of_zombies = 5;
	Zombie* arrZombie = zombieHorde(number_of_zombies, "Alo");

	if (arrZombie)
	{
		for (int i = 0; i < number_of_zombies; ++i)
			arrZombie[i].announce();
		delete[] arrZombie;
	}

	return (0);
}
