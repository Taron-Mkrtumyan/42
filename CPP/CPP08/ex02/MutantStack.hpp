#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack()                           : std::stack<T, Container>() {}
        MutantStack(MutantStack const & other)  : std::stack<T, Container>(other) {}
        MutantStack & operator=(MutantStack const & other)
        {
            if (this != &other)
                std::stack<T, Container>::operator=(other);
            return *this;
        }
        ~MutantStack() {}

        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        iterator            begin()     { return this->c.begin(); }
        iterator            end()       { return this->c.end(); }

        const_iterator      begin() const { return this->c.begin(); }
        const_iterator      end() const   { return this->c.end(); }

        reverse_iterator    rbegin()        { return this->c.rbegin(); }
        reverse_iterator    rend()          { return this->c.rend(); }

        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const   { return this->c.rend(); }
};


 #define BOLD_CRIMSON "\033[1m\033[38;2;220;20;60m"
 #define RESET "\033[0m"


#endif
