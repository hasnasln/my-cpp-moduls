#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"

class Animal
{
	public:
		Animal();
		~Animal();
		Animal(const std::string type);
		Animal(const Animal &other);
		Animal operator=(const Animal &other);

		std::string getType(void) const;
		void setType(const std::string tpye);
		
		virtual void makeSound() const;
	private:
		std::string type;
};

#endif