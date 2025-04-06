#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>

Btc::Btc(){}

Btc::~Btc() {}

Btc::Btc(const Btc& other): _data(other._data) {}

Btc& Btc::operator=(const Btc& other)
{
	if(this != &other)
		_data = other._data;
	return *this;
}

Btc::Btc(std::string data_path)
{
	std::ifstream data_file(data_path.c_str());
	if (!data_file)
		throw DataFileNotOpen();
	std::string line;
	std::getline(data_file, line);
	while(std::getline(data_file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw DataFileNotOpen();
		_data[line.substr(0, pos)] = atof((line.substr(pos + 1).c_str()));
	}
	data_file.close();
}

std::string trim(std::string str){
	size_t start = 0;
	size_t end = str.length();
	for (; start < str.length() && std::isspace(str[start]); ++start);
	for (; end > start && std::isspace(str[end -1]); --end);
	return str.substr(start, end - start);
}

void trim(std::string &str, char value) {
	size_t start = 0;
	size_t end = str.length();
	for (; start < str.length() && str[start] == value; start++);
	for (; end > start && str[end - 1] == value; end--);
	str = str.substr(start, end - start);
}

bool check_date(std::string date)
{
	int year, month, day;
	char f, s;
	std::stringstream x(date);
	x >> year >> f >> month >> s >> day;
	
	if (f != '-' || s != '-') {
		std::cerr << "Error: Invalid date format. Use YYYY-MM-DD." << std::endl;
		return false;
	}
	
	if (year < 2009) {
		std::cerr << "Error: Year must be 2009 or later." << std::endl;
		return false;
	}
	
	if (month < 1 || month > 12) {
		std::cerr << "Error: Month must be between 01 and 12." << std::endl;
		return false;
	}
	
	if (day < 1 || day > 31) {
		std::cerr << "Error: Day must be between 01 and 31." << std::endl;
		return false;
	}
	
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		std::cerr << "Error: This month only has 30 days." << std::endl;
		return false;
	}
	
	if (month == 2) {
		if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
			if (day > 29) {
				std::cerr << "Error: February only has 29 days in leap years." << std::endl;
				return false;
			}
		} else if (day > 28) {
			std::cerr << "Error: February only has 28 days this year." << std::endl;
			return false;
		}
	}
	
	return true;
}

bool check_value(std::string input)
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
			return false;
	}
	double x = atof(input.c_str());
	if (x < 0.0)
	{
		std::cerr << "Error: not a postive number." << std::endl;
		return false;
	}
	if (x > 1000.0)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void Btc::calculateBitcoinValue(std::string date, std::string value)
{
	std::map<std::string, float>::iterator it = _data.find(date);
	if (it == _data.end())
	{
		it = _data.lower_bound(date);
		if (it == _data.end())
			std::cout << "tarih bulunamadi" << std::endl;
		/*lower_bound() ve upper_bound()*/
		std::cout << date << " => " << it->second << " = " << it->second * std::atof(value.c_str()) << std::endl;
	}
	else
	{
		std::cout << date << " => " << _data[date] << " = " << _data[date] * std::atof(value.c_str()) << std::endl;
	}
}

void Btc::parseExchangeInput(std::string arv_path)
{
	std::string line;
	std::string date;
	std::string value;
	int position;
	bool flag;

	std::ifstream arg_file(arv_path.c_str());
	if (!arg_file)
		throw ArgFileNotOpen();
	std::getline(arg_file, line);
	if (line != "date | value")
	{
		std::cerr << "Error: wront type input-> date | value" << std::endl;
		return;
	}
	while(std::getline(arg_file, line))
	{
		trim(line);
		flag = !(line.find('|') == std::string::npos);
		if (flag)
		{
			position = line.find('|');
			date = trim(line.substr(0, position));
			value = trim(line.substr(position + 1));
		}
		if (!flag || !check_date(date) || !check_value(value))
		{
			if (!flag)
				std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		calculateBitcoinValue(date, value);
	}
}

/*--------------Exceptions------------------*/

const char* Btc::DataFileNotOpen::what() const throw()
{
	return "Data File Not Open";
}

const char* Btc::ArgFileNotOpen::what() const throw()
{
	return "Arg file not open";
}