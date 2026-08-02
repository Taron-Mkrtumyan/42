#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    private:
        unsigned int    _size;
        T *             _data;

    public:
        Array();
        Array(unsigned int size);
        Array(Array const & src);
        Array & operator=(Array const & src);
        ~Array();

        T &             operator[](unsigned int index);
        T const &       operator[](unsigned int index) const;
        unsigned int    size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
};

#include "Array.tpp"

#endif
