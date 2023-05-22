/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:39:03 by tclaudin          #+#    #+#             */
/*   Updated: 2021/05/02 14:18:32 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

namespace ft
{
    template <class T, class Container = ft::list<T> >
	class queue
	{
		public:
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
			typedef typename container_type::size_type			size_type;
		
			/* Constructs a queue container adaptor object */
			explicit queue(const container_type& ctnr = container_type()) { c = ctnr; }

			/* Constructs a queue container adaptor object from another queue */
			~queue() {}
			
			/* Returns whether the queue is empty: i.e. whether its size is zero */
			bool empty() const { return c.empty(); }

			/* Returns a reference to the next element in the queue */
			reference front() { return c.front(); }

			/* Returns a reference to the next element in the queue */
			const_reference front() const { return c.front(); }

			/* Returns a reference to the last element in the queue. This is the "newest"
			element in the queue (i.e. the last element pushed into the queue) */
			reference	back() { return c.back(); }

			/* Returns a reference to the last element in the queue. This is the "newest"
			element in the queue (i.e. the last element pushed into the queue) */
    		const_reference	back() const { return c.back(); }

			/* Inserts a new element at the end of the queue, after its current 
			last element. The content of this new element is initialized to val */
			void push (const value_type& val) { c.push_back(val); }

			/* Removes the next element in the queue, effectively reducing its size by one */
			void pop() { c.pop_front(); }

			/* Returns the number of elements in the queue */
			size_type size() const { return c.size(); }

			template <class Ty, class Container2>
			friend bool operator== (const queue<Ty,Container2>& lhs, const queue<Ty,Container2>& rhs)
			{ return (lhs.c == rhs.c); }

			template <class Ty, class Container2>
			friend bool operator!= (const queue<T,Container2>& lhs, const queue<Ty,Container2>& rhs)
			{ return (lhs.c != rhs.c); }

			template <class Ty, class Container2>
			friend bool operator<  (const queue<Ty,Container2>& lhs, const queue<Ty,Container2>& rhs)
			{ return (lhs.c < rhs.c); }

			template <class Ty, class Container2>
			friend bool operator<= (const queue<Ty,Container2>& lhs, const queue<Ty,Container2>& rhs)
			{ return (lhs.c <= rhs.c); }

			template <class Ty, class Container2>
			friend bool operator>  (const queue<Ty,Container2>& lhs, const queue<Ty,Container2>& rhs)
			{ return (lhs.c > rhs.c); }

			template <class Ty, class Container2>
			friend bool operator>= (const queue<Ty,Container2>& lhs, const queue<Ty,Container2>& rhs)
			{ return (lhs.c >= rhs.c); }

		protected:
			container_type c;
	};
}

#endif
