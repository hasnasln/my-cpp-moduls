#include "Fixed.hpp"

Fixed::Fixed(): _x(0)
{
}
Fixed::~Fixed()
{
}
Fixed::Fixed(const Fixed& other): _x(other.getRawBits())
{
}
Fixed& Fixed::operator=(const Fixed& other)
{
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

/*------------------------Ex01--------------------------------------*/

Fixed::Fixed(const int number)
{
	this->setRawBits(number * (1 << _y));
}
Fixed::Fixed(const float number)
{

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

/*-----------------------------ex02-------------------------------*/
Fixed Fixed::operator+(const Fixed& other)
{
	this->setRawBits(this->getRawBits() + other.getRawBits());
	return (*this);
}
Fixed Fixed::operator-(const Fixed& other)
{
	this->setRawBits(this->getRawBits() - other.getRawBits());
	return (*this);
}
Fixed Fixed::operator*(const Fixed& other)
{
	this->setRawBits(this->getRawBits() * other.getRawBits());
	return (*this);
}
Fixed Fixed::operator/(const Fixed& other)
{
	this->setRawBits(this->getRawBits() / other.getRawBits());
	return (*this);
}

Fixed Fixed::operator++(void) // ++a
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}
Fixed Fixed::operator--(void) //--a
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}
Fixed Fixed::operator++(int) // a++
{
	Fixed temp(*this);

	++(*this);
	return temp;
}
Fixed Fixed::operator--(int)// a--
{
	Fixed temp(*this);

	--(*this);
	return temp;
}

bool Fixed::operator>(const Fixed& a) const
{
	if(this->getRawBits() > a.getRawBits())
		return true;
	return false;
}
bool Fixed::operator<(const Fixed& a) const
{
	if(this->getRawBits() < a.getRawBits())
		return true;
	return false;
}
bool Fixed::operator<=(const Fixed& a) const
{
	if(this->getRawBits() <= a.getRawBits())
		return true;
	return false;
}
bool Fixed::operator>=(const Fixed& a) const
{
	if(this->getRawBits() >= a.getRawBits())
		return true;
	return false;
}
bool Fixed::operator==(const Fixed& a) const
{
	if(this->getRawBits() == a.getRawBits())
		return true;
	return false;
}
bool Fixed::operator!=(const Fixed& a) const
{
	if(this->getRawBits() != a.getRawBits())
		return true;
	return false;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return b;
	else
		return a;
}
Fixed const& Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}