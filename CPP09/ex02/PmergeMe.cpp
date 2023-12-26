/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:00:04 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/26 18:13:37 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//OCF

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& obj) : _vec(obj._vec), _deq(obj._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe& obj)
{
	if (this != &obj) {
	    this->_vec = obj._vec;
	    this->_deq = obj._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

//Constructor with arguments

PmergeMe::PmergeMe(std::vector<int> vec) : _vec(vec), _deq(vec.begin(), vec.end())
{
	std::cout << "\033[1;36mBefore: \033[0m";
	std::vector<int> ::iterator it;
	for(it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n" << std::endl;
	SortContainers();
}

//Aux member functions

void	PmergeMe::printVec(void)
{
	std::vector<int>::iterator it;
	std::cout << "\033[1;33mAfter Algorithm[VECTOR]: \033[0m";
	for(it = _vec.begin(); it < _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printDeq(void)
{
	std::deque<int>::iterator it;
	std::cout << "\033[1;34mAfter Algorithm[DEQUE]: \033[0m";
	for(it = _deq.begin(); it < _deq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//Main part of the algorithm 

void PmergeMe::SortContainers(void)
{
	clock_t startV = clock();
	mergeVec(_vec);//algorithm for vector
	clock_t endV = clock();
	double timeV = 1000.0 * (endV - startV) / CLOCKS_PER_SEC;  // Convert to microseconds
	printVec();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << timeV << " us" << std::endl;
	
	std::cout << "\n\n" << std::endl;
	
	clock_t startD = clock();
	mergeDec(_deq);//algorithm for vector
	clock_t endD = clock();
	double timeD = 1000.0 * (endD - startD) / CLOCKS_PER_SEC;  // Convert to microseconds
	printDeq();
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::vector: " << timeD << " us" << std::endl;
	
}


// Merge insert algorithm VECTOR

void PmergeMe::mergeVec(std::vector<int>& vec)
{
	if (vec.size() == 1)
		return ;
	
	int middle = vec.size() / 2;
	
	std::vector<int> left = std::vector<int>(vec.begin(), vec.begin() + middle);
  std::vector<int> right = std::vector<int>(vec.begin() + middle, vec.end());

	mergeVec(left);
	mergeVec(right);
	sortMergeVec(left, right, vec);
}

void PmergeMe::sortMergeVec(std::vector<int>& left, std::vector<int>& right, std::vector<int>& vec)
{
	size_t l = 0, r = 0, i = 0;

  while (l < left.size() && r < right.size())
	{
    if (left[l] < right[r]) 
		{
      vec[i] = left[l];
      i++;
      l++;
    }
    else 
		{
      vec[i] = right[r];
      i++;
      r++;
    }  
  }

	while (l < left.size())
	{
    vec[i] = left[l];
    i++;
    l++;
  }
  while (r < right.size())
	{
    vec[i] = right[r];
    i++;
    r++;
  }
}


// Merge insert algorithm DEQUE

void PmergeMe::mergeDec(std::deque<int>& vec)
{
	if (vec.size() == 1)
		return ;
	
	int middle = vec.size() / 2;
	
	std::deque<int> left = std::deque<int>(vec.begin(), vec.begin() + middle);
  std::deque<int> right = std::deque<int>(vec.begin() + middle, vec.end());

	mergeDec(left);
	mergeDec(right);
	sortMergeDeq(left, right, vec);
}

void PmergeMe::sortMergeDeq(std::deque<int>& left, std::deque<int>& right, std::deque<int>& vec)
{
	size_t l = 0, r = 0, i = 0;

  while (l < left.size() && r < right.size())
	{
    if (left[l] < right[r]) 
		{
      vec[i] = left[l];
      i++;
      l++;
    }
    else 
		{
      vec[i] = right[r];
      i++;
      r++;
    }  
  }

	while (l < left.size())
	{
    vec[i] = left[l];
    i++;
    l++;
  }
  while (r < right.size())
	{
    vec[i] = right[r];
    i++;
    r++;
  }
}
