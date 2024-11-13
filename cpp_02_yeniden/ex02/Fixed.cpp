#include "Fixed.hpp"

Fixed::Fixed(void): _x(0)
{
}
Fixed::Fixed(const Fixed& other): _x(other.getRawBits())
{
}
Fixed&	Fixed::operator=(const Fixed& other)
{
	if(this != &other)
		this->setRawBits(other.getRawBits());
	return(*this);
}

Fixed::~Fixed(void)
{
}

int		Fixed::getRawBits(void) const
{
	return (_x);
}
void	Fixed::setRawBits(int const raw)
{
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

/*---ex02----*/

bool	Fixed::operator>(const Fixed& other) const
{
	if(this->getRawBits() > other.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator<(const Fixed& other) const
{
	if(this->getRawBits() < other.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator>=(const Fixed& other) const
{
	if(this->getRawBits() >= other.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator<=(const Fixed& other) const
{
	if(this->getRawBits() <= other.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator==(const Fixed& other) const
{
	if(this->getRawBits() == other.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator!=(const Fixed& other) const
{
	if(this->getRawBits() != other.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator+(const Fixed& other)
{
	this->setRawBits(this->getRawBits() + other.getRawBits());
	return(*this);
}
Fixed	Fixed::operator-(const Fixed& other)
{
	this->setRawBits(this->getRawBits() - other.getRawBits());
	return(*this);
}
Fixed	Fixed::operator*(const Fixed& other)
{
	this->setRawBits(this->getRawBits() * other.getRawBits() / (1 << Fixed::_y));
	return(*this);
}
Fixed	Fixed::operator/(const Fixed& other)
{
	this->setRawBits(this->getRawBits() / other.getRawBits() * (1 << Fixed::_y));
	return(*this);
}

Fixed	Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}
Fixed	Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}
Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

Fixed& Fixed::min(Fixed &num1, Fixed &num2)
{
	if(num1.getRawBits() > num2.getRawBits())
		return num1;
	return num2;
}
Fixed& Fixed::max(Fixed &num1, Fixed &num2)
{
	if(num1.getRawBits() > num2.getRawBits())
		return num1;
	return num2;
}
Fixed const& Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if(num1.getRawBits() > num2.getRawBits())
		return num1;
	return num2;
}
Fixed const&  Fixed:: max(Fixed const &num1, Fixed const &num2)
{
	if(num1.getRawBits() > num2.getRawBits())
		return num1;
	return num2;
}