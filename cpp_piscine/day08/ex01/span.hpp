/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:49:51 by tclaudin          #+#    #+#             */
/*   Updated: 2021/03/19 20:34:21 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>
#include <iostream>
#include <iterator>

class Span
{
private:
	std::multiset<int> _arr;
	size_t _size;

public:
	Span();
	Span(size_t n);
	Span(const Span &);
	~Span();

	void addNumber(int);
	template <typename T>
		void addNumber(T first, T last);
	int shortestSpan() const;
	int longestSpan() const;

	void operator = (const Span &);

	class MaximalSizeReached: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NotEnoughNumber: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

template<typename T>
void Span::addNumber(T first, T last)
{
	for (T i = first; i != last; i++)
		_arr.insert(*i);
}

#endif
