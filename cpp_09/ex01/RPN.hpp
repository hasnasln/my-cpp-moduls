#ifndef RPN_HPP
# define RPN_HPP

#include <exception>
#include <iostream>
#include <stack>

class RPN
{
	public:
		RPN(std::string arg);
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();
		void calculateResult();
		int flag;
	private:
		std::stack<std::string> _data;
};

#endif // RPN_HPP
