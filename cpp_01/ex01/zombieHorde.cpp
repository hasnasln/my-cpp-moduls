#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	Zombie *all_zombie = new Zombie[N]; // burada varsayılan yapıcıya ihtiyaç var

	for (int i = 0; i < N; i++) 
	{
		new (&all_zombie[i]) Zombie(name);
		all_zombie[i].annonunce();
	}
	return (all_zombie);
}