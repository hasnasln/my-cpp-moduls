#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(),FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructre called" << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAtacDamage(FragTrap::getAtacDamage());
	this->setName("Unnamed -ClabTrab-");
	_name = "Unnamed -DiamondTrap";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructre called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap constructre called" << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAtacDamage(FragTrap::getAtacDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap copy constructre called" << std::endl;
	_name = other._name;
}

DiamondTrap DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other.getName();
	}
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name: " << _name << ", My ClabTrap name: " << this->getName() << std::endl;
}

