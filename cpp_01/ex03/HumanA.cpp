#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << _name << _Weapon.getType() << "ile saldirdi." << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon): _name(name) , _Weapon(weapon)
{
}
HumanA::~HumanA()
{
}