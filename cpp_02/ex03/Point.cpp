#include "Point.hpp"


Point::Point(): _x(0), _y(0)
{}

Point::~Point()
{}

Point::Point(Fixed x, Fixed y): _x(x), _y(y)
{
}

Point::Point(const Point &other): _x(other.getPointx()), _y(other.getPointy())
{
}

const Fixed& Point::getPointx(void) const
{
	return (_x);
}

const Fixed& Point::getPointy(void) const
{
	return (_y);
}

Point& Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}
