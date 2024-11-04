#include <iostream> // input/output stream
#include <iomanip> // Input/Output Manipulation
#include "phone_book.hpp"
/*
earse: ?
stirng  üzerinden kullanılnca verilen indeksler arasını siler
ikinci parametre boş verilirse ilk paramtreden sona kadar siler

find_first_not_of: ?
find_last_not_of: ?


eof()
*/
void    welcome_my_phone_book();

int main()
{
	std::string buf;
	std::string coppy;
	PhoneBook book;
	int i = 0;

	welcome_my_phone_book();
	do
	{
		std::cout << "Pls Enter One Choise\n -> ";
		std::getline(std::cin, buf);
		if (std::cin.eof()) // EOF
		{
			std::cout << RED_TEXT << "Error: EOF" << RESET << std::endl;
			break;
		}
		buf.erase(0, buf.find_first_not_of(" "));
		buf.erase(buf.find_last_not_of(" ") + 1);
		if (buf == "ADD")
		{
			book.add_someone(i);
			i++;
		}
		else if (buf == "SEARCH")
			book.search_someone(i);
		else if (buf != "EXIT")
			std::cout << RED_TEXT << "Error: A Choice that doesn't exist" << RESET << std::endl;
	}while (buf != "EXIT");
}

void	welcome_my_phone_book()
{
	std::cout << std::setw(50) << std::left << "----------------------------------------------" << std::endl;
	std::cout << std::setw(50) << "|  Welcome Phone Book                        |" << std::endl;
	std::cout << std::setw(50) << "|  Have 3 Options:                           |" << std::endl;
	std::cout << std::setw(50) << "|  1.ADD (Add any one to Phone Book)         |" << std::endl;
	std::cout << std::setw(50) << "|  2.SEARCH (SERCH any one to Phone Book)    |" << std::endl;
	std::cout << std::setw(50) << "|  1.EXIT (Close and Delete Phone Book)      |" << std::endl;
	std::cout << std::setw(50) << "----------------------------------------------" << std::endl;
}