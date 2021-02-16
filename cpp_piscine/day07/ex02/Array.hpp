/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:30:51 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/17 18:49:31 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
private:
	size_t _size;
	T *_arr;

public:
	class OutOfRangeException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	Array();
	Array(size_t n);
	Array(const Array<T> &);
	~Array();

	void operator = (const Array<T> &);
	T &operator[] (size_t);
	size_t size() const;

	
};

template<typename T>
Array<T>::Array(): _size(0)
{
	_arr = NULL;
}

template<typename T>
Array<T>::Array(size_t n): _size(n)
{
	_arr = new T[_size];
}

template<typename T>
Array<T>::Array(const Array<T> &copy): _size(copy._size)
{
	_arr = new T[_size];
	for (int i = 0; i < _size; i++)
		_arr[i] = copy._arr[i];
}

template<typename T>
Array<T>::~Array()
{
	if (_arr)
		delete[] _arr;
}

template<typename T>
void Array<T>::operator=(const Array<T> &copy)
{
	if (this != &copy)
	{
		_size = copy._size;
		_arr = new T[_size];
		for (int i = 0; i < _size; i++)
			_arr[i] = copy._arr[i];
	}
}

template<typename T>
size_t Array<T>::size() const
{
	return _size;
}

template<typename T>
T &Array<T>::operator[] (size_t idx)
{
	if (!(idx >= 0 && idx < _size))
		throw Array<T>::OutOfRangeException();
	return _arr[idx];
}

template<typename T>
const char* Array<T>::OutOfRangeException::what() const throw()
{
	return "Error: Index out of range";
}

#endif
