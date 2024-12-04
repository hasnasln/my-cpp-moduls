#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _count(0)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other): _count(other._count)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = other._materias[i];
}

MateriaSource MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		_count = other._count;
		for (int i = 0; i < 4; i++)
		{
			if (_materias[i])
				delete _materias[i];
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (_count < 4)
	{
		_materias[_count] = m;
		_count++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return NULL;
}