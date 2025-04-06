#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** arg)
{
	if (argc == 1)
	{
		std::cerr << "./btc [input]" << std::endl;
		return (1);
	}
	try
	{
		Btc a("data.csv");
		a.parseExchangeInput(arg[1]);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}