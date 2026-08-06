#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "===== Subject test =====" << std::endl;

        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;



        std::cout << "\n===== insertRange() test =====" << std::endl;
        
        Span sp2(10001);
        std::vector<int> numbers(10000, 1);
        sp2.addNumber(10);

        sp2.insertRange(numbers.begin(), numbers.end());

        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;



        std::cout << "\n===== insertRange() overflow =====" << std::endl;

        Span sp3(3);
        sp3.insertRange(numbers.begin(), numbers.end());   // should throw
    }
    
    catch (const std::exception &e)
    {
        std::cerr << BOLD_CRIMSON << "Error: " << e.what() << RESET << std::endl;
    }

    return 0;
}
