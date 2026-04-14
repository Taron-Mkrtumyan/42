#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int _value;
		static const int _fracBits = 8;
		
	public:
		Fixed();
		Fixed(Fixed const & other);
		Fixed & operator=(Fixed const & other);
		~Fixed();
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif