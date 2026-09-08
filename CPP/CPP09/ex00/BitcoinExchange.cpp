// #include "BitcoinExchange.hpp"

// void cout_error_message(std::string const & message)
// {
// 	std::cout << message;
// }


// void print_line_error(std::string const & line, LINE_ERRORS error)
// {
// 	switch (error)
// 	{
// 		case WRONG_DATE_YEAR:
// 			cout_error_message(WRONG_DATE_YEAR_MESSAGE);
// 			break;
// 		case WRONG_DATE_MONTH:
// 			cout_error_message(WRONG_DATE_MONTH_MESSAGE);
// 			break;
// 		case WRONG_DATE_DAY:
// 			cout_error_message(WRONG_DATE_DAY_MESSAGE);
// 			break;
// 		case WRONG_VALUE:
// 			cout_error_message(WRONG_VALUE_MESSAGE);
// 			break;
// 		case WRONG_LINE_LENGTH:
// 			cout_error_message(WRONG_LINE_FORMAT_MESSAGE);
// 			break;
// 		case NO_DELIMITER:
// 			cout_error_message(NO_DELIMITER_MESSAGE);
// 			break;
// 		case BAD_INPUT:
// 			cout_error_message(BAD_INPUT_MESSAGE);
// 			break;
// 		default:
// 			break;
// 	}

// 	std::cout << line << std::endl;

// 	return ;
// }



// std::map <std::string, double> get_database(std::string const & filename, char delimiter)
// {
// 	std::map <std::string, double> database;
// 	std::ifstream file(filename.c_str());

// 	if (!file)
// 		throw std::runtime_error("Could not open file");

// 	std::string line;
// 	std::getline(file, line); // Skip header

// 	while (std::getline(file, line))
// 	{
// 		std::istringstream ss(line);
// 		std::string key;
// 		double value;
// 		if (!std::getline(ss, key, delimiter) || !(ss >> value))
// 			continue;

// 		database[key] = value;
// 	}
// 	return (database);
// }



// double get_closest_date_value(std::map<std::string, double> const & database, std::string const & date)
// {
// 	std::map<std::string, double>::const_iterator it = database.lower_bound(date);
// 	if (it == database.end())
// 		--it;

// 	if (it == database.begin())
// 		throw std::runtime_error("No earlier date found in the database: " RESET + date);

// 	return (it->second);
// }



// double stod_cpp98(std::string const & str)
// {
//     std::stringstream ss(str);
//     double result;
//     ss >> result;

// 	if (ss.fail())
// 		throw std::runtime_error("Invalid double: " + str);

//     return result;
// }



// bool char_is_digit(char c)
// {
// 	return (c >= '0' && c <= '9');
// }



// bool is_valid_value(std::string const & value)
// {
// 	for (size_t i = 0; i < value.size(); ++i)
// 	{
// 		if (!char_is_digit(value[i]) && value[i] != '.')
// 			return (false);
// 	}
// 	try
// 	{
// 		double val = stod_cpp98(value);
// 		if (val < 0 || val > 1000)
// 			return (false);
// 	}
// 	catch (std::exception & e)
// 	{
// 		return (false);
// 	}

// 	return (true);
// }



// int stoi_cpp98(std::string const & str)
// {
//     std::stringstream ss(str);
//     int result;
//     ss >> result;

// 	if (ss.fail())
// 		throw std::runtime_error("Invalid integer: " + str);

//     return result;
// }



// bool is_leap_year(int year)
// {
//     return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
// }


// int days_in_month(int year, int month)
// {
//     static int days[] = 
// 	{
//         31, 28, 31, 30, 31, 30,
//         31, 31, 30, 31, 30, 31
//     };

//     if (month == 2 && is_leap_year(year))
//         return 29;

//     return (days[month - 1]);
// }



// LINE_ERRORS is_valid_date(std::string const & date)
// {
// 	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
// 		return (BAD_INPUT);

// 	try
// 	{
// 		int year = stoi_cpp98(date.substr(0, 4));
// 		int month = stoi_cpp98(date.substr(5, 2));
// 		int day = stoi_cpp98(date.substr(8, 2));

// 		if (year < 2009 || year > 2026)
// 			return (WRONG_DATE_YEAR);
// 		if (month < 1 || month > 12)
// 			return (WRONG_DATE_MONTH);
// 		if (day < 1 || day > days_in_month(year, month))
// 			return (WRONG_DATE_DAY);
// 	}
// 	catch (std::exception & e)
// 	{
// 		return (BAD_INPUT);
// 	}

// 	return (NO_ERROR);
// }



// LINE_ERRORS is_valid_line(std::string const & line, std::string const & delimiter)
// {
// 	if(line.size() < 12)
// 		return (BAD_INPUT);

// 	std::size_t pos = line.find(delimiter);
// 	if (pos == std::string::npos)
// 		return (NO_DELIMITER);

// 	std::string date = line.substr(0, pos);
// 	std::string value = line.substr(pos + delimiter.length());

// 	if (!is_valid_value(value))
// 		return (WRONG_VALUE);

// 	return (is_valid_date(date));
// }


