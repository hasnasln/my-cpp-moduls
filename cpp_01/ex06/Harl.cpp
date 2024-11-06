#include "Harl.hpp"


void Harl::debug( void ){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void ){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put " <<
		"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void ){
	std::cout <<	"I think I deserve to have some extra bacon for free. I’ve been coming for "<<
					"years whereas you started working here since last month." << std::endl;
}
void Harl::error( void ){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	// typedef void (Harl::*y)();    -> y adında bir fonsiyon işaretcisi oluşturdum bunun üzerinden de kullanılabilir 

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*x[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int size = sizeof(levels) / sizeof(levels[0]);
	for (int i = 0; i < size; i++)
	{
		if (levels[i] == level)
		{
			std::cout << "[" << level << "]" << std::endl;
			(this->*x[i])();
			return;
		}
	}
	std::cout << "Undefined input" << std::endl;
}

