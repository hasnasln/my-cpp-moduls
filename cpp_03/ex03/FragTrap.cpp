#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << YELLOW << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << YELLOW << "FragTrap destructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << YELLOW << "FragTrap constructor called" << RESET << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAtacDamage(30);
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << YELLOW << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << YELLOW << "FragTrap coopy operator called" << RESET << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if(this->getHitPoints() > 0)
		std::cout << YELLOW << "FragTrap " << this->getName() << ": give me five!" << RESET << std::endl;
}