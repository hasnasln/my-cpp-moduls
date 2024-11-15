#include "ScavTrap.hpp"


int main()
{
	{
		ClapTrap ClabTrap("hasan");
		std::cout << ClabTrap << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
	{
		ScavTrap ScavTrap("aslan");
		std::cout << ScavTrap << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
	ScavTrap scavTrap("ScavTrap");
	ScavTrap scavTrap2(scavTrap);
	ScavTrap scavTrap3("ScavTrap3");

	scavTrap.attack("ScavTrap2");
	scavTrap2.takeDamage(10);
	scavTrap2.beRepaired(10);
	scavTrap.guardGate();
	std:: cout << scavTrap << std::endl;
}