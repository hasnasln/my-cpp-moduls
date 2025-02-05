#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2 || std::string(argv[1]).empty())
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

/*
20

Bu biraz kafa karıştırıcı olabilir, ancak ikili sayı sistemindeki ondalık basamaklar iki'nin kuvvetlerinin karşılıklılarını temsil eder (örneğin, sırasıyla birinci, ikinci, üçüncü ve dördüncü ondalık basamak için 1/2, 1/4, 1/8, 1/16) tıpkı ondalıktaki ondalık basamakların onun ardışık kuvvetlerinin karşılıklılarını temsil etmesi gibi.

Sorunuzu cevaplamak için, 1/10'a ulaşmak için iki'nin kuvvetlerinin hangi karşılıklılarının toplanması gerektiğini bulmanız gerekir. Örneğin:

1/16 + 1/32 = 0,09375, ki bu 1/10'a oldukça yakın. 1/64'ü eklemek bizi daha da yukarılara götürür, 1/128 de öyle. Ancak, 1/256 bizi daha da yakınlaştırır. Yani:

0.00011001 ikili = 0.09765625 ondalık, bu da sorduğunuza yakın.

Daha fazla rakam eklemeye devam edebilirsiniz; böylece cevap 0.00011001... olur.
*/