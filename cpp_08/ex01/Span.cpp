#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span()
{}

Span::Span(unsigned int N): _N(N), _datalen(0)
{
}

Span::~Span() {}

Span Span::operator=(const Span& other)
{
	return other;
}

Span::Span(const Span& other)
{
	_N = other._N;
}


void Span::addNumber(int value)
{
	if (_datalen == _N)
		throw AlredyHaveNvalue();
	data.push_back(value);
	_datalen++;
}

int Span::shortestSpan()
{
	int tmp = 1000000;
	if (_N == 0)
		throw DontHaveValue();
	if (_N == 1)
		throw HaveOneValue();
	std::sort(data.begin(), data.end());
	std::vector<int>::iterator it;
	for(it = data.begin(); it++ != data.end(); it++)
	{
		if (*it - *(it++) < tmp )
			tmp = *it - *(it++);
		std::cout << *it << std::endl;
	}
	return *it;
}

int Span::longestSpan()
{
	if (_N == 0)
		throw DontHaveValue();
	if (_N == 1)
		throw HaveOneValue();
	std::sort(data.begin(), data.end());
	std::vector<int>::iterator it;
	for(it = data.begin(); it != data.end(); it++)
		std::cout << *it << std::endl;
	return *it;
}


// 1 8 7 9 2 5 8 3