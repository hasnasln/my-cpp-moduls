#include "Harl.hpp"


void Harl::debug( void ){
	std::cout << "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastır-" <<
	"ması yemeyi seviyorum. Gerçekten seviyorum!" << std::endl;
}
void Harl::info( void ){
	std::cout <<  "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıy-" <<
		"orum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını iste-"<<
		"mezdim!" << std::endl;
}
void Harl::warning( void ){
	std::cout << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum. Ben yıllardır"<<
			"geliyorum, sen geçen aydan beri burada çalışmaya başladın." << std::endl;
}
void Harl::error( void ){
	std::cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << std::endl;
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
	std::cout << "Tanimsiz bir girdi" << std::endl;
}

