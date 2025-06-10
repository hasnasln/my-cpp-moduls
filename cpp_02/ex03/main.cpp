#include "Point.hpp"


int main ()
{
	Point a(2,2);
	Point b(5,7);
	Point c(8,2);
	Point x(5,2);
	Point x1(5,3);
	Point x2(1,1);
	Point x3(9,5);


	std::cout << bsp(a,b,c,x) << std::endl;
	std::cout << bsp(a,b,c,x1) << std::endl;
	std::cout << bsp(a,b,c,x2) << std::endl;
	std::cout << bsp(a,b,c,x3) << std::endl;

}