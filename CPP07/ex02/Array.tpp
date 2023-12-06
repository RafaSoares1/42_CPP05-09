/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:21:51 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/06 10:44:07 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_TPP
#define ARRAY_TPP

template <class T>
Array<T>::Array() : _n(0)
{
	_array = new T[_n];
}

template <class T>
Array<T>::Array(unsigned int n) : _n(n)
{
	_array = new T[_n];
	for(unsigned int i = 0; i < _n; i++)
		_array[i] = T(); // The default value is obtained by calling the default constructor of type T using T().
}

template <class T>
Array<T>::Array(Array& obj) : _n(obj._n)
{
	_array = new T[_n];
	for(unsigned int i = 0; i < _n; i++)
		_array[i] = obj._array[i];
}

template <class T>
Array<T>& Array<T>::operator=(Array const& obj)
{
	if (this != &obj)
	{
		delete [] _array;
		_n = obj._n;
		_array = new T[_n];
		for(unsigned int i = 0; i < _n; i++)
			_array[i] = obj._array[i];
	}
	return (*this);
}

template <class T>
Array<T>::~Array()
{
	delete [] _array;
}

template <class T>
unsigned int Array<T>::size(void)const
{
	return(_n);
}

template <class T>
T& Array<T>:: operator[](unsigned int i)
{
	if(i >= _n)
		throw IndexOutOfBoundsException();
	return (_array[i]);
}

#endif