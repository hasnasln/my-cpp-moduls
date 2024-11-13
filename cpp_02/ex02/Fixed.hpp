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
		// ex02
		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);
		
		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		
		bool operator>(const Fixed& a) const;
		bool operator<(const Fixed& a) const;
		bool operator<=(const Fixed& a) const;
		bool operator>=(const Fixed& a) const;
		bool operator==(const Fixed& a) const;
		bool operator!=(const Fixed& a) const;

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);


	private:
		int					_x; // sabit noktalı sayı değerini depolamak için
		static const int	_y = 8; // kesirli bitlerin sayısını depolamak için her zaman 8 olacaktır
};

std::ostream& operator<<(std::ostream &os, Fixed const &a);

#endif