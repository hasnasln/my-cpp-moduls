#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("ClapTrapA");
	ClapTrap b("ClapTrapB");
	ClapTrap c("ClapTrapC");
	ClapTrap a2;
	a2 = a;

	std::cout << a ;
	std::cout << b ;
	std::cout << c ;

	a.attack("ClapTrapB");
	b.takeDamage(0);
	c.beRepaired(5);

	std::cout << a ;
	std::cout << b ;
	std::cout << c ;
}