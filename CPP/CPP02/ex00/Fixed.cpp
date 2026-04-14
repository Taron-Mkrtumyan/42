#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;

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
