#include <iostream>
#include "iter.hpp"


int main()
{
	std::string aray[5];
	aray[0] = "ali";
	aray[1] = "veli";
	aray[2] = "deli";
	aray[3] = "mehmet";
	aray[4] = "ahmet";
	iter(aray, 5, sayHi);
}