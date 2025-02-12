#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

enum Type{
	UNKNOW, CHAR, INT, FLOAT, DOUBLE, PsoidoL
};

class ScalarConverter
{
	public:
		static void convert(const std::string &input);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();
};

int checkType(const std::string &input);
#endif // SCALARCONVERTER_HPP