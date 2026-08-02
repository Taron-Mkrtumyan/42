#include <iostream>
#include "iter.hpp"

void multiplyByTwo(int & n) { n *= 2; }

template <typename T>
void printElement(T const & elem)
{
    std::cout << elem << " ";
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
	::iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;


    ::iter(intArray, intArraySize, multiplyByTwo);

    std::cout << "Modified int array: ";
	::iter(intArray, intArraySize, printElement<int>);	
    std::cout << std::endl;

    return (0);
}
