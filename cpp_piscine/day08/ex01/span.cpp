/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:50:48 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/18 16:17:32 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(): _size(0)
{
}

Span::Span(size_t n): _size(n)
{
}

Span::Span(const Span &copy): _arr(copy._arr), _size(copy._size)
{
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
	if (_arr.size() >= _size)
		throw Span::MaximalSizeReached();
	_arr.insert(num);
}

int Span::longestSpan() const
{
	if (_size == 0 || _arr.size() == 0)
		throw Span::NotEnoughNumber();
	return *(--_arr.end()) - *_arr.begin();
}

int Span::shortestSpan() const
{
	if (_size < 2 || _arr.size() < 2)
		throw Span::NotEnoughNumber();
	int res = std::numeric_limits<int>::max();
	int last = *_arr.begin();
	for (std::multiset<int>::iterator k = ++_arr.begin(); k != _arr.end(); k++)
	{
		if (res > *k - last)
			res = *k - last;
		last = *k;
	}
	return res;
}

void Span::operator=(const Span &copy)
{
	_size = copy._size;
	_arr = copy._arr;
}

const char* Span::MaximalSizeReached::what() const throw()
{
	return "Span: Maximal Size Reached";
}

const char* Span::NotEnoughNumber::what() const throw()
{
	return "Span: Not enough number in array";
}
