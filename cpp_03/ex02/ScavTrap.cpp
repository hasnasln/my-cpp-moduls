#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << BLUE << "ScavTrap default constructure called" << RESET <<  std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAtacDamage(20);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << BLUE << "ScavTrap destructor called" << RESET <<  std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << BLUE << "ScavTrap constructor called" << RESET <<  std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAtacDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << BLUE << "ScavTrap copy constructor called" << RESET <<  std::endl;
}

ScavTrap ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << BLUE << "ScavTrap copy constructor called" << RESET << std::endl;
	return *this;
}

/*-----------Üye fonsiyonlar ---------------------*/

void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
		return ;
	std::cout << BLUE << "ScavTrap " << this->getName() << " attack " << target << ", causing "
	<< this->getAtacDamage() << " points of damage!" << RESET <<  std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate()
{
	std::cout << BLUE << this->getName() << " have enterred in Gate keeper mode" << RESET <<  std::endl;
}


