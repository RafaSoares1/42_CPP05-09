/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:36:19 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/12 14:10:06 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& obj) 
{
	*this = obj;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& obj) 
{
  std::stack<T>::operator=(this, obj);
  return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(){}


/* this->c.begin() and this->c.end() are used to access the iterators of the underlying container (c) of the std::stack,
and these iterators are then returned by the begin() and end() functions of the MutantStack class */

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
  return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif