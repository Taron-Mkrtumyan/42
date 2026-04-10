#include <iostream>
#include <string>
#include "SedIsForLosers.hpp"

int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);
	if (filename.empty() || s1.empty())
	{
		std::cerr << "Error: First and Second arguments cannot be empty strings." << std::endl;
		return (1);
	}
	SedIsForLosers sed(filename, s1, s2);
	sed.replace();
	return (0);
}