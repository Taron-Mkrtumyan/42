#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>


bool			is_valid_literal(std::string const & literal);
e_literal_type	get_literal_type(std::string const & literal);
double			parse_literal(std::string const & literal);
void			print_conversions(double value);
void			print_special(std::string const & literal);

ScalarConverter::ScalarConverter() { return ; }
ScalarConverter::ScalarConverter(ScalarConverter const & other) { (void)other; return ; }
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() { return ; }



void	ScalarConverter::convert(std::string const & literal)
{
	if (!is_valid_literal(literal))
	{
		std::cerr << BOLD_CRIMSON << "Error: Empty or invalid literal" << RESET << std::endl;
		return ;
	}
	
	try
	{
		e_literal_type type = get_literal_type(literal);
		
		if (type == SPECIAL)
			print_special(literal);
		else if (type == CHAR)
		{
			if (!std::isprint(literal[0]))
			{
				std::cout << "char: Non displayable" << std::endl;
			}
			else
			{
				std::cout << "char: '" << literal[0] << "'" << std::endl;
			}
			std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
		}
		else
		{
			double value = parse_literal(literal);
			print_conversions(value);
		}
	}
	catch(std::exception const & e)
	{
		std::cout	<< "char: impossible\n" 
					<< "int:  impossible\n"
					<< "float: impossible\n"
					<< "double: impossible"
					<< std::endl;
	}
	
	return ;
}


void	print_special(std::string const & literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	std::ptrdiff_t count = std::count(literal.begin(), literal.end(), 'f');
	switch (count)
	{
		case 0:
			std::cout << "float: " << literal << 'f' << std::endl;
			std::cout << "double: " << literal << std::endl;
			break;
		case 1:
			if (literal == "nanf")
			{
				std::cout << "float: " << literal << std::endl;
				std::cout << "double: " << "nan" << std::endl;
			}
			else
			{
				std::cout << "float: " << literal << 'f' << std::endl;
				std::cout << "double: " << literal << std::endl;
			}
			break;
		case 2:
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
		default:
			break;
	}

	return ;
}


bool inline is_ascii(int c)
{
	return ( c >= 0 && c <= 127 );
}


void	print_char(double value)
{
	if (value < 0 || value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible\n";
	}
	else if (!std::isprint(static_cast<char>(value)))
	{
		std::cout << "char: Non displayable\n";
	}
	else
	{
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}


void	print_int(double value)
{
	if (value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void	print_conversions(double value)
{
	int intValue = static_cast<int>(value);

	print_char(value);
	print_int(value);

	if (value >  std::numeric_limits<float>::max() || 
		value < -std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		if (intValue == static_cast<float>(value))
			std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
		else
		{
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		}
	}

	if (intValue == value)
		std::cout << "double: " << value << ".0" << std::endl;
	else
		std::cout << "double: " << value << std::endl;

	return ;
}


bool inline is_special_literal(std::string const & literal)
{
	return (literal == "nan"  || literal == "-inf"  || literal == "+inf"  || literal == "inf" || 
		    literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "inff");
}


bool is_valid_literal(std::string const & literal)
{
	if (literal.empty())
		return (false);
	if (is_special_literal(literal))
		return (true);
	if (literal.size() == 1 && is_ascii(literal[0]))
		return (true);

	bool has_decimal = false;
	bool has_digit = false;
	bool has_sign = false;

	for (size_t i = 0; i < literal.size(); i++)
	{
		if (std::isdigit(literal[i]))
		{
			has_digit = true;
		}
		else if (i == 0 and (literal[i] == '+' || literal[i] == '-'))
		{
			if (has_sign || has_decimal)
				return (false);
			has_sign = true;
		}
		else if (literal[i] == '.')
		{
			if (has_decimal)
				return ( false );
			has_decimal = true;
		}
		else if (literal[i] == 'f' && i == literal.size() - 1)
			continue;
		else
			return (false);
	}
	return ( has_digit );
}


double	parse_literal(std::string const & literal)
{
	std::stringstream	ss(literal);
	double				res;

	ss >> res;
	if (ss.fail())
		throw std::runtime_error("Error: failed to parse literal");

	return (res);
}


e_literal_type get_literal_type(std::string const & literal)
{
	if (is_special_literal(literal))
		return (SPECIAL);

	if (literal.size() == 1 && !std::isdigit(literal[0]))
		return (CHAR);

	if (literal.find('.') != std::string::npos)
	{
		if (literal[literal.size() - 1] == 'f')
			return (FLOAT);
		return (DOUBLE);
	}
	return (INT);
}
