#ifndef HARL_HPP
#define HARL_HPP

#include <string>

#define DEBUG_MESSAGE "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define INFO_MESSAGE "I think I deserve to have some extra bacon for free."
#define WARNING_MESSAGE "I am warning you! Extra bacon will cost you extra money."
#define ERROR_MESSAGE "This is unacceptable! I want to speak to the manager now."

class	Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl();
		~Harl();
		void complain( std::string level );
};

#endif