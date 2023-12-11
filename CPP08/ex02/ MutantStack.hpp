/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    MutantStack.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:06 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/11 18:43:52 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
    MutantStack();
    MutantStack(const MutantStack& obj);
    MutantStack& operator=(const MutantStack& obj);
    ~MutantStack();
		
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin(void);
    iterator end(void);
};

#include "MutantStack.tpp"

#endif