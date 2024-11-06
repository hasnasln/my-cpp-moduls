#include "HumanB.hpp"

void HumanB::attack()
{
	if (_Weapon == NULL)
		std::cout << _name << " could not attack" << std::endl;
	else
		std::cout << _name << " attacks with their " << (*_Weapon).getType() << std::endl;
}

HumanB::HumanB(std::string name): _name(name), _Weapon(NULL)
{
}
HumanB::~HumanB()
{
}
void HumanB::setWeapon(Weapon &weapon)
{
	_Weapon = &weapon;
}
