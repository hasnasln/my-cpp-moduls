#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("unnamed")
{
	std::cout << RED << "WrongAnimal default constructre called" << RESET << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructre called" << RESET << std::endl;
}
WrongAnimal::WrongAnimal(const std::string type): type(type)
{
	std::cout << RED << "WrongAnimal constructre called" << RESET << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other): type(other.type)
{
	std::cout << RED << "WrongAnimal coopy constracture called" << RESET << std::endl;
}
WrongAnimal WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << RED << "WrongAnimal assignment operator called" << RESET << std::endl;
	return *this;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}
void WrongAnimal::setType(const std::string type)
{
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << RED << "*-*" << RESET << std::endl;
}