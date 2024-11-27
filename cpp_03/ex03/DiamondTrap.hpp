#ifndef DIAMOND_HPP
# define DIAMOND_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		~DiamondTrap(void);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap operator=(const DiamondTrap &other);

		void whoAmI();
	private:
		std::string _name;
};

#endif