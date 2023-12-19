/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:45:01 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/19 18:11:01 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> btcMap;
		std::string _file;
		
		BitcoinExchange(const BitcoinExchange& obj);
    BitcoinExchange& operator=(const BitcoinExchange& obj);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string file);
    ~BitcoinExchange();
		void	setFile(std::string fileName);
		std::string getFileName(void);
		
		void	printMap(void);
		bool	isDigit(const std::string& str);
		bool	isLeapYear(int year);
		
		void	readCSV(void);
		void	validationInput(void);
		void	checkLine(std::string& line);
		bool	checkPipe(std::string& line);
		bool	checkDate(std::string& line);
		bool	checkYear(std::string& year, std::string& date);
		bool	checkMonth(std::string& month);
		bool	checkDay(std::string& year, std::string& month, std::string& day);
		bool	checkValue(std::string& line, std::string& date);
		void	calculateBTC(std::string& date, int value);
		class CantOpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Exception: Can't open file!";}
		};
		class FormatException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Exception: Incorrect format at the beginning of the file!";}
		};
};



#endif