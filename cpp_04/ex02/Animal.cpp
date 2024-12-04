#include "Animal.hpp"

AAnimal::AAnimal():type("unnamed")
{
	std::cout << RED << "AAnimal default constructre called" << RESET << std::endl;
}
AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal destructre called" << RESET << std::endl;
}
AAnimal::AAnimal(const std::string type): type(type)
{
	std::cout << RED << "AAnimal constructre called" << RESET << std::endl;
}
AAnimal::AAnimal(const AAnimal &other): type(other.type)
{
	std::cout << RED << "AAnimal coopy constracture called" << RESET << std::endl;
}

void	AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << RED << "AAnimal assignment operator called" << RESET << std::endl;
}
std::string AAnimal::getType(void) const
{
	return this->type;
}
void AAnimal::setType(const std::string type)
{
	this->type = type;
}

void AAnimal::makeSound() const
{
	std::cout << RED << "*-*" << RESET << std::endl;
}