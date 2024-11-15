#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("ClapTrap"), _hit_points(10), _energy_points(10), _atac_damage(0)
{
	std::cout << "\033[31m" << "ClapTrap default constructor called" << "\033[30m" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "\033[31m" << "ClapTrap destructor called" << "\033[30m" << std::endl;
}
ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _atac_damage(0)
{
	std::cout << "\033[31m" << "ClapTrap constructor called" << "\033[30m" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other): _name(other.getName()), _hit_points(other.getHitPoints()), \
_energy_points(other.getEnergyPoints()), _atac_damage(other.getAtacDamage())
{
	std::cout << "\033[31m" << "ClapTrap copy constructor called" << "\033[30m" << std::endl;
}


/*---------------Set-------------------*/

void ClapTrap::setName(std::string name)
{
	_name = name;
}
void ClapTrap::setHitPoints(int hit_points)
{
	_hit_points = hit_points;
}
void ClapTrap::setEnergyPoints(int energy_points)
{
	_energy_points = energy_points;
}
void  ClapTrap::setAtacDamage(int atac_damage)
{
	_atac_damage = atac_damage;
}


/*--------------get--------------------*/

std::string ClapTrap::getName(void) const
{
	return _name;
}
int ClapTrap::getHitPoints(void) const
{
	return _hit_points;
}
int ClapTrap::getEnergyPoints(void) const
{
	return _energy_points;
}
int  ClapTrap::getAtacDamage(void) const
{
	return _atac_damage;
}

/*-----------------Opertator - Overloding-----------------*/
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		std::cout << "CLAPTRAP assignation operator called" << std::endl;
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAtacDamage(other.getAtacDamage());
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &ClapTrap)
{
	out << "\033[31m" << "ClapTrap " << ClapTrap.getName() << " has " << ClapTrap.getHitPoints() 
	<< " hit points, " << ClapTrap.getEnergyPoints() << " energy points and " 
	<< ClapTrap.getAtacDamage() << " atac damage" << "\033[30m" << std::endl;
	return out;
}

/*-----------------Member Function-----------------*/

void ClapTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0) /* ikisinden biri 0 isi hiçbirşey yapmaması gerektiği yazıyor*/
		return ;
	std::cout << "\033[32m" << "ScavTrap " << this->getName() << " attack " << target << ", causing "
	<< this->getAtacDamage() << " points of damage!" << "\033[30m" <<  std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() <= 0)
		return ;
	std::cout << "\033[31m" << "ClapTrap " << this->getName() << " take " << amount << " points of damage!" << "\033[30m" << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
		return ;
	std::cout << "\033[31m" << "ClapTrap " << this->getName() << " repaired " << amount << " points of energy!" << "\033[30m" << std::endl;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

