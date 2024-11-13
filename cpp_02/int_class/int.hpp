#ifndef INT_HPP
# define INT_HPP

#include <iostream>

class Hasan
{
	public:
		Hasan(void);					// Defaul constructure
		Hasan(int value);				// Constructure
		~Hasan(void);					// Default destructure
		Hasan(const Hasan& other);		// copy constructure
		
		int getValue(void) const; // bu const nestneler üzerinden çağrılabilir
		void setValue(int value);

		Hasan operator+(const Hasan& left);
		Hasan operator-(const Hasan& left);
		Hasan operator*(const Hasan& left);
		Hasan operator/(const Hasan& left);

		bool operator<(const Hasan& left);
		bool operator>(const Hasan& left);
		bool operator<=(const Hasan& left);
		bool operator>=(const Hasan& left);
		bool operator!=(const Hasan& left);
		bool operator==(const Hasan& left);

		Hasan operator++();
		Hasan operator--();
		Hasan operator++(int);
		Hasan operator--(int);

	private:
		int _value;
};

// std::ostream operator<<(std::ostream& left, const Hasan& right);

#endif