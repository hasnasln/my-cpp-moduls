#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

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
	typename T::iterator it = find(container.begin(), container.end(), value);
	if ( it == container.end())
		throw NotFound();
	return it;
}

#endif // EASYFIND_HPP