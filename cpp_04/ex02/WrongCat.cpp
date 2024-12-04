#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	type = "WrongCat";
	std::cout << BLUE << "WrongCat default constructre called" << RESET << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << BLUE << "WrongCat destructre called" << RESET << std::endl;
}
WrongCat::WrongCat(const std::string type): WrongAnimal(type)
{
	std::cout << BLUE << "WrongCat constructre called" << RESET << std::endl;
}
WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
	std::cout << BLUE << "WrongCat coopy constracture called" << RESET << std::endl;
}
WrongCat WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << BLUE << "WrongCat assignment operator called" << RESET << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << BLUE << "Miavvvvv !!" << RESET << std::endl;
}