#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data data = {42};

	std::cout << "Original Pointer Address:\t" << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Address as Integer value:\t" << raw << std::endl;

	Data *back = Serializer::deserialize(raw);
	std::cout << "Recovered Value:\t\t" << back << std::endl;

	std::cout << "Value through ptr:\t\t" << back->value << std::endl;

	return (0);
}
