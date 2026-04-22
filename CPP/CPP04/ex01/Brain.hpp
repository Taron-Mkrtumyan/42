#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(Brain const & other);
		~Brain();

		Brain & operator=(Brain const & other);
		void fillIdea( std::string idea );
		void printIdeas( void ) const;
};

#endif