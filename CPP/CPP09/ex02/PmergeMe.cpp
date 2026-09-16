#include "PmergeMe.hpp"

// static Pair get_large_small(int a, int b);
int		stoi_cpp98(std::string const & str);
void	display();

PmergeMe::PmergeMe (int ac, char **av) : _av(av), _ac(ac), _timeTaken(0)
{
    for (int i = 1; i < ac; ++i)
    {
        int current_int = stoi_cpp98(av[i]);
        _vector.push_back(current_int);
		_deque.push_back(current_int);
    }
}

PmergeMe::~PmergeMe () {}
PmergeMe::PmergeMe (PmergeMe const & other)
{
	_vector = other._vector;
	_deque = other._deque;
	_ac = other._ac;
	_av = other._av;
	_timeTaken = other._timeTaken;
}

PmergeMe & PmergeMe::operator= (PmergeMe const & other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_av = other._av;
		_ac = other._ac;
		_timeTaken = other._timeTaken;
	}

	return (*this);
}

void	PmergeMe::run()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // --- Run your sorting algorithm here ---

    gettimeofday(&end, NULL);
    _timeTaken = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);


	display();

	return ;
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

void	PmergeMe::display_unsorted_numbers()
{
	for (char ** iterator = _av; *iterator != NULL; ++iterator)
	{
		std::cout << (*iterator);
		if (*(iterator + 1) != NULL)
			std::cout << " ";
	}
	std::cout << std::endl;

	return ;
}

void	PmergeMe::display_sorted_numbers()
{
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << (*it);
		if (it + 1 != _vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;

	return ;
}

void	PmergeMe::display_time()
{
	std::cout << "Time taken: " << _timeTaken << " µs " << std::endl;
}

void	PmergeMe::display()
{
	display_unsorted_numbers();
	display_sorted_numbers();
	display_time();

	return ;
}

// static Pair get_large_small(int a, int b)
// {
//     return ( (a > b) ? Pair(a, b) : Pair(b, a) );
// }

