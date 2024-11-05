#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// 3 tane parametre alıyor
// 1. paramtere dosya adı
// 2. parametre x
// 3. parametre y
// girilne dosyadaki x leri y ile değiştirip yeni bir dosyaya yaz

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Hatali girdi" << std::endl;
		return 0;
	}
	std::ifstream input_file(argv[1]);
	std::string b = argv[1];
	b.append(".replace");
	std::ofstream ouput_file(b.c_str()); // char * istiyor
	
	if (!(input_file.is_open()) || !(ouput_file.is_open()))
		std::cout << "dosya acilamadi";
	
	std::string line;
	std::string::size_type len_argv2 = std::strlen(argv[2]);
	std::string::size_type p;
	for (;std::getline(input_file, line);)
	{
		p = line.find(argv[2]);
		while (p != std::string::npos)
		{
			ouput_file << line.substr(0, p);
			ouput_file << argv[3];
			line = line.substr(p + len_argv2);
			p = line.find(argv[2]);
		}
		ouput_file << line << std::endl;
	}
	return (0);
}
