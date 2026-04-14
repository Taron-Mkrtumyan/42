#include <iostream>
#include <cmath>
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0.0f), _y(0.0f)
{
	//std::cout << "Default constructor called" << std::endl;

	return ;
}

Point::Point(float const x, float const y) : _x(x), _y(y) 
{
	//std::cout << "Int constructor called" << std::endl;

	return ;
}

Point::Point(Point const & other) : _x(other._x), _y(other._y)
{
	return ;
}

Point & Point::operator=(Point const & other)
{
	(void) other;
	//std::cout << "Copy assignment operator called" << std::endl;

	// if (this != &other)
	// {
	// 	this->_x = other._x;
	// 	this->_y = other._y;
	// }
	return (*this);
}

Point::~Point()
{
	//std::cout << "Destructor called" << std::endl;

	return ;
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}