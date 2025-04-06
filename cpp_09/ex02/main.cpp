#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <deque>




int main(int argc, const char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: Please use like this:" << std::endl;
		std::cout << "./PmergeMe \"2 3 4 5\"" << std::endl;
		return 0;
	}
	std::vector<int> vec;
	std::deque<int> lst;
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << " ";
		vec.push_back(atoi(argv[i]));
		lst.push_back(atoi(argv[i]));
	}
	std::cout << std::endl;
	double v1 = PmergeMe(vec);
	double v2 = PmergeMe(lst);
	std::cout << "After: ";
	for(size_t x = 0; x < lst.size(); x++)
		std::cout << lst[x] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector :" << v1 << "ms"<< std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list :" << v2 << "ms" << std::endl;
	return 0;
}