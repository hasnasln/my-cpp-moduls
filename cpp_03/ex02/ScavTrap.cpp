#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout <<  "\033[32m" << "ScavTrap destructor called" << "\033[30m" <<  std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "\033[32m" << "ScavTrap destructor called" << "\033[30m" <<  std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "\033[32m" << "ScavTrap constructor called" << "\033[30m" <<  std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAtacDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "\033[32m" << "ScavTrap copy constructor called" << "\033[30m" <<  std::endl;
}

ScavTrap ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap copy operator called" << std::endl;
	return *this;	
}

/*-----------Üye fonsiyonlar ---------------------*/

void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
		return ;
	std::cout << "\033[32m" << "ScavTrap " << this->getName() << " attack " << target << ", causing "
	<< this->getAtacDamage() << " points of damage!" << "\033[30m" <<  std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate()
{
	std::cout << "\033[32m" << "ScavTrap " << this->getName() << " have enterred in Gate keeper mode" << "\033[30m" <<  std::endl;
}


