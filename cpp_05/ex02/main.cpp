#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("hasan", 4);
		Form b("ali", 1, 1);
		a.promotion(2);
		b.beSinged(a);
		a.singForm(b);
		std::cout << a ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}