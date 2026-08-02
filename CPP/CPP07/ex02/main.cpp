#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void printArray(Array<T> const & arr, std::string const & name)
{
    std::cout << name << " (size: " << arr.size() << "): [ ";
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "]\n";

    return ;
}

int main()
{
    std::cout << "\n=== Test 1: Int Array Initialization ===" << std::endl;
    Array<int> intArr(5);
    printArray(intArr, "intArr (Value-initialized)");

    for (unsigned int i = 0; i < intArr.size(); ++i)
        intArr[i] = (i + 1) * 10;
    printArray(intArr, "intArr (Modified)");

    std::cout << "\n=== Test 2: String Array Type Integration ===" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "42";
    strArr[2] = "Network";
    printArray(strArr, "strArr");


    std::cout << "\n=== Test 3: Boundary Exception Checking ===" << std::endl;
    try
    {
        std::cout << "Attempting to access safe index (idx = size - 1)..." << std::endl;
        std::cout << "Value: " << intArr[intArr.size() - 1] << " (Success)" << std::endl;
        
        std::cout << "Attempting out-of-bounds access (idx == size)..." << std::endl;
        std::cout << intArr[intArr.size()] << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cout << "Caught Exception successfully: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Attempting negative out-of-bounds (idx = -1)..." << std::endl;
        std::cout << intArr[-1] << std::endl; 
    }
    catch (std::exception const & e)
    {
        std::cout << "Caught Exception successfully: " << e.what() << std::endl;
    }

    std::cout << "\nAll tests completed cleanly." << std::endl;

    return (0);
}
