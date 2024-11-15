#ifndef DIAMOND_HPP
# define DIAMOND_HPP

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap: virtual public FragTrap, virtual public ClapTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		~DiamondTrap(void);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap operator=(const DiamondTrap &other);

		void vhoAmI();
	private:
		std::string _name;

};


#endif