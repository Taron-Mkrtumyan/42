#include <iostream>
#include <cmath>
#include "Point.hpp"
#include "Fixed.hpp"

#define epsilon (1.0f / 256.0f) // 1/256 is the smallest difference we can represent with 8 fractional bits

static float Area(float x1, float y1, float x2, float y2, float x3, float y3)
{
	// std::cout << "x1: " << x1 << ", y1: " << y1 << ", x2: " << x2 << ", y2: " << y2 << ", x3: " << x3 << ", y3: " << y3 << std::endl;
	return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

	// std::cout << a.getX() << ", " << a.getY() << std::endl;
	// std::cout << b.getX() << ", " << b.getY() << std::endl;
	float A = std::abs(Area(a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat()));
	float A1 = std::abs(Area(point.getX().toFloat(), point.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat()));
	float A2 = std::abs(Area(a.getX().toFloat(), a.getY().toFloat(), point.getX().toFloat(), point.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat()));
	float A3 = std::abs(Area(a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), point.getX().toFloat(), point.getY().toFloat()));

	// std::cout << "A: " << A << ", A1 + A2 + A3: " << A1 + A2 + A3 << std::endl;

	if (A1 < epsilon || A2 < epsilon || A3 < epsilon)
        return false;
	
	return (std::abs(A - (A1 + A2 + A3)) < epsilon);
}