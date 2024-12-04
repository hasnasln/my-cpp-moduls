#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	public:
		Dog();
		~Dog();
		Dog(const std::string type);
		Dog(const Dog &other);
		Dog operator=(const Dog &other);
		
		void makeSound() const;
		void print_adress() const;
	private:
		Brain *brain;
};

#endif