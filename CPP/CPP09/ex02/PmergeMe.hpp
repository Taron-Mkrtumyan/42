#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <fstream>
# include <unistd.h>
# include <sstream>
# include <stdexcept>
# include <string>
# include <cstdlib>
# include <vector>
# include <deque>
# include <utility>
# include <sys/time.h>


class PmergeMe
{
    private:
        char **             _av;
        int                 _ac;
        std::vector <int>   _vector;
        std::deque  <int>   _deque;
        long long           _timeTaken;

        void	display_unsorted_numbers();
        void	display_sorted_numbers();
        void	display_time();
        void    display();

    public:
        PmergeMe(int ac, char **av);
        ~PmergeMe();
        PmergeMe(PmergeMe const & other);
        PmergeMe & operator=(PmergeMe const & other);

        void run();
};


typedef std::pair<int, int> Pair;


#define WRONG_ARGUMENTS_MESSAGE		"" BOLD_CRIMSON	"Error: Please provide positive integer arguments." RESET
#define NO_ARGUMENTS_MESSAGE		"" BOLD_CRIMSON	"Error: No arguments provided." RESET
#define	USAGE_MESSAGE 				"" BOLD_GREEN	"Usage: ./PmergeMe int1 int2 ... intN" RESET

#define BOLD_CRIMSON	"\033[1;31m"
#define BOLD_GREEN		"\033[1;32m"
#define BOLD_YELLOW		"\033[1;33m"
#define BOLD_CYAN		"\033[1;36m"
#define RESET			"\033[0m"



#endif