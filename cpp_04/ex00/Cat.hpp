#ifndef Cat_HPP
# define Cat_HPP

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const std::string type);
		Cat(const Cat &other);
		Cat operator=(const Cat &other);
		void makeSound() const;
};

#endif