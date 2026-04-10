#include <iostream>
#include <fstream>
#include <string>
#include "SedIsForLosers.hpp"

SedIsForLosers::SedIsForLosers(std::string file, std::string s1, std::string s2) : _file(file), _s1(s1), _s2(s2)
{
	return ;
}

SedIsForLosers::~SedIsForLosers()
{
	return ;
}

void SedIsForLosers::replace(void)
{
    std::ifstream infile(this->_file.c_str());
    if (!infile.is_open())
	{
        std::cerr << "Error: Could not open input file named \"" << this->_file << '\"' << std::endl;
        return ;
    }

    std::ofstream outfile((this->_file + ".replace").c_str());
    if (!outfile.is_open())
	{
        std::cerr << "Error: Could not create output file named \"" << (this->_file + ".replace") << '\"' << std::endl;
        infile.close();
        return;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::string newLine;
        size_t pos = 0;
        size_t prev = 0;

        while ((pos = line.find(this->_s1, prev)) != std::string::npos)
        {
            newLine.append(line, prev, pos - prev); 
            newLine.append(this->_s2);              
            prev = pos + this->_s1.length();      
        }
        newLine.append(line, prev, std::string::npos); 
        
		if (infile.eof())
			outfile << newLine << "";
		else
        	outfile << newLine << std::endl;
    }

    infile.close();
    outfile.close();
}