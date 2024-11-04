#ifndef CONTACT_H
# define CONTACT_H


#include <iostream> // input / output strean
#include <iomanip> // input /output maniplasyon
//

// color text
#define RED_TEXT        "\033[31m"
#define GREEN_TEXT      "\033[32m"
#define YELLOW_TEXT     "\033[33m"
#define BLUE_TEXT       "\033[34m"
#define MAGENTA_TEXT    "\033[35m"
#define CYAN_TEXT       "\033[36m"

// color backgraund
#define BLACK_BG        "\033[40m"
#define RED_BG          "\033[41m"
#define GREEN_BG        "\033[42m"
#define YELLOW_BG       "\033[43m"
#define BLUE_BG         "\033[44m"
#define MAGENTA_BG      "\033[45m"
#define CYAN_BG         "\033[46m"
#define WHITE_BG        "\033[47m"

// reset
#define RESET           "\033[0m"

class Contact
{
	public:
		void		set_name(std::string);
		void		set_surname(std::string);
		void		set_nickname(std::string);
		void		set_number(std::string);
		void		set_darkest_secret(std::string);
		std::string	get_name();
		std::string	get_surname();
		std::string	get_nickname();
		std::string	get_number();
		std::string	get_darkest_secret();

	private:
		std::string name;
		std::string surname;
		std::string nickname;
		std::string number;
		std::string darkest_secret;
};

#endif
