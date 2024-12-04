#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"

class AAnimal
{
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const std::string type);
		AAnimal(const AAnimal &other);
		void operator=(const AAnimal &other);

		std::string getType(void) const;
		void setType(const std::string tpye);
		virtual void makeSound() const = 0;

	protected:
		std::string type;
};

#endif