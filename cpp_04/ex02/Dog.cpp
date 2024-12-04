#include "Dog.hpp"

Dog::Dog(): AAnimal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << YELLOW << "Dog default constructre called" << RESET << std::endl;
}
Dog::~Dog()
{
	delete brain;
	std::cout << YELLOW << "Dog destructre called" << RESET << std::endl;
}
Dog::Dog(const std::string type): AAnimal(type)
{
	brain = new Brain();
	std::cout << YELLOW << "Dog constructre called" << RESET << std::endl;
}
Dog::Dog(const Dog &other): AAnimal(other)
{
	brain = new Brain();
	*brain = *(other.brain);
	std::cout << YELLOW << "Dog coopy constracture called" << RESET << std::endl;
}
Dog Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		*brain = *(other.brain);
	}
	std::cout << YELLOW << "Dog assignment operator called" << RESET << std::endl;
	return *this;
}
void Dog::makeSound() const
{
	std::cout << YELLOW << "AVUUUUUU !!" << RESET << std::endl;
}

void Dog::print_adress() const
{
	std::cout << "Brain adress: " << brain << std::endl;
}