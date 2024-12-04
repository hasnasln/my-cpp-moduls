#include "Animal.hpp"

Animal::Animal():type("unnamed")
{
	std::cout << RED << "Animal default constructre called" << RESET << std::endl;
}
Animal::~Animal()
{
	std::cout << RED << "Animal destructre called" << RESET << std::endl;
}
Animal::Animal(const std::string type): type(type)
{
	std::cout << RED << "Animal constructre called" << RESET << std::endl;
}
Animal::Animal(const Animal &other): type(other.type)
{
	std::cout << RED << "Animal coopy constracture called" << RESET << std::endl;
}
Animal Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << RED << "Animal assignment operator called" << RESET << std::endl;
	return *this;
}
std::string Animal::getType(void) const
{
	return this->type;
}
void Animal::setType(const std::string type)
{
	this->type = type;
}

void Animal::makeSound() const
{
	std::cout << RED << "*-*" << RESET << std::endl;
}