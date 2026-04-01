#include <iostream>
#include <cctype>

int	main(int ac, char *av[])
{
	if (ac != 1)
	{
		for (int i = 1; i < ac; ++i)
		{
			for (size_t j = 0; av[i][j]; ++j)
				std::cout << static_cast<char>(toupper(static_cast<unsigned char>(av[i][j])));
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
