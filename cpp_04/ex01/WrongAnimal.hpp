#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal operator=(const WrongAnimal &other);

		std::string getType(void) const;
		void setType(const std::string tpye);
		
		void makeSound() const;
	private:
		std::string type;
};

#endif