#include "Weapon.hpp"

void	Weapon::setType(std::string type)
{
	_tpye = type;
}
const std::string&  Weapon::getType(void) const
{
	return (_tpye);
}

Weapon::Weapon(std::string type): _tpye(type)
{
}
Weapon::~Weapon()
{
}