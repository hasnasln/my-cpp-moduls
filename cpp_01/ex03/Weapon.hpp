#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		void setType(std::string type);
		const std::string &getType(void) const;

	private:
		std::string _tpye;
};

#endif