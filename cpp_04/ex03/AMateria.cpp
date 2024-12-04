#include "AMateria.hpp"

AMateria::AMateria(): _type("default")
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const & type): _type(type)
{
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
}

void	AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMAteria use"<< target.getName() << std::endl;
}