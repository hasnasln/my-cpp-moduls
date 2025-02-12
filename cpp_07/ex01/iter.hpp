#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t size, void (*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void sayHi(T const &value)
{
	std::cout << "Hi! I'm a value: " << value << std::endl;
}

#endif // ITER_HPP