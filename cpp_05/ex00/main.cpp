#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("hasan", 4);
		a.promotion(1);
		std::cout << a ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}