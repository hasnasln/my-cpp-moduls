#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

/*
   A
  / \
 B   C
  \ /
   D
*/

int main()
{
	// {
	// 	ClapTrap a("hasan");
	// 	std::cout << a << std::endl;
	// 	a.attack("aslan");
	// 	a.beRepaired(10);
	// 	a.takeDamage(15);
	// 	std::cout << a << std::endl;
	// }
	// {
	// 	ScavTrap a("hasan");
	// 	std::cout << a << std::endl;
	// 	a.attack("aslan");
	// 	a.beRepaired(10);
	// 	a.takeDamage(10);
	// 	a.guardGate();
	// }
	// {
	// 	FragTrap a("hasan");
	// 	std::cout << a << std::endl;
	// 	a.attack("aslan");
	// 	a.beRepaired(10);
	// 	a.takeDamage(10);
	// 	a.highFivesGuys();
	// }
	{
		DiamondTrap a;
		a.attack("hasan");
		a.beRepaired(10);
		a.takeDamage(100);
		a.takeDamage(100);
		a.takeDamage(100);
		a.guardGate();
		a.highFivesGuys();
		std::cout << a ;
	}
}