#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAtacDamage(30);
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap coopy operator called" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
		return;
	std::cout << "\033[32m" << "ScavTrap " << this->getName() << " attack " << target << ", causing "
	<< this->getAtacDamage() << " points of damage!" << "\033[30m" <<  std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << ": give me five!" << std::endl;
}