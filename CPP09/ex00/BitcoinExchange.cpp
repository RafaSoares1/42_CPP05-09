/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:45:06 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/27 18:14:36 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Orthodox Canonical Form
BitcoinExchange::BitcoinExchange() : _file("Default")
{
	readCSV();
	validationInput();
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
	validationInput();
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

// aux member functions
void	BitcoinExchange::printMap(void)
{
  std::map<std::string, float>::iterator it;
    for (it = btcMap.begin(); it != btcMap.end(); ++it)
        std::cout << it->first << "," << std::setprecision(7) << it->second << std::endl;
}

bool BitcoinExchange::isDigit(const std::string& str)
{
  for (size_t i = 0; i < str.length(); ++i)
  	if (!isdigit(str[i]))
      return false;
  return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
  	return false;
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
}

void	BitcoinExchange::validationInput(void)
{
	std::ifstream inputFile(this->_file.c_str());
	if(!inputFile.is_open())
		throw CantOpenFileException();
	std::string line; // Read each line from the file
	if (!std::getline(inputFile, line))
		return ;
	if(line != "date | value")
		throw FormatException();
	while(std::getline(inputFile, line))
		checkLine(line);
}

//check methods
void BitcoinExchange::checkLine(std::string& line)
{
	//std::cout << "Checking line: " << line << std::endl;
	//Check Pipes:
	if (checkPipe(line) == false)
		return;
	if (checkDate(line) == false)
		return;
}

bool BitcoinExchange::checkPipe(std::string& line)
{
	int pipeCount = 0;
	for (size_t i = 0; i < line.length(); i++)
		if (line[i] == '|')
			pipeCount++;
	if (pipeCount != 1)
	{
		std::cout << "Error(1): bad input => " << line << std::endl;
		return false;
	}
	//std::cout << "Pipe ok!" << std::endl;
	return true;
}

bool BitcoinExchange::checkDate(std::string& line)
{
	size_t pos = line.find('|');
	
	std::string date = line.substr(0, pos);
	
	// Remove all whitespaces
  date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());
	
	// -- check - sign --
	int minusCount = 0;
	for (size_t i = 0; i < date.length(); i++)
		if (line[i] == '-')
			minusCount++;
	if (minusCount != 2)
	{
		std::cout << "Error(2): bad input => " << line << std::endl;
		return false;
	}

	// -- separate yyyy/mm/dd --
	std::istringstream dateStream(date);
	std::string year, month, day;
	
	std::getline(dateStream, year, '-');
	std::getline(dateStream, month, '-');
	std::getline(dateStream, day);
	
	// -- check size of date
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
	{
		std::cout << "Error(3): bad input => " << line << std::endl;
		return false;
	}
	//check date values
	if(checkYear(year, date) == false || checkMonth(month) == false || checkDay(year, month, day) == false)
	{
		std::cout << "Error(4): bad input => " << line << std::endl;
		return false;
	}
	if (checkValue(line, date) == false)
		return false;
	return true;
}

bool BitcoinExchange::checkYear(std::string& year, std::string& date)
{
	if (isDigit(year) == false)
		return false;
	if (atoi(year.c_str()) < 2009 || date == "2009-01-01")
		return false;
	return true;
}

bool	BitcoinExchange::checkMonth(std::string& month)
{
	if (isDigit(month) == false)
		return false;
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
		return false;
	return true;
}

bool	BitcoinExchange::checkDay(std::string& year, std::string& month, std::string& day)
{
	if (isDigit(day) == false)
		return false;
	
	if (month == "02")
	{
		if(isLeapYear(atoi(year.c_str())) == true)
		{
			if(atoi(day.c_str()) < 1 || atoi(day.c_str()) > 29)
				return false;
		}
		else
		{
			if(atoi(day.c_str()) < 1 || atoi(day.c_str()) > 28)
				return false;
		}
	}
	else if(month == "04" || month == "06" || month == "09" || month == "11")
	{
		if(atoi(day.c_str()) < 1 || atoi(day.c_str()) > 30)
			return false;
	}
	else
	{
		if(atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
			return false;
	}
	return true;	
}

bool	BitcoinExchange::checkValue(std::string& line, std::string& date)
{
	size_t pos = line.find('|');
	
	std::string value = line.substr(pos + 1);
	// Remove all whitespaces
  value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
	
	if(value.length() <= 0)
	{
		std::cout << "Error(5): bad input => " << line << std::endl;
		return false;
	}
	float numValue = atof(value.c_str());
	if (numValue < 0.0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (numValue > 1000.0)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	int dotCount = 0;
	for (size_t i = 0; i < value.length(); i++)
	{
		if (!isdigit(value[i]) && value[i] != '.')
		{
			std::cout << "Error(6): bad input => " << line << std::endl;
			return false;
		}
		if(value[i] == '.')
			dotCount++;
	}
	if (dotCount > 1 || !isdigit(value[0]))
	{
		std::cout << "Error(7): bad input => " << line << std::endl;
		return false;
	}
	size_t dotPos = value.find('.');
	if(dotPos != std::string::npos && !isdigit(value[dotPos + 1]))
	{
		std::cout << "Error(8): bad input => " << line << std::endl;
		return false;
	}
	
	calculateBTC(date, value);
	return true;
}

//--CALCULATE BTC

void	BitcoinExchange::calculateBTC(std::string& date, std::string& value)
{
	float valueMult;
	
	std::map<std::string, float>::iterator it;
  for (it = btcMap.begin(); it != btcMap.end(); ++it)
	{
		if (date < it->first)
		{
			--it;
			valueMult = it->second;
			break;
		}
	}
	if(it == btcMap.end())
	{
		--it;
		valueMult = it->second;
	}
	float finalValue = atof(value.c_str()) * valueMult;
	std::cout << date << " => " << value << " = " << finalValue << std::endl;
}