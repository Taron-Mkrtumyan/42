#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <fstream>
# include <unistd.h>
# include <sstream>
# include <stack>
# include <stdexcept>
# include <string>
# include <cstdlib>

class RPN
{
    private:
        std::stack<int> _stack;
        void handleOperation(std::string const & op);

    public:
        RPN();
        ~RPN();
        RPN(RPN const & other);
        RPN & operator=(RPN const & other);

        void run(std::string const & input);
};



#define WRONG_ARGUMENTS_MESSAGE		"" BOLD_CRIMSON	"Error: Please provide a single argument." RESET
#define	USAGE_MESSAGE 				"" BOLD_GREEN	"Usage: ./RPN <expression>" RESET

#define BOLD_CRIMSON	"\033[1;31m"
#define BOLD_GREEN		"\033[1;32m"
#define BOLD_YELLOW		"\033[1;33m"
#define BOLD_CYAN		"\033[1;36m"
#define RESET			"\033[0m"



#endif