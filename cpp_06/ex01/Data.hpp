#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data
{
	int value;
	std::string str;

	Data();
	Data(int value, std::string str);
};

#endif // DATA_HPP