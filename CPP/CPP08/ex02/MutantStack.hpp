#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

 #include <exception>

 template <typename T>
 class MutantStack
 {
    private:
        unsigned int    _size;
        T *             _data;

    public:
        MutantStack();
        MutantStack(unsigned int size);
        MutantStack(MutantStack const & src);
        MutantStack & operator=(MutantStack const & src);
        ~MutantStack();

        T &             operator[](unsigned int index);
        T const &       operator[](unsigned int index) const;
        unsigned int    size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
 };


 #define BOLD_CRIMSON "\033[1m\033[38;2;220;20;60m"
 #define RESET "\033[0m"


 #include "MutantStack.tpp"

#endif
