#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _fracBits = 8;

	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const n);
		Fixed(Fixed const & other);
		~Fixed();

		Fixed & operator=(Fixed const & other);

		bool operator>(Fixed const & other) const;
		bool operator<(Fixed const & other) const;
		bool operator>=(Fixed const & other) const;
		bool operator<=(Fixed const & other) const;
		bool operator==(Fixed const & other) const;
		bool operator!=(Fixed const & other) const;

		Fixed operator+(Fixed const & other) const;
		Fixed operator-(Fixed const & other) const;
		Fixed operator*(Fixed const & other) const;
		Fixed operator/(Fixed const & other) const;

		Fixed & operator++();
		Fixed operator++(int);
		Fixed & operator--();
		Fixed operator--(int);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed & min(Fixed & f1, Fixed & f2);
		static const Fixed & min(Fixed const & f1, Fixed const & f2);
		static Fixed & max(Fixed & f1, Fixed & f2);
		static const Fixed & max(Fixed const & f1, Fixed const & f2);
};

std::ostream & operator<<(std::ostream & out, Fixed const & instance);

#endif