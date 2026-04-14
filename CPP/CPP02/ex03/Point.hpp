#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed  const _x;
		Fixed  const _y;
		Point & operator=(Point const & other); //const _x _y => unused

	public:
		Point();
		Point(float x, float y);
		Point(Point const & other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

#endif