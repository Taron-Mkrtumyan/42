#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main( void )
{
	try
	{
		std::vector<int> v(10, 10);
		v.insert(v.begin() + 7, 5);
		v.push_back(5);
		std::vector<int>::iterator it;

		it = easyfind(v, 5);
		std::cout << "Index position: " << it - v.begin() << std::endl;
		
		it = easyfind(v, 6);
		std::cout << "Index position: " << it - v.begin() << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}