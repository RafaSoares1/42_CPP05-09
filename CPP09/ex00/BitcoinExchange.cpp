/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:45:06 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/18 17:25:18 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Orthodox Canonical Form
BitcoinExchange::BitcoinExchange() : _file("Default")
{
	readCSV();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	(void)obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	(void)obj;
  return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

//Constructor with argument
BitcoinExchange::BitcoinExchange(std::string file) : _file(file)
{
	readCSV();
}

//Get and set functions

void BitcoinExchange::setFile(std::string fileName)
{
	_file = fileName;
}

std::string BitcoinExchange::getFileName(void)
{
	return (_file);
}


// map container aux member functions
void	BitcoinExchange::printMap(void)
{
  std::map<std::string, float>::iterator it;
    for (it = btcMap.begin(); it != btcMap.end(); ++it)
        std::cout << it->first << "," << std::setprecision(7) << it->second << std::endl;
}

//DataBase to std::map container

void BitcoinExchange::readCSV(void) //place this function inside another one!
{
	std::ifstream inputFile("data.csv"); // Open the CSV file
	if (!inputFile.is_open()) // Check if the file is opened successfully
   throw CantOpenFileException();
	
	std::string line; // Read each line from the file
	std::getline(inputFile, line); //jump the first line of the .csv file (date|exchange_rate)
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line); // to parse the line
		
		// Declare variables for date and bitcoin value
		std::string date;
		float value;
		
		std::getline(iss, date, ',');
		iss >> value;
		btcMap[date] = value;
	}
	
	inputFile.close();
	
	//printMap();
	validationInput();

}

void	BitcoinExchange::validationInput(void)
{
	std::ifstream inputFile(this->_file.c_str());
	if(!inputFile.is_open())
		throw CantOpenFileException();
	if (inputFile.eof())
		return ;
	std::string line; // Read each line from the file
	std::getline(inputFile, line);
	if(line != "date | value")
		throw FormatException();
	while(std::getline(inputFile, line))
	{
		checkLine(line);
	}
}

void BitcoinExchange::checkLine(std::string& line)
{
	//std::cout << "Checking line: " << line << std::endl;
	//Check Pipes:
	int pipeCount = 0;
	for (std::size_t i = 0; i < line.length(); ++i)
		if (line[i] == '|')
			pipeCount++;
	if (pipeCount != 1)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	std::cout << "Pipe ok!" << std::endl;
}