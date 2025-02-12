#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void charPrint(int i)
{
	if (i < 0 || i > 127)
		std::cout << "Char: not converted" << std::endl;
	else if (!isprint(i))
		std::cout << "Char: character that cannot be displayed" << std::endl;
	else
		std::cout << "Char: " << static_cast<char>(i) << std::endl;
}

void charConverter(const std::string &input)
{
	char c = input[0];
	charPrint(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(3) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(3) << static_cast<double>(c) << std::endl;
}

void intConverter(const std::string &input)
{
	int i = atoi(input.c_str());

	charPrint(i);
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(3) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(3) << static_cast<double>(i) << std::endl;
}

void floatConverter(const std::string &input)
{
	float i = atof(input.c_str());

	charPrint(i);
	std::cout << "Int: " << static_cast<int>(i) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(3) << i << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(3) << static_cast<double>(i) << std::endl;
}

void doubleConverter(const std::string &input)
{
	double i = atof(input.c_str());

	charPrint(i);
	std::cout << "Int: " << static_cast<int>(i) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(3) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(3) << i << std::endl;
}

void PseudoLiteralConvertor(const std::string &input)
{
	if(input == "nan" || input == "nanf")
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	}
	else if(input == "+inf" || input == "+inff")
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: inff" << std::endl;
		std::cout << "Double: inf" << std::endl;
	}
	else if(input == "-inf" || input == "-inff")
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: -inff" << std::endl;
		std::cout << "Double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input)
{
	int type = checkType(input);

	if (type == CHAR)
		charConverter(input);
	else if (type == INT)
		intConverter(input);
	else if (type == FLOAT)
		floatConverter(input);
	else if (type == DOUBLE)
		doubleConverter(input);
	else if (type == PsoidoL)
		PseudoLiteralConvertor(input);
	else 
		std::cout << "This is unknow type." << std::endl;
}