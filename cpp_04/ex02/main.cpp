#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	Dog i;
	Cat j;
	Dog k(i);

	i.makeSound(); //will output the cat sound!
	j.makeSound();
	j.print_adress();

	// delete j;//should not create a leak
	// delete i;
	return 0;
}
