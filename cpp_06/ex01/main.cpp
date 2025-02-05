#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"
#include <stdint.h>

// c98 standartı silindi

int main()
{
	Data *ptr = new Data(10, "hasan");

	std::cout << "Default address: " << ptr << std::endl;
	std::cout << ptr->str << "-" << ptr->value << std::endl;

	uintptr_t a = Serializer::serialize(ptr);
	std::cout << "Serialized value: " << a << std::endl;

	ptr = Serializer::deserialize(a);
	std::cout << "Deserialized address: " << ptr << std::endl;
	std::cout << ptr->str << "-" << ptr->value << std::endl;

	delete ptr;
}