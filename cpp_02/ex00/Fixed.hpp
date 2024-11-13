#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& other);		// copy constructure
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int					_x;			// sabit noktalı sayı değerini depolamak için
		static const int	_y = 8;		// kesirli bitlerin sayısını depolamak için her zaman 8 olacaktır
};

#endif