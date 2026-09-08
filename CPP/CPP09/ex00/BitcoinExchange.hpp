// #ifndef BITCOINEXCHANGE_HPP
// # define BITCOINEXCHANGE_HPP

// # include <iostream>
// # include <fstream>
// # include <unistd.h>
// # include <sstream>
// # include <map>

// class BitcoinExchange
// {
//     public:
//         BitcoinExchange();
//         ~BitcoinExchange();
//         BitcoinExchange(BitcoinExchange const & other);
//         BitcoinExchange & operator=(BitcoinExchange const & other);

//         void    loadData(const char *filename);
//         void    processInput(const char *inputFile);
//         double  getExchangeRate(std::string const & date) const;

//     private:
//         std::map <std::string, double> _exchangeRates;

//         bool _isValidDate(std::string const & date) const;
// };

// enum LINE_ERRORS
// {
// 	NO_ERROR,
// 	WRONG_DATE_YEAR,
// 	WRONG_DATE_MONTH,
// 	WRONG_DATE_DAY,
// 	WRONG_VALUE,
// 	WRONG_LINE_LENGTH,
// 	NO_DELIMITER,
// 	BAD_INPUT
// };

// #define BOLD_CRIMSON	"\033[1;31m"
// #define BOLD_GREEN		"\033[1;32m"
// #define BOLD_YELLOW		"\033[1;33m"
// #define BOLD_CYAN		"\033[1;36m"
// #define RESET			"\033[0m"

// #define WRONG_ARGUMENTS_MESSAGE		"" BOLD_CRIMSON	"Error: Please provide a single argument." RESET
// #define HELP_MESSAGE				"" BOLD_CYAN	"try " BOLD_YELLOW "'./btc help' " BOLD_CYAN "for more information." RESET
// #define	USAGE_MESSAGE 				"" BOLD_GREEN	"Usage: ./btc <database_path>" RESET
// #define	CSV_MESSAGE					"" BOLD_CYAN	"Database should have lines in the following format:"	BOLD_YELLOW	" \"date | value\"" BOLD_CYAN "." RESET
// #define	VALID_DATE_MESSAGE			"" BOLD_CYAN	"A valid date format: "	BOLD_YELLOW	"Year-Month-Day"	BOLD_CYAN	"." RESET
// #define	VALID_VALUE_MESSAGE			"" BOLD_CYAN	"A valid value should be a number between "	BOLD_YELLOW	"0-1000"	BOLD_CYAN	"." RESET
// #define WRONG_LINE_FORMAT_MESSAGE	"" BOLD_CRIMSON "Error: Wrong line format. (should be \"date | value\")" RESET
// #define WRONG_DATE_FORMAT_MESSAGE	"" BOLD_CRIMSON "Error: Wrong date format. (should be \"Year-Month-Day\")" RESET

// #define WRONG_VALUE_MESSAGE			"" BOLD_CRIMSON "Error: Wrong value (not 0-1000): " RESET
// #define NO_DELIMITER_MESSAGE		"" BOLD_CRIMSON "Error: No delimiter: " RESET
// #define BAD_INPUT_MESSAGE			"" BOLD_CRIMSON "Error: Bad input: " RESET
// #define WRONG_DATE_DAY_MESSAGE		"" BOLD_CRIMSON "Error: Wrong date (day): " RESET
// #define WRONG_DATE_MONTH_MESSAGE	"" BOLD_CRIMSON "Error: Wrong date (month): " RESET
// #define WRONG_DATE_YEAR_MESSAGE		"" BOLD_CRIMSON "Error: Wrong date (year): " RESET
// #define WRONG_LINE_LENGTH_MESSAGE	"" BOLD_CRIMSON "Error: Wrong line length: " RESET

// #define CSV_FILENAME "data.csv"

// #endif