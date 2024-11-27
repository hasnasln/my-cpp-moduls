#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->setType("Cat");
	std::cout << BLUE << "Cat default constructre called" << RESET << std::endl;
}
Cat::~Cat()
{
	std::cout << BLUE << "Cat destructre called" << RESET << std::endl;
}
Cat::Cat(const std::string type): Animal(type)
{
	std::cout << BLUE << "Cat constructre called" << RESET << std::endl;
}
Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << BLUE << "Cat coopy constracture called" << RESET << std::endl;
}
Cat Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << BLUE << "Cat assignment operator called" << RESET << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << BLUE << "Miavvvvv !!" << RESET << std::endl;
}