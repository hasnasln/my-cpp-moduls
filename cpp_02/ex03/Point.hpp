#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		~Point(void);
		Point(Fixed x, Fixed y);
		Point(const Point& other);
		Point& operator=(const Point &other);

		const Fixed& getPointx(void) const;
		const Fixed& getPointy(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

/*
class Point
{
private:
	Fixed _x;
	Fixed _y;
public:
	void setPointx(Fixed const x);
	void setPointy(Fixed const y);
	Fixed getPointx(void) const;
	Fixed getPointy(void) const;
};*/

#endif