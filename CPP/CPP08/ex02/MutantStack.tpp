#include "MutantStack.hpp"

template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size), _data(size > 0 ? new T[size]() : NULL) {}

template <typename T>
Array<T>::Array(Array const & src) : _size(src._size), _data(NULL)
{
    if (this->_size > 0)
    {
        this->_data = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_data[i] = src._data[i];
    }
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & src)
{
    if (this != & src)
    {
        delete[] this->_data;
        this->_size = src._size;
        this->_data = NULL;
        if (this->_size > 0)
        {
            this->_data = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++)
                this->_data[i] = src._data[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() { delete [] _data; }

template <typename T>
T & Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfBoundsException();
    return (_data[index]);
}

template <typename T>
T const & Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw OutOfBoundsException();
    return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const { return _size; }

template <typename T>
const char * Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Index is out of bounds!");
}
