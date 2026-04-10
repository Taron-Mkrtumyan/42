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
    void (Harl::*complaints[])(void) = 
	{
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    int i = 0;
    while (i < 4 && level != levels[i])
        i++;
    
    switch (i)
    {
        case 0:
            (this->*complaints[0])();
        case 1:
            (this->*complaints[1])();
        case 2:
            (this->*complaints[2])();
        case 3:
            (this->*complaints[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return ;
}