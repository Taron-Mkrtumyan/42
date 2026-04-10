#ifndef SedIsForLosers_HPP
#define SedIsForLosers_HPP

#include <string>

class SedIsForLosers
{
	public:
		SedIsForLosers(std::string file, std::string s1, std::string s2);
		~SedIsForLosers();
		void replace( void );
	
	private:
		std::string _file;
		std::string	_s1;
		std::string	_s2;
};

#endif