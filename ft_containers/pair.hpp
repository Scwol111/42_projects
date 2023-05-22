/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:29:47 by tclaudin          #+#    #+#             */
/*   Updated: 2021/05/02 14:21:33 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type		first;
		second_type		second;

		/* Constructs a pair object with its elements value-initialized */
		pair(): first(), second() {}

		/* The object is initialized with the contents of the pr pair object */
		pair(const pair& pr): first(pr.first), second(pr.second) {}

		/* Member first is constructed with a and member second with b */
		pair (const first_type& a, const second_type& b): first(a), second(b) {}

		/* Assigns pr as the new content for the pair object */
		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}	
	};
	
	/* Constructs a pair object with its first element set to x and its second element set to y */
	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{ return ( pair<T1,T2>(x, y) ); }

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs == rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs < lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs < lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs < rhs); }

	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template <class T> 
	struct less : binary_function <T, T, bool>
	{ 
		bool operator() (const T& x, const T& y) const 
		{ return x < y; } 
	};
}

#endif
