/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:51:11 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/26 18:08:02 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <iterator>
#include <climits>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe &operator=(const PmergeMe& obj);
		~PmergeMe();
		PmergeMe(std::vector<int> vec);
		void	SortContainers(void);
		
		void	printVec(void);
		void	printDeq(void);
		
		void	mergeVec(std::vector<int>& vec);
		void	sortMergeVec(std::vector<int>& left, std::vector<int>& right, std::vector<int>& vec);

		void mergeDec(std::deque<int>& vec);
		void	sortMergeDeq(std::deque<int>& left, std::deque<int>& right, std::deque<int>& vec);
};


#endif