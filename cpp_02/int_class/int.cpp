#include "int.hpp"

Hasan::Hasan(void)
{}
Hasan::Hasan(int value): _value(value)
{}
Hasan::~Hasan(void)
{}

Hasan::Hasan(const Hasan& other): _value(other.getValue())
{
}

void	Hasan::setValue(int value)
{
	_value = value;
}
int		Hasan::getValue(void) const
{
	return _value;
}

Hasan Hasan::operator+(const Hasan& left)
{
	return Hasan(this->getValue() + left.getValue());
}
Hasan Hasan::operator-(const Hasan& left)
{
	return Hasan(this->getValue() - left.getValue());
}
Hasan Hasan::operator*(const Hasan& left)
{
	return Hasan(this->getValue() * left.getValue());

}
Hasan Hasan::operator/(const Hasan& left)
{
	return Hasan(this->getValue() / left.getValue());
}

bool Hasan::operator<(const Hasan& left)
{
	if (this->getValue() < left.getValue())
		return (true);
	return false;
}
bool Hasan::operator>(const Hasan& left)
{
	if (this->getValue() > left.getValue())
		return (true);
	return false;
}
bool Hasan::operator<=(const Hasan& left)
{
	if (this->getValue() <= left.getValue())
		return (true);
	return false;
}
bool Hasan::operator>=(const Hasan& left)
{
	if (this->getValue() >= left.getValue())
		return (true);
	return false;
}
bool Hasan::operator!=(const Hasan& left)
{
	if (this->getValue() != left.getValue())
		return (true);
	return false;
}
bool Hasan::operator==(const Hasan& left)
{
	if (this->getValue() == left.getValue())
		return (true);
	return false;
}

Hasan Hasan::operator++()
{
	return Hasan(this->getValue() + 1);
}
Hasan Hasan::operator--()
{
	return Hasan(this->getValue() + 1);
}
Hasan Hasan::operator++(int)
{
	
	this->setValue(this->getValue() + 1);
}
Hasan Hasan::operator--(int)
{
	this->setValue(this->getValue() - 1);
}