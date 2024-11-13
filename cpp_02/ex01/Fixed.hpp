#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		// ex01
		Fixed(const int number);
		Fixed(const float number);
		float toFloat(void) const;
		int toInt(void) const;
	private:
		int					_x; // sabit noktalı sayı değerini depolamak için
		static const int	_y = 8; // kesirli bitlerin sayısını depolamak için her zaman 8 olacaktır
};

std::ostream& operator<<(std::ostream &os, Fixed const &a);

#endif