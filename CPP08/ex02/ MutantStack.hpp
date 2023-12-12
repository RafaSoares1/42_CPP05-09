/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    MutantStack.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:06 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/12 14:06:40 by emsoares         ###   ########.fr       */
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
		
    typedef typename std::stack<T>::container_type::iterator iterator;//entire line is creating an alias iterator for the iterator type of the underlying container type used in the std::stack of type T.
    // This allows the MutantStack class to use iterator as a shorthand for the iterator type used in its underlying container.
    
    //These functions return iterators pointing to the beginning and the end of the underlying container, respectively.
    iterator begin(void);
    iterator end(void);
};

#include "MutantStack.tpp"

#endif