#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Incorrect input" << std::endl;
		return 0;
	}
	else if (std::strlen(argv[2]) == 0)
	{
		std::cout << "search cannot be empty" << std::endl;
		return 0;
	}
	std::ifstream input_file(argv[1]); // char *
	std::string b = argv[1];
	b.erase(b.find_last_of('.'));
	b.append(".replace");
	std::ofstream output_file(b.c_str()); // char *
	if (!(input_file.is_open()) || !(output_file.is_open()))
	{
		std::cout << "dosya acilamadi";
		return (0); // if file not open return 0
	}
	std::string line;
	std::string::size_type len_argv2 = std::strlen(argv[2]);
	std::string::size_type p;
	for (;std::getline(input_file, line);)
	{
		p = line.find(argv[2]);
		while (p != std::string::npos)// find returns npos if it can't find
		{
			output_file << line.substr(0, p);
			output_file << argv[3];
			line = line.substr(p + len_argv2);
			p = line.find(argv[2]);
		}
		output_file << line << std::endl;
	}
	return (0);
}
