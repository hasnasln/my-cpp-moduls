#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;

	/*---------------------------------*/
	Fixed c(-38);
	Fixed c2(-30);
	Fixed a6 = c / c2;
	Fixed a5((c / c2));
	std::cout << a6.getRawBits() << std::endl;
	std::cout << a5 << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}