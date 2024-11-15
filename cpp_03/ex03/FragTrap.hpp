#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap operator=(const FragTrap &other);

		void attack(const std::string &target);
		void highFivesGuys(void);
};



#endif
