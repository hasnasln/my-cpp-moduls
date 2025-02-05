#include <climits> //INT_MIN INT_MAX
#include <cerrno> // errno
#include <cstdlib> // strtol
#include "ScalarConverter.hpp" // ENUM


bool isChar(const std::string &input)
{
	if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
		return true;
	return false;
}

bool isInt(const std::string &input)
{
	char *end;
	errno = 0;
	long num = std::strtol(input.c_str(), &end, 10);

	if (*end != '\0')
		return false;
	if (errno == ERANGE || num > INT_MAX || num < INT_MIN)
		return false;
	return true;
}


bool isDorF(const std::string &input, int *type)
{
	bool haveDot = false;
	size_t i = 0;

	if (input[0] == '-' || input[0] == '+')
		i = 1;
	for (; i < input.length(); i++)
	{
		if (!haveDot && input[i] == '.')
			haveDot = true;
		else if (isdigit(input[i]))
			continue;
		else
		{
			if ((i == input.length() - 1) && (input[i] == 'f' || input[i] == 'F')) // if the last character is f or F
			{
				*type = FLOAT;
				return true;
			}
			return false;
		}
	}
	*type = DOUBLE;
	return true;
}

bool isPseudoLiteral(const std::string &input)
{
	return (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff");
}

int checkType(const std::string &input)
{
	int type = 0;
	if(isChar(input))
		return CHAR;
	if(isInt(input))
		return INT;
	if(isDorF(input, &type))
		return type;
	if (isPseudoLiteral(input))
		return PsoidoL;
	return UNKNOW;
}