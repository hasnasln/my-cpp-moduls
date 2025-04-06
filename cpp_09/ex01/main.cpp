#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <stack>
#include "RPN.hpp"

int main(int argc, char** arg)
{
	if (argc == 1)
	{
		(void) arg;
		std::cerr << "Error: dont enter number." << std::endl;
		return (1);
	}
	else
	{
		RPN hasan(arg[1]);
		if (hasan.flag != -1)
			hasan.calculateResult();
	}
}