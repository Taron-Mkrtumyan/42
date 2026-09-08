#include "RPN.hpp"

int		stoi_cpp98(std::string const & str);
bool	is_valid_input(std::string const & input);
bool	is_valid_token(char c);

RPN::RPN () {}
RPN::~RPN () {}
RPN::RPN (RPN const & other) { _stack = other._stack; }

RPN & RPN::operator= (RPN const & other)
{
	if (this != &other)
		_stack = other._stack;

	return (*this);
}

void RPN::handleOperation(std::string const & op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Not enough operands");

	int b = _stack.top(); _stack.pop();
	int a = _stack.top(); _stack.pop();

	if (op == "+")
		_stack.push(a + b);
	else if (op == "-")
		_stack.push(a - b);
	else if (op == "*")
		_stack.push(a * b);
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Division by zero");
		_stack.push(a / b);
	}
	else
		throw std::runtime_error("Unknown operation");
}


void	RPN::run(std::string const & input)
{
	if (!is_valid_input(input))
		throw std::runtime_error("Invalid input");

	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (std::isdigit(token[0]))
			_stack.push(stoi_cpp98(token));
		else
			handleOperation(token);
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid RPN expression");
	std::cout << BOLD_GREEN << _stack.top() << RESET << std::endl;
	_stack.pop();
}

int stoi_cpp98(std::string const & str)
{
    std::stringstream ss(str);
    int result;
    ss >> result;

	if (ss.fail())
		throw std::runtime_error("Invalid integer: " + str);

    return (result);
}


bool is_valid_token(char c)
{
	if (std::isdigit(c))
		return (true);
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	if (std::isspace(c))
		return (true);
	return (false);
}


bool is_valid_input(std::string const & input)
{
	for (size_t i = 0; i < input.size(); ++i)
	{
		if (!is_valid_token(input[i]))
			return (false);
	}
	return (true);
}