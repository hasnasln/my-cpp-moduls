#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <map>
#include <string>

class Btc
{
	public:
		Btc();
		~Btc();
		Btc(const Btc& other);
		Btc& operator=(const Btc& other);
		Btc(std::string data_path);
		void parseExchangeInput(std::string arv_path);
		void calculateBitcoinValue(std::string date, std::string value);

		class DataFileNotOpen : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class ArgFileNotOpen : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		std::map<std::string, float> _data;
};

#endif //BITCOINEXCHANGE_HPP