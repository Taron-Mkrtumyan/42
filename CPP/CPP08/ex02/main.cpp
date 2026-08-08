#include <iostream>
#include <string>
#include "MutantStack.hpp"
#include <list>

int main()
{
    try
    {
        MutantStack< int > mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << "Top element: " << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "Stack size after pop: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);

        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);

    }
    catch (std::exception const & e)
    {
        std::cerr << BOLD_CRIMSON << "Error: " << e.what() << RESET << std::endl;
    }

    return 0;
}