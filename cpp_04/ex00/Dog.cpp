#include "Dog.hpp"

Dog::Dog(): Animal()
{
	type = "Dog";
	std::cout << YELLOW << "Dog default constructre called" << RESET << std::endl;
}
Dog::~Dog()
{
	std::cout << YELLOW << "Dog destructre called" << RESET << std::endl;
}
Dog::Dog(const std::string type): Animal(type)
{
	std::cout << YELLOW << "Dog constructre called" << RESET << std::endl;
}
Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << YELLOW << "Dog coopy constracture called" << RESET << std::endl;
}
Dog Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << YELLOW << "Dog assignment operator called" << RESET << std::endl;
	return *this;
}
void Dog::makeSound() const
{
	std::cout << YELLOW << "AVUUUUUU !!" << RESET << std::endl;
}