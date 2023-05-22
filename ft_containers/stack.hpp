/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:54:33 by tclaudin          #+#    #+#             */
/*   Updated: 2021/05/02 14:18:46 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> > 
	class stack
	{
		public:
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
			typedef typename container_type::size_type			size_type;
			
			/* Constructs a stack container adaptor object */
			explicit stack (const container_type& ctnr = container_type()) { c = ctnr; }
			
			~stack() {}
			
			/* Returns whether the stack is empty: i.e. whether its size is zero */
			bool empty() const { return c.empty(); }

			/* Returns the number of elements in the stack */
			size_type size() const { return c.size(); }

			/* Returns a reference to the top element in the stack */
			reference top() { return c.back(); }

			/* Returns a reference to the top element in the stack */
			reference top() const { return c.back(); }

			/* Inserts a new element at the top of the stack, above its current 
			top element. The content of this new element is initialized to a copy of val */
			void push (const value_type& val) { c.push_back(val); }

			/* Removes the element on top of the stack, effectively reducing its size by one */
			void pop() { c.pop_back(); }

			template <class Ty, class Container2>
			friend bool operator== (const stack<Ty,Container2>& lhs, const stack<Ty,Container2>& rhs)
			{ return (lhs.c == rhs.c); }

			template <class Ty, class Container2>
			friend bool operator!= (const stack<Ty,Container2>& lhs, const stack<Ty,Container2>& rhs)
			{ return (lhs.c != rhs.c); }

			template <class Ty, class Container2>
			friend bool operator<  (const stack<Ty,Container2>& lhs, const stack<Ty,Container2>& rhs)
			{ return (lhs.c < rhs.c); }

			template <class Ty, class Container2>
			friend bool operator<= (const stack<Ty,Container2>& lhs, const stack<Ty,Container2>& rhs)
			{ return (lhs.c <= rhs.c); }
				
			template <class Ty, class Container2>
			friend bool operator>  (const stack<Ty,Container2>& lhs, const stack<Ty,Container2>& rhs)
			{ return (lhs.c > rhs.c); }

			template <class Ty, class Container2>
			friend bool operator>= (const stack<Ty,Container2>& lhs, const stack<Ty,Container2>& rhs)
			{ return (lhs.c >= rhs.c); }

		protected:
			container_type c;
	};
}

#endif
