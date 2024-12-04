#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const std::string type): AMateria(type)
{
}

Cure::Cure(const Cure &other): AMateria(other)
{
}

Cure Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}