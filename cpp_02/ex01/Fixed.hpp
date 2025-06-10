#ifndef Fixed_HPP
# define Fixed_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		/*--ex01--*/
		Fixed(const int num);
		Fixed(const float num);
		float	toFloat(void)	const;
		int		toInt(void)	const;

	private:
		int	_x;
		static const int _y = 8;
};

std::ostream& operator<<(std::ostream &os, Fixed const &num);

#endif