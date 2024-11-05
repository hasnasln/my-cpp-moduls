#include "Zombie.hpp"


int main(void)
{
	Zombie *zombie;

	zombie = newZombie("heap");
	zombie->annonunce();
	randomChump("stack");

	delete zombie;
	return (0);
}