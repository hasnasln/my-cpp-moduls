#include "Character.hpp"

Character::Character(): _name("default"), _count(0)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

Character::Character(const std::string name): _name(name), _count(0)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

Character::Character(const Character &other): _name(other._name), _count(other._count)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

Character Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		_count = other._count;
		for (int i = 0; i < 4; i++)
		{
			if(_materias[i])
				delete _materias[i];
			if(other._materias[i])
				_materias[i] = other._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
			
	}
	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (_count < 4 && m )
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materias[i] == NULL)
			{
				_materias[i] = m;
				_count++;
				return;
			}
		}
		_materias[_count] = m;
		_count++;
	}
	return;
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && _materias[idx])
	{
		_materias[idx] = NULL;
		_count--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && _materias[idx])
	{
		_materias[idx]->use(target);
	}
}