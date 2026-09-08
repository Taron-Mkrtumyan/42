#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include <map>

#define BOLD_CRIMSON	"\033[1;31m"
#define BOLD_GREEN		"\033[1;32m"
#define BOLD_YELLOW		"\033[1;33m"
#define BOLD_CYAN		"\033[1;36m"
#define RESET			"\033[0m"

#define WRONG_ARGUMENTS_MESSAGE		"" BOLD_CRIMSON	"Error: Please provide a single argument." RESET
#define HELP_MESSAGE				"" BOLD_CYAN	"try " BOLD_YELLOW "'./btc help' " BOLD_CYAN "for more information." RESET
#define	USAGE_MESSAGE 				"" BOLD_GREEN	"Usage: ./btc <database_path>" RESET
#define	CSV_MESSAGE					"" BOLD_CYAN	"Database should have lines in the following format:"	BOLD_YELLOW	" \"date | value\"" BOLD_CYAN "." RESET
#define	VALID_DATE_MESSAGE			"" BOLD_CYAN	"A valid date format: "	BOLD_YELLOW	"Year-Month-Day"	BOLD_CYAN	"." RESET
#define	VALID_VALUE_MESSAGE			"" BOLD_CYAN	"A valid value should be a number between "	BOLD_YELLOW	"0-1000"	BOLD_CYAN	"." RESET
#define WRONG_LINE_FORMAT_MESSAGE	"" BOLD_CRIMSON "Error: Wrong line format. (should be \"date | value\")" RESET
#define WRONG_DATE_FORMAT_MESSAGE	"" BOLD_CRIMSON "Error: Wrong date format. (should be \"Year-Month-Day\")" RESET

#define WRONG_VALUE_MESSAGE			"" BOLD_CRIMSON "Error: Wrong value (not 0-1000): " RESET
#define NO_DELIMITER_MESSAGE		"" BOLD_CRIMSON "Error: No delimiter: " RESET
#define BAD_INPUT_MESSAGE			"" BOLD_CRIMSON "Error: Bad input: " RESET
#define WRONG_DATE_DAY_MESSAGE		"" BOLD_CRIMSON "Error: Wrong date (day): " RESET
#define WRONG_DATE_MONTH_MESSAGE	"" BOLD_CRIMSON "Error: Wrong date (month): " RESET
#define WRONG_DATE_YEAR_MESSAGE		"" BOLD_CRIMSON "Error: Wrong date (year): " RESET
#define WRONG_LINE_LENGTH_MESSAGE	"" BOLD_CRIMSON "Error: Wrong line length: " RESET

#define CSV_FILENAME "data.csv"


enum LINE_ERRORS
{
	NO_ERROR,
	WRONG_DATE_YEAR,
	WRONG_DATE_MONTH,
	WRONG_DATE_DAY,
	WRONG_VALUE,
	WRONG_LINE_LENGTH,
	NO_DELIMITER,
	BAD_INPUT
};



void printErrorMessage(std::string const & message, std::ostream & stream)
{
	stream << message << std::endl;
	usleep(500000);
}


void cout_error_message(std::string const & message)
{
	std::cout << message;
}


void print_line_error(std::string const & line, LINE_ERRORS error)
{
	switch (error)
	{
		case WRONG_DATE_YEAR:
			cout_error_message(WRONG_DATE_YEAR_MESSAGE);
			break;
		case WRONG_DATE_MONTH:
			cout_error_message(WRONG_DATE_MONTH_MESSAGE);
			break;
		case WRONG_DATE_DAY:
			cout_error_message(WRONG_DATE_DAY_MESSAGE);
			break;
		case WRONG_VALUE:
			cout_error_message(WRONG_VALUE_MESSAGE);
			break;
		case WRONG_LINE_LENGTH:
			cout_error_message(WRONG_LINE_FORMAT_MESSAGE);
			break;
		case NO_DELIMITER:
			cout_error_message(NO_DELIMITER_MESSAGE);
			break;
		case BAD_INPUT:
			cout_error_message(BAD_INPUT_MESSAGE);
			break;
		default:
			break;
	}

	std::cout << line << std::endl;

	return ;
}



std::map <std::string, double> get_database(std::string const & filename, char delimiter)
{
	std::map <std::string, double> database;
	std::ifstream file(filename.c_str());

	if (!file)
		throw std::runtime_error("Could not open file");

	std::string line;
	std::getline(file, line); // Skip header

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string key;
		double value;
		if (!std::getline(ss, key, delimiter) || !(ss >> value))
		{
			continue;
		}
		database[key] = value;
	}
	return (database);
}



double get_closest_date_value(std::map<std::string, double> const & database, std::string const & date)
{
	std::map<std::string, double>::const_iterator it = database.lower_bound(date);
	if (it == database.end())
		--it;

	if (it == database.begin())
	{
		throw std::runtime_error("No earlier date found in the database: " RESET + date);
	}

	return (it->second);
}



double stod_cpp98(std::string const & str)
{
    std::stringstream ss(str);
    double result;
    ss >> result;

	if (ss.fail())
	{
		throw std::runtime_error("Invalid double: " + str);
	}

    return result;
}



bool char_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}



bool is_valid_value(std::string const & value)
{
	for (size_t i = 0; i < value.size(); ++i)
	{
		if (!char_is_digit(value[i]) && value[i] != '.')
			return (false);
	}
	try
	{
		double val = stod_cpp98(value);
		if (val < 0 || val > 1000)
			return (false);
	}
	catch (std::exception & e)
	{
		return (false);
	}

	return (true);
}



int stoi_cpp98(std::string const & str)
{
    std::stringstream ss(str);
    int result;
    ss >> result;

	if (ss.fail())
	{
		throw std::runtime_error("Invalid integer: " + str);
	}

    return result;
}



bool is_leap_year(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}


int days_in_month(int year, int month)
{
    static int days[] = 
	{
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2 && is_leap_year(year))
        return 29;

    return (days[month - 1]);
}



LINE_ERRORS is_valid_date(std::string const & date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (BAD_INPUT);

	try
	{
		int year = stoi_cpp98(date.substr(0, 4));
		int month = stoi_cpp98(date.substr(5, 2));
		int day = stoi_cpp98(date.substr(8, 2));

		if (year < 2009 || year > 2026)
			return (WRONG_DATE_YEAR);
		if (month < 1 || month > 12)
			return (WRONG_DATE_MONTH);
		if (day < 1 || day > days_in_month(year, month))
			return (WRONG_DATE_DAY);
	}
	catch (std::exception & e)
	{
		return (BAD_INPUT);
	}

	return (NO_ERROR);
}



LINE_ERRORS is_valid_line(std::string const & line, std::string const & delimiter)
{
	if(line.size() < 12)
		return (BAD_INPUT);

	std::size_t pos = line.find(delimiter);
	if (pos == std::string::npos)
		return (NO_DELIMITER);

	std::string date = line.substr(0, pos);
	std::string value = line.substr(pos + delimiter.length());

	if (!is_valid_value(value))
		return (WRONG_VALUE);

	return (is_valid_date(date));
}



int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << std::endl;

		printErrorMessage(WRONG_ARGUMENTS_MESSAGE,	std::cerr);
		printErrorMessage(HELP_MESSAGE,				std::cerr);

		std::cout << std::endl;
		return (1);
	}
	if  (std::string(av[1]) == "help")
	{
		std::cout << std::endl;

		printErrorMessage(USAGE_MESSAGE,		std::cout);
		printErrorMessage(CSV_MESSAGE,			std::cout);
		printErrorMessage(VALID_DATE_MESSAGE,	std::cout);
		printErrorMessage(VALID_VALUE_MESSAGE,	std::cout);

		std::cout << std::endl;
		return (0);
	}
	try
	{
		std::ifstream file(av[1]);
		if (!file)
		{
			std::cerr << BOLD_CRIMSON "Error: Could not open file '" << av[1] << "'." RESET << std::endl;
			return (1);
		}

		std::string line;
		std::getline(file, line);
		int line_size = line.size();
		if (line_size < 10 || line.substr(0, 4) != "date" || line.substr(line_size - 5) != "value")
		{
			std::cerr << BOLD_CRIMSON "Error: Invalid header format. Expected 'date | value'." RESET << std::endl;
			return (1);
		}

		std::map<std::string, double> database;
		database = get_database(CSV_FILENAME, ',');

		std::string delimiter = line.substr(4, line_size - 9);

		while (std::getline(file, line))
		{
			LINE_ERRORS line_err = is_valid_line(line, delimiter);

			if (line_err == NO_ERROR)
			{
				std::string date = line.substr(0, line.find(delimiter));

				try
				{
					double value = stod_cpp98(line.substr(line.find(delimiter) + delimiter.length()));
					double res = get_closest_date_value(database, date) * value;
					std::cout << date << " => " << value << " = " << res << std::endl;
				}
				catch (std::exception const & e)
				{
					std::cerr << BOLD_CRIMSON "Error: " << e.what() << RESET << std::endl;
				}
			}
			else
			{
				print_line_error(line, line_err);
			}
		}
	}
	catch (std::exception const & e)
	{
		std::cerr << BOLD_CRIMSON "Error: " << e.what() << RESET << std::endl;
		usleep(1000000);
		return (1);
	}


	return (0);
}