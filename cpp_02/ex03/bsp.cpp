#include "Point.hpp"
#include "Fixed.hpp"
#include <cstdlib>
/*
	
*/
bool bsp( Point const p1, Point const p2, Point const p3, Point const p)
{
	Fixed x1 = p1.getPointx();
	Fixed y1 = p1.getPointy();
	Fixed x2 = p2.getPointx();
	Fixed y2 = p2.getPointy();
	Fixed x3 = p3.getPointx();
	Fixed y3 = p3.getPointy();
	Fixed x = p.getPointx();
	Fixed y = p.getPointy();

    // Üçgenin alanına göre Barycentric koordinatları hesaplayın.
  	Fixed const denominator = ((y2 - y3) * (x1 - x3)) + ((x3 - x2) * (y1 - y3));
	// std::cout << "deminoator = "<< "(" << y2 << " - " << y3 << ")" << " * " << "(" << x1 << " - " << x3 << ")" << " + " << "(" << x3 << " - " << x2 << ")" << " * " << "(" << y1 << " - " << y3 << ")" << std::endl;
	// std::cout << "deminoator = " << denominator << std::endl;
	Fixed const lambda1 = (((y2 - y3) * (x - x3)) + ((x3 - x2) * (y - y3))) / denominator;
	// std::cout << "lambda1 = "<< "(" << y2 << " - " << y3 << ")" << " * " << "(" << x << " - " << x3 << ")" << " + " << "(" << x3 << " - " << x2 << ")" << " * " << "(" << y << " - " << y3 << ")" << std::endl;
	// std::cout << "lambda1 = " << lambda1 << std::endl;

    Fixed const lambda2 = (((y3 - y1) * (x - x3)) + ((x1 - x3) * (y - y3))) / denominator;
	// std::cout << "lambda2 = "<< "(" << y3 << " - " << y1 << ")" << " * " << "(" << x << " - " << x3 << ")" << " + " << "(" << x1 << " - " << x3 << ")" << " * " << "(" << y << " - " << y3 << ")" << std::endl;
	// std::cout << "lambda2 = " << lambda2 << std::endl;
    
	Fixed const lambda3 = Fixed(1) - lambda1 - lambda2;
	// std::cout << "lambda3 = " << Fixed(1) << lambda1 << lambda2;
	// std::cout << "lambda3 = " << lambda3 << std::endl;
	
	
	// std::cout << "-----------------------------------------------------" << std::endl;
	// std::cout <<(y2 - y3) << std::endl;
	// std::cout <<(x1 - x3) << std::endl;
	// std::cout <<(x3 - x2) << std::endl;
	// std::cout <<(y1 - y3) << std::endl;

	// std::cout << "-----------------------------------------------------" << std::endl;

	// std::cout << "nokta 1= (" << x1 << "," << y1 << ")" << std::endl;
	// std::cout << "nokta 2= (" << x2 << "," << y2 << ")" << std::endl;
	// std::cout << "nokta 3= (" << x3 << "," << y3 << ")" << std::endl;
	// std::cout << "nokta 4= (" << x << "," << y << ")" << std::endl;



	// std::cout << "detarminotör :" << denominator << std::endl;
	// std::cout << "lamda 1 :" << lambda1 << std::endl;
	// std::cout << "lamda 2 :" << lambda2 << std::endl;
	// std::cout << "lamda 3 :" << lambda3 << std::endl;

	// exit(0);

    // Barycentric koordinatlarının tümü 0 ile 1 arasında olmalıdır.
    return (lambda1 >= Fixed(0) && lambda2 >= Fixed(0) && lambda3 >= Fixed(0));
}

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