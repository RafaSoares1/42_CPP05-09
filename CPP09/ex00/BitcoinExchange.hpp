/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:45:01 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/18 17:14:52 by emsoares         ###   ########.fr       */
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
		void	readCSV(void);
		void	validationInput(void);
		void	checkLine(std::string& line);

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