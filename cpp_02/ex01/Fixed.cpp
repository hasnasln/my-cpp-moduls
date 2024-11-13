#include "Fixed.hpp"

Fixed::Fixed(): _x(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other): _x(other.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operato called" << std::endl;
	if (this != &other)
	{
		this->setRawBits(other.getRawBits());
	}
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (_x);
}

void Fixed::setRawBits( int const raw )
{
	_x = raw;
}
/*----------------------Ex01------------------------*/


Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(number << Fixed::_y);
}
Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	if (number >= 0.0f)
		this->setRawBits((number * (1 << _y)) + 0.5f);
	else
		this->setRawBits((number * (1 << _y)) - 0.5f);
}
float Fixed::toFloat(void) const
{
	return ((float)(this->getRawBits()) / (float)(1 << _y));
}
int Fixed::toInt(void) const
{
	return(this->getRawBits() / (1 << _y));
}
std::ostream& operator<<(std::ostream &os, Fixed const &a)
{
	os << a.toFloat();
	return (os);
}