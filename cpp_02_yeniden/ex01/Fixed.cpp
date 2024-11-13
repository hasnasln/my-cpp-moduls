#include "Fixed.hpp"

Fixed::Fixed(void): _x(0)
{
	std::cout << "Default constructor called" << std::endl; 
}
Fixed::Fixed(const Fixed& other): _x(other.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl; 
}
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator calle" << std::endl; 
	if(this != &other)
		this->setRawBits(other.getRawBits());
	return(*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl; 
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl; 
	return (_x);
}
void	Fixed::setRawBits(int const raw)
{
	std::cout << "" << std::endl; 
	_x = raw;
}

/*----ex01------*/

Fixed::Fixed(const int num)
{
	this->setRawBits(num * (1 << _y));
}

Fixed::Fixed(const float num)
{
	if(num > 0.0f)
		this->setRawBits(num * (1 << _y) + 0.5f);
	else
		this->setRawBits(num * (1 << _y) - 0.5f);
}
float Fixed::toFloat(void) const
{
	return (float(_x) / float(1 << _y));
}
int	Fixed::toInt(void) const
{
	return(_x / (1 << _y));
}

std::ostream& operator<<(std::ostream &os, Fixed const &num)
{
	os << num.toFloat();
	return(os);
}