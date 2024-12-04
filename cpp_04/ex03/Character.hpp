#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character: public ICharacter
{
	public:
		Character();
		~Character();
		Character(const std::string name);
		Character(const Character &other);
		Character operator=(const Character &other);

		/*--------Intarface--Fonctions--------*/
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria *_materias[4];
		int _count;
};

# endif 