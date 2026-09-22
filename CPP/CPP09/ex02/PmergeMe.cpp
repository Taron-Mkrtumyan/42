#include "PmergeMe.hpp"

int			stoi_cpp98(std::string const & str);
std::string	intToString(int value);

PmergeMe::PmergeMe (int ac, char **av) : _av(av), _ac(ac), _timeTakenVector(0), _timeTakenDeque(0)
{
    for (int i = 1; i < ac; i++)
    {
        int current_int = stoi_cpp98(av[i]);

		if ( _seen.insert(current_int).second == false)                                           //returns std::pair<iterator, bool>
			throw std::runtime_error("Duplicate integer: " + intToString(current_int));

        _vector.push_back(current_int);
		_deque.push_back(current_int);
    }
}

PmergeMe::~PmergeMe () {}
PmergeMe::PmergeMe (PmergeMe const & other)
{
	_vector = other._vector;
	_deque = other._deque;
	_seen = other._seen;
	_ac = other._ac;
	_av = other._av;
	_timeTakenVector = other._timeTakenVector;
	_timeTakenDeque = other._timeTakenDeque;
}

PmergeMe & PmergeMe::operator= (PmergeMe const & other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_seen = other._seen;
		_av = other._av;
		_ac = other._ac;
		_timeTakenVector = other._timeTakenVector;
		_timeTakenDeque = other._timeTakenDeque;
	}

	return (*this);
}


void	PmergeMe::run()
{
    struct timeval start, end;

    gettimeofday(&start, NULL);
	_mergeInsertionSort(_vector);
    gettimeofday(&end, NULL);
    
	_timeTakenVector = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
	

    gettimeofday(&start, NULL);
	_mergeInsertionSort(_deque);
    gettimeofday(&end, NULL);
    
	_timeTakenDeque = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);


	_display();

	return ;
}


void	PmergeMe::_mergeInsertionSort(std::vector<int> & container)
{
    if (container.size() <= 1)
        return ;

    std::vector<Pair> pairs;
    std::vector<int>  winners;

    bool	hasStraggler = (container.size() % 2 != 0);
    int		straggler = 0;

    for (std::vector<int>::size_type i = 0;
         i + 1 < container.size();
         i += 2)
    {
        if (container[i] < container[i + 1])
            pairs.push_back(Pair(container[i], container[i + 1]));
        else
            pairs.push_back(Pair(container[i + 1], container[i]));

        winners.push_back(pairs.back().second);
    }

    if (hasStraggler)
        straggler = container.back();


    _mergeInsertionSort(winners);


    std::vector<int> mainChain;

    for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->second == winners[0])
        {
            mainChain.push_back(it->first);
            break ;
        }
    }

    for (std::vector<int>::iterator it = winners.begin(); it != winners.end(); it++)
        mainChain.push_back(*it);

    for (std::vector<int>::size_type i = 1; i < winners.size(); ++i)
	{
		int winner = winners[i];
		int loser = 0;

		for (std::vector<Pair>::const_iterator it = pairs.begin();
			it != pairs.end();
			++it)
		{
			if (it->second == winner)
			{
				loser = it->first;
				break ;
			}
		}

		std::vector<int>::iterator partner  = std::find		  (mainChain.begin(), mainChain.end(), winner);
		std::vector<int>::iterator position = std::lower_bound(mainChain.begin(), partner, loser);

		mainChain.insert(position, loser);
	}

	if (hasStraggler)
	{
		std::vector<int>::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);

		mainChain.insert(position, straggler);
	}

	container = mainChain;
}

void	PmergeMe::_mergeInsertionSort(std::deque<int> & container)
{
    if (container.size() <= 1)
        return ;

    std::deque<Pair> pairs;
    std::deque<int>  winners;

    bool	hasStraggler = (container.size() % 2 != 0);
    int		straggler = 0;

    for (std::deque<int>::size_type i = 0;
         i + 1 < container.size();
         i += 2)
    {
        if (container[i] < container[i + 1])
            pairs.push_back(Pair(container[i], container[i + 1]));
        else
            pairs.push_back(Pair(container[i + 1], container[i]));

        winners.push_back(pairs.back().second);
    }

    if (hasStraggler)
        straggler = container.back();


    _mergeInsertionSort(winners);


    std::deque<int> mainChain;

    for (std::deque<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->second == winners[0])
        {
            mainChain.push_back(it->first);
            break ;
        }
    }

    for (std::deque<int>::iterator it = winners.begin(); it != winners.end(); it++)
        mainChain.push_back(*it);

    for (std::deque<int>::size_type i = 1; i < winners.size(); ++i)
	{
		int winner = winners[i];
		int loser = 0;

		for (std::deque<Pair>::const_iterator it = pairs.begin();
			it != pairs.end();
			++it)
		{
			if (it->second == winner)
			{
				loser = it->first;
				break ;
			}
		}

		std::deque<int>::iterator partner  = std::find		  (mainChain.begin(), mainChain.end(), winner);
		std::deque<int>::iterator position = std::lower_bound(mainChain.begin(), partner, loser);

		mainChain.insert(position, loser);
	}

	if (hasStraggler)
	{
		std::deque<int>::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);

		mainChain.insert(position, straggler);
	}

	container = mainChain;
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

std::string	intToString(int value)
{
    std::ostringstream oss;
    oss << value;

	if (oss.fail())
		return ("");

    return (oss.str());
}

void	PmergeMe::_display_unsorted_numbers()
{
	for (char ** iterator = _av + 1; *iterator != NULL; iterator++)
		std::cout << (*iterator) << ' ';

	std::cout << std::endl;

	return ;
}

void	PmergeMe::_display_sorted_numbers()
{
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << (*it) << ' ';

    std::cout << std::endl;
}

void	PmergeMe::_display_vector_time() { std::cout << "Time taken: " << _timeTakenVector << " µs " << std::endl; }
void	PmergeMe::_display_deque_time()  { std::cout << "Time taken: " << _timeTakenDeque  << " µs " << std::endl; }

void	PmergeMe::_display()
{
	std::cout << "Unsorted numbers : ";
	_display_unsorted_numbers();

	std::cout << "Sorted numbers   : ";
	_display_sorted_numbers();

	std::cout << "Time taken to sort " << _ac - 1 << " numbers by std::vector :\t";
	_display_vector_time();

	std::cout << "Time taken to sort " << _ac - 1 << " numbers by std::deque  :\t";
	_display_deque_time();

	return ;
}
