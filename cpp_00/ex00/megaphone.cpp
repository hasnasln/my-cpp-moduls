#include <iostream> // input output strean -> girdi çıktı akışı

/*
İsim Uzayı (Namespace) Nedir?
İsim uzayı (namespace), C++ dilinde isim çakışmalarını önlemek için kullanılan
bir yapılandırmadır. Farklı kod parçalarında aynı isimde fonksiyonlar, değişkenler
ya da sınıflar olabileceği için, bunları ayırt etmek amacıyla isim uzayları kullanılır.
İsim uzayları, aynı isimdeki sembollerin (fonksiyon, değişken, sınıf vb.) farklı kod
bloklarında bağımsız şekilde kullanılmasına olanak tanır.
*/

/*
cout -> console output
<< insetion opreator -> çıktı yönlendirme
:: -> scope resolution operator ( kapsam çözümleme operatörü) belirli bir adın hangi isim uzayında olduğunu belirtir.
*/
int main(int argc, char **argv)
{
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i = 1; argv[i] != NULL; i++)
		{
			for(int j = 0; argv[i][j] != '\0'; j++)
				std::cout << (char)std::toupper(argv[i][j]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}