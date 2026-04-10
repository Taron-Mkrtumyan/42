#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
    return ;
}

Harl::~Harl()
{
    return ;
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl << DEBUG_MESSAGE<< std::endl;
	return ;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl << INFO_MESSAGE << std::endl;
	return ;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl << WARNING_MESSAGE<< std::endl;
	return ;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl << ERROR_MESSAGE << std::endl;
	return ;
}

void Harl::complain(std::string level)
{
    if (level.empty())
        return ;

    void (Harl::*complaints[])(void) = 
	{
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*complaints[i])();
            return ;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}