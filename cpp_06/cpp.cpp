#include <iostream>

int main ()
{
	int a = 65;
	int *ptr = &a;
	char *ali = reinterpret_cast<char *>(ptr);
	std::cout << ali << std::endl;
}