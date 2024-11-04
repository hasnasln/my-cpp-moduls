/*--------------------------Contact--------------------------------------*/
#include "contact.hpp"

// set functions
void	Contact::set_name(std::string name = "Girilmedi") // herhangi bir şey girilmediği zaman dfault olarak tanımlayabiliyoruz
{
	this->name = name;
}
void	Contact::set_surname(std::string surname = "Girilmedi")
{
	this->surname = surname;
}
void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}
void	Contact::set_number(std::string number)
{
	this->number = number;
}
void	Contact::set_darkest_secret(std::string secret)
{
	this-> darkest_secret= secret;
}


// get functions
std::string Contact::get_name()
{
	return this->name;
}
std::string Contact::get_surname()
{
	return this->surname;
}
std::string Contact::get_nickname()
{
	return this->nickname;
}
std::string Contact::get_number()
{
	return this->number;
}
std::string Contact::get_darkest_secret()
{
	return this->darkest_secret;
}
