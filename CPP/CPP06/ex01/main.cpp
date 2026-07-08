#include <iostream>
#include <cstdint>
#include "Serializer.hpp"

int main()
{
	Data data = {42};

	std::cout << "Original Pointer Address: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Address as Integer value: (Serialized value) : " << raw << std::endl;

	Data *back = Serializer::deserialize(raw);
	std::cout << "Recovered Value: " << back << std::endl;

	std::cout << "Value through ptr: " << back->value << std::endl;

	return (0);
}
