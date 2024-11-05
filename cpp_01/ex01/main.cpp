#include "Zombie.hpp"
#include <iostream>

int main()
{
	Zombie *all;

	all = zombieHorde(10, "ali");
	delete[] all;
}