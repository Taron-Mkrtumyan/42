#ifndef FIXED_HPP
#define FIXED_HPP

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
		Fixed & operator=(Fixed const & other);
		~Fixed();
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & out, Fixed const & instance);

#endif