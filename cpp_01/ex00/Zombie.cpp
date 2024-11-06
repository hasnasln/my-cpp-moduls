#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "A new Zombi has been created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << ": has been slain" << std::endl;
}

void	Zombie::annonunce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}