#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include "Span.hpp"


Span::Span(unsigned int N) : _capacity(N), _size(0) {}
Span::Span(Span const & other) : _capacity(other._capacity), _size(other._size), _numbers(other._numbers) {}
Span & Span::operator=(Span const & other)
{
    if (this != &other)
    {
        _capacity = other._capacity;
        _size = other._size;
        _numbers = other._numbers;
    }
    return *this;
}
Span::~Span() {}


void Span::addNumber(int number)
{
    if (_size >= _capacity)
        throw ( std::overflow_error("Span is full") );

    _numbers.push_back(number);
    _size++;
}


long long Span::shortestSpan() const
{
    if (_size < 2)
        throw ( std::runtime_error("Not enough numbers to find the shortest span") );

    std::vector<int> copy = _numbers;
    std::sort(copy.begin(), copy.end());
    long long minSpan = copy[1] - copy[0];

    for (size_t i = 2; i < copy.size(); ++i)
    {
        long long span = copy[i] - copy[i - 1];
        if (span < minSpan)
            minSpan = span;
    }

    return ( minSpan );
}


long long Span::longestSpan() const
{
    if (_size < 2)
        throw ( std::runtime_error("Not enough numbers to find the longest span") );

    return (    *std::max_element(_numbers.begin(), _numbers.end())
                - 
                *std::min_element(_numbers.begin(), _numbers.end()) );
}