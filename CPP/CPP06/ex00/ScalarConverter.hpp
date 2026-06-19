#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & rhs); 
		virtual ~ScalarConverter() = 0;									//prevent instantiation

		static void convert(std::string const & literal);
};

enum e_literal_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL
};

#define BOLD_CRIMSON "\033[1m\033[38;2;220;20;60m"
#define RESET "\033[0m"

#endif