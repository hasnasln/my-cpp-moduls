#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	Zombie *all_zombie = new Zombie[N];

	for (int i = 0; i < N; i++) 
	{
		all_zombie[i].setName(name);
		all_zombie[i].annonunce();
	}
	return (all_zombie);
}