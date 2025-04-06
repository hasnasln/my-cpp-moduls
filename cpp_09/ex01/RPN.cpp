#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN(std::string arg): flag(0)
{
	if (arg.find_first_not_of("0123456789*-+/ ") != std::string::npos)
	{
		std::cout << "Error" << std::endl;
		flag = -1;
		return ;
	}
	std::stringstream x(arg);
	std::string a;
	while(x >> a)
		_data.push(a);
}

RPN::RPN(const RPN &other):  flag(other.flag), _data(other._data)
{
}

RPN& RPN::operator=(const RPN &other)
{
	if(this != &other)
	{
		_data = other._data;
		flag = other.flag;
	}
	return *this;
}

RPN::~RPN()
{
}

int op(int x, int y, std::string z)
{
	if (z == "+")
		x = x + y;
	else if (z == "-")
		x = x - y;
	else if (z == "*")
		x = x * y;
	else
		x = x / y;
	return x;
}

void RPN::calculateResult()
{
	std::stack<std::string> operands;
	std::stack<int> values;

	while(_data.size())
	{
		std::string tmp = _data.top();
		if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/")
		{
			operands.push(tmp);
			_data.pop();
		}
		else
		{
			values.push(atoi(tmp.c_str()));
			_data.pop();
			tmp = _data.top();
			if (!(tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/"))
			{
				int hasan = op(atoi((tmp.c_str())), values.top(),   operands.top());
				_data.pop();
				operands.pop();
				values.pop();
				values.push(hasan);
			}
		}
	}
	int x;
	int y;
	bool flag = false;
	std::string z;
	while(values.size())
	{
		if (flag == false)
		{
			x = values.top();
			values.pop();
			flag = true;
		}
		y = values.top();
		values.pop();
		z = operands.top();
		operands.pop();
		x = op(x, y, z);
	}
	std::cout << x << std::endl;
}