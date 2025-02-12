#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>

class NotFound :public std::exception
{
	public:
		const char * what() const throw()
		{
			return "Value not found in container";
		}
};


template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	for (typename T::iterator it = container.begin(); it != container.end() ; it++)
	{
		if (*it == value)
			return it;
	}
	throw NotFound();
}



#endif // EASYFIND_HPP