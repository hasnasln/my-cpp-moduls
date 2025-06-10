#include "phone_book.hpp"
#include <iostream> // input/output stream
#include <iomanip> // Input/Output Manipulation
#include <cstdlib> // atoi


/*
iki parametrei kullanımı 
getline(std::istream& is, std::string&str);
is (std::istream&): Giriş akışıdır (örneğin std::cin veya bir dosya akışı olabilir).
	std::istream sınıfından türetilmiş bir nesne olması gerekir.
str (std::string&): Verinin yazılacağı std::string değişkenidir.
	Giriş akışından alınan satır bu string değişkenine kaydedilir.
3. parametre olarak bir charakter alıyor ve bu karakter satır sonu olarak kabul ediliyor. default olarak \n tanımlanmış olabilir.

length
string nesnesi üzerinden çağrılır ve bu nesenin uzunluğunu döner

push_back
string nesnesi üzerinden çağrılı ve nesnenin sonuncu indeksine verilen karakteri ekler

substr
verilen indeksler arasında alt dizi oluşturur

right
bir çıktı maniplatörüdür kullanıldıktan sonra gelen karakterleri sağa yazlı olarak yazar lef ise tam tersi
left
setw
setfill
akış genişliği belirtimiş ise bu genişlik içerisinde kalan boşlukları doldurur.
*/

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_someone(int i)
{
	int index;
	std::string buf;

	index = i;
	
	if (i >= 0)
		i %= 8;

	do
	{
		std::cout << "Enter Name -> ";
		std::getline(std::cin, buf);
	} while (buf == "");
	this->data[i].set_name(buf);

	do
	{
		std::cout << "Enter Surname -> ";
		std::getline(std::cin, buf);
	} while (buf == "");
	this->data[i].set_surname(buf);

	do
	{
		std::cout << "Enter Nickname -> ";
		std::getline(std::cin, buf);
	} while (buf == "");
	this->data[i].set_nickname(buf);

	do
	{
		std::cout << "Enter Number -> ";
		std::getline(std::cin, buf);
		for (int k = 0; buf[k] != '\0'; k++)
		{
			if(!std::isdigit(buf[k]) && buf[k] != ' ')
			{
				buf = "";
				std::cout << "Enter only numbers !" << std::endl;
				break;
			}
		}
	} while (buf == "");
	this->data[i].set_number(buf);

	do
	{
		std::cout << "Enter Darkest Secret -> ";
		std::getline(std::cin, buf);
	} while (buf == "");
	this->data[i].set_darkest_secret(buf);

	std::cout << GREEN_TEXT << "Add Sucsessful No->" << index + 1 << RESET <<std::endl;
}

std::string get_someone(Contact someone, std::string flag)
{
	std::string result;

	if (flag == "Name")
	{
		result = someone.get_name();
		if (result.length() > 10)
		{
			result = result.substr(0,9);
			result.push_back('.');
		}
	}
	else if (flag == "Surname")
	{
		result = someone.get_surname();
		if (result.length() > 10)
		{
			result = result.substr(0,9);
			result.push_back('.');
		}
	}
	else if (flag == "NickName")
	{
		result = someone.get_nickname();
		if (result.length() > 10)
		{
			result = result.substr(0,9);
			result.push_back('.');
		}
	}
	return (result);
}

void PhoneBook::search_someone(int i)
{
	int no;
	bool flag = false;
	std::string string_no;

	no = 0;
	if (i >= 8)
	{
		flag = true;
		i = 7;
	}
	if (i == 0)
		std::cout << RED_TEXT <<"Error: List is emty. Add someone (ADD)" << RESET << std:: endl;
	else
	{
		std::cout << std::right << std::setw(45) << std::setfill('-') << "-" << std::endl;
		std::cout << std::setfill(' ')
				<< std::setw(10) << "No"
				<< "|"
				<< std::setw(10) << "Name"
				<< "|"
				<< std::setw(10) << "Surname"
				<< "|"
				<< std::setw(10) << "NickName"
				<< std::endl;
		std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl;
		if (flag)
			i++;
		for (int j = 0; j < i; j++)
		{
			std::cout << std::setfill(' ')
				<< std::setw(10) << j + 1
				<< "|"
				<< std::setw(10) << get_someone(data[j],"Name")
				<< "|"
				<< std::setw(10) << get_someone(data[j], "Surname")
				<< "|"
				<< std::setw(10) << get_someone(data[j], "NickName")
				<< std::endl;
			std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl;
		}
		std::cout << "Choice someone NO: " << std::endl << " -> ";
		std::getline(std::cin, string_no);
		no = atoi(string_no.c_str());
		if (no > 8 || no < 1)
			std::cout << "Invalid number entry, you are redirected to the beginning !" << std::endl;
		else
		{
			std::cout << std::left << std::setfill('-') << std::setw(15) << "Name " << "> " << data[no - 1].get_name() << std::endl;
			std::cout << std::left << std::setfill('-') << std::setw(15) << "Surname " << "> " << data[no - 1].get_surname() << std::endl;
			std::cout << std::left << std::setfill('-') << std::setw(15) << "Nick Name " << "> " << data[no - 1].get_nickname() << std::endl;
			std::cout << std::left << std::setfill('-') << std::setw(15) << "Number " << "> " << data[no - 1].get_number() << std::endl;
			std::cout << std::left << std::setfill('-') << std::setw(15) << "Dark Secret " << "> " << data[no - 1].get_darkest_secret() << std::endl;
		}
	}
}