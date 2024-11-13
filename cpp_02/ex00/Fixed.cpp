#include "Fixed.hpp"
#include <iostream>

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
	std::cout << "getRawBits Member function called" << std::endl;
	return (_x);
}

void Fixed::setRawBits( int const raw )
{
	_x = raw;
}