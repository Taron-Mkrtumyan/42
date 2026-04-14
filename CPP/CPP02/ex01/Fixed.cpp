#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed(int const n) : _value(n << this->_fracBits)
{
	std::cout << "Int constructor called" << std::endl;

	return ;
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;

	this->_value = n * (1 << this->_fracBits);
	return ;
}

Fixed::Fixed(Fixed const & other)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
	return ;
}

Fixed & Fixed::operator=(Fixed const & other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

	return ;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_value = raw;
	return ;
}


float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_value) / (1 << this->_fracBits) );
}

int Fixed::toInt( void ) const
{
	return (_value >> this->_fracBits);
}

std::ostream & operator<<(std::ostream & out, Fixed const & instance)
{
	out << instance.toFloat();
	return (out);
}
