#include <iostream>
#include "whatever.hpp"


int main( void ) 
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

/*
Template Nedir?
Template, bir genel kalıp (şablon) oluşturarak, farklı veri türleriyle çalışabilen fonksiyonlar veya sınıflar yazmamızı sağlar.

Eğer bir fonksiyon/sınıf farklı veri türleriyle çalışıyorsa, template kullanmak gereksiz kod tekrarını önler.
Derleme sırasında, template çağrıldığında, kullanılan veri türüne göre gerçek bir fonksiyon/sınıf oluşturulur.
*/