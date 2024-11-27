#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"

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