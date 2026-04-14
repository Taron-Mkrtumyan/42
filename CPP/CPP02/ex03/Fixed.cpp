#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const n) : _value(n << this->_fracBits)
{
	//std::cout << "Int constructor called" << std::endl;

	return ;
}

Fixed::Fixed(float const n)
{
	//std::cout << "Float constructor called" << std::endl;

	this->_value = n * (1 << this->_fracBits);
	return ;
}

Fixed::Fixed(Fixed const & other)
{
	if (this != &other)
	{
		//std::cout << "Copy constructor called" << std::endl;
		*this = other;
	}
	return ;
}

Fixed & Fixed::operator=(Fixed const & other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;

	return ;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;

	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;

	this->_value = raw;
	return ;
}

float Fixed::toFloat( void ) const
{
	// std::cout << "toFloat member function called" << std::endl;

	return (static_cast<float>(_value) / (1 << this->_fracBits) );
}

int Fixed::toInt( void ) const
{
	// std::cout << "toInt member function called" << std::endl;

	return (_value >> this->_fracBits);
}

std::ostream & operator<<(std::ostream & out, Fixed const & instance)
{
	// std::cout << "Insertion operator called" << std::endl;

	out << instance.toFloat();
	return (out);
}

bool Fixed::operator>(Fixed const & other) const
{
	// std::cout << "Greater than operator called" << std::endl;

	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(Fixed const & other) const
{
	// std::cout << "Less than operator called" << std::endl;

	return (this->_value < other.getRawBits());
}

bool Fixed::operator>=(Fixed const & other) const
{
	// std::cout << "Greater than or equal operator called" << std::endl;

	return (this->_value >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const & other) const
{
	// std::cout << "Less than or equal operator called" << std::endl;

	return (this->_value <= other.getRawBits());
}

bool Fixed::operator==(Fixed const & other) const
{
	// std::cout << "Is Equal operator called" << std::endl;

	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(Fixed const & other) const
{
	// std::cout << "Is Not Equal operator called" << std::endl;

	return (this->_value != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const & other) const
{
	// std::cout << "Addition operator called" << std::endl;

	return (Fixed((this->toFloat() + other.toFloat()) * (1 << this->_fracBits)));
}

Fixed Fixed::operator-(Fixed const & other) const
{
	// std::cout << "Subtraction operator called" << std::endl;

	return Fixed((this->toFloat() - other.toFloat()) * (1 << this->_fracBits));
}

Fixed Fixed::operator*(Fixed const & other) const
{
	// std::cout << "Multiplication operator called" << std::endl;

	return Fixed((other.toFloat() * this->toFloat()) * (1 << this->_fracBits));
}

Fixed Fixed::operator/(Fixed const & other) const
{
	// std::cout << "Division operator called" << std::endl;

	if (other.getRawBits() == 0)
	{
		std::cerr << "Division by zero error" << std::endl;
		return Fixed();
	}
	return Fixed((this->toFloat() / other.toFloat()) * (1 << this->_fracBits));
}

Fixed & Fixed::operator++()
{
	// std::cout << "Pre-increment operator called" << std::endl;

	++this->_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	// std::cout << "Post-increment operator called" << std::endl;

	Fixed temp(*this);
	++this->_value;
	return (temp);
}

Fixed & Fixed::operator--()
{
	// std::cout << "Pre-decrement operator called" << std::endl;

	--this->_value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	// std::cout << "Post-decrement operator called" << std::endl;

	Fixed temp(*this);
	--this->_value;
	return (temp);
}

Fixed & Fixed::min(Fixed & f1, Fixed & f2)
{
	return (f1 < f2 ? f1 : f2);
}

const Fixed & Fixed::min(Fixed const & f1, Fixed const & f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed & Fixed::max(Fixed & f1, Fixed & f2)
{
	return (f1 > f2 ? f1 : f2);
}

const Fixed & Fixed::max(Fixed const & f1, Fixed const & f2)
{
	return (f1 > f2 ? f1 : f2);
}