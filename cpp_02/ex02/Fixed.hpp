#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed& other);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		/*--ex01--*/
		Fixed(const int num);
		Fixed(const float num);
		float	toFloat(void)	const;
		int		toInt(void)	const;
		/*--ex02--*/
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);

		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static Fixed& min(Fixed &num1, Fixed &num2);
		static Fixed& max(Fixed &num1, Fixed &num2);
		static const Fixed& min(Fixed const &num1, Fixed const &num2);
		static const Fixed& max(Fixed const &num1, Fixed const &num2);

	private:
		int	_x;
		static const int _y = 8;
};

std::ostream& operator<<(std::ostream &os, Fixed const &num);

#endif