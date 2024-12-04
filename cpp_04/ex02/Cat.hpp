#ifndef Cat_HPP
# define Cat_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
	public:
		Cat();
		~Cat();
		Cat(const std::string type);
		Cat(const Cat &other);
		Cat operator=(const Cat &other);
		void makeSound() const;
		void print_adress() const;
	private:
		Brain *brain;
};

#endif