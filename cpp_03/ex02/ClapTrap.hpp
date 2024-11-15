#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);

		void setName(std::string name);
		void setHitPoints(int hit_points);
		void setEnergyPoints(int energy_points);
		void setAtacDamage(int atac_damage);
		
		std::string getName(void) const;
		int getHitPoints(void) const;
		int getEnergyPoints(void) const;
		int getAtacDamage(void) const;
		
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_atac_damage;
		
};

std::ostream &operator<<(std::ostream &out, const ClapTrap &ClapTrap);

#endif