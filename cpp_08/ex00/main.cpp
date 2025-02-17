#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>


int main()
{
	std::vector<int> ali;
	std::list<int> ali2;
	std::deque<int> ali3;

	ali.push_back(0);
	ali.push_back(1);
	ali.push_back(2);
	ali.push_back(3);
	ali.push_back(4);
	ali.push_back(5);
	ali.push_back(6);
	ali.push_back(7);
	ali.push_back(8);
	ali.push_back(9);

	ali2.push_back(0);
	ali2.push_back(1);
	ali2.push_back(2);
	ali2.push_back(3);
	ali2.push_back(4);
	ali2.push_back(5);
	ali2.push_back(6);
	ali2.push_back(7);
	ali2.push_back(8);
	ali2.push_back(9);


	ali3.push_back(0);
	ali3.push_back(1);
	ali3.push_back(3);
	ali3.push_back(3);
	ali3.push_back(4);
	ali3.push_back(5);
	ali3.push_back(6);
	ali3.push_back(7);
	ali3.push_back(8);
	ali3.push_back(9);


	try
	{
		std::list<int>::iterator it = easyfind(ali2, 1);
		std::cout << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(ali, 2);
		std::cout << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		std::deque<int>::iterator it = easyfind(ali3, 3);
		std::cout << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}