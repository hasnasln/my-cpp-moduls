#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl x;
		std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		int i;
		int size = sizeof(levels) / sizeof (levels[0]);
		for (i = 0; i < size; i ++)
		{
			if (argv[1] == levels[i])
				break;
		}
		switch (i)
		{
			case 0:
			{
				x.complain("DEBUG");
				x.complain("INFO");
				x.complain("WARNING");
				x.complain("ERROR");
				break;
			}
			case 1:
			{
				x.complain("INFO");
				x.complain("WARNING");
				x.complain("ERROR");
				break;
			}
			case 2:
			{
				x.complain("WARNING");
				x.complain("ERROR");
				break;
			}
			case 3:
			{
				x.complain("ERROR");
				break;
			}
			default:
			{
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break;
			}
		}
	}
	return (0);
}
