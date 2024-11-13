#include <iostream>

int main()
{
	int i;
	float f = 1.234;

	// folat sayıyı saklarken 256 ile çarpıp saklıyoruz.
	i = f * 256 + 0.5f; // bu sayı eski halide istediğimizde ise bölerek elde ediyoruz
	std::cout << i << std::endl;
	int a = i / 256;
	float f2 = (float)i / (float)256 ;
	std::cout << a << std::endl << f2 << std::endl;
}