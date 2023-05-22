/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:39:07 by tclaudin          #+#    #+#             */
/*   Updated: 2021/05/02 14:18:22 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>
#include "nodes.hpp"
#include "iterator.hpp"
#include "exception.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> > 
	class list
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef ft::BidirectionalIterator<value_type>		iterator;
			typedef ft::BidirectionalIterator<value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			/* Constructs an empty container, with no elements */
			explicit list (const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _node_alloc()
			{
				_start = _node_alloc.allocate(1);
				_end = _start;
				_node_alloc.construct(_start, list_node());
				_alloc.construct(&_end->data, value_type());
				_end->next = _start;
				_end->prev = _start;
			}

			/* Constructs a container with n elements. Each element is a copy of val */
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _size(0), _node_alloc()
			{
				size_type i = 0;
				list_node *tmp = NULL;
				_start = NULL;

				do
				{
					_end = _node_alloc.allocate(1);
					_node_alloc.construct(_end, list_node());
					_alloc.construct(&_end->data, val);
					if (tmp != NULL)
					{
						tmp->next = _end;
						_end->prev = tmp;
					}
					if (_start == NULL)
						_start = _end;
					tmp = _end;
					if (i != n)
						_size++;
				} while (i++ < n);
				_end->next = _start;
				_start->prev = _end;
			}

			/* Constructs a container with as many elements as the range [first,last), with each element constructed 
			from its corresponding element in that range, in the same order */
			template <class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), char (*)[sizeof(*first)] = NULL):
			_alloc(alloc), _size(0), _node_alloc()
			{
				list_node *tmp = NULL;
				_start = NULL;

				do
				{
					_end = _node_alloc.allocate(1);
					_node_alloc.construct(_end, list_node());
					if (first != last)
						_alloc.construct(&_end->data, *first);
					else
						_alloc.construct(&_end->data, value_type());
					if (tmp != NULL)
					{
						tmp->next = _end;
						_end->prev = tmp;
					}
					if (_start == NULL)
						_start = _end;
					tmp = _end;
					_size++;
				} while (first++ != last);
				_size--;
				_end->next = _start;
				_start->prev = _end;
			}

			/* Constructs a container with a copy of each of the elements in x, in the same order */
			list (const list& x): _alloc(x._alloc), _size(0)
			{
				list_node *t = x._start;
				list_node *tmp = NULL;
				_start = NULL;

				do
				{
					_end = _node_alloc.allocate(1);
					_node_alloc.construct(_end, list_node());
					_alloc.construct(&_end->data, t->data);
					if (tmp != NULL)
					{
						tmp->next = _end;
						_end->prev = tmp;
					}
					if (_start == NULL)
						_start = _end;
					tmp = _end;
					if (t != x._end)
						_size++;
					t = t->next;
				} while (t != x._start);
				_end->next = _start;
				_start->prev = _end;
			}

			/* Destroys the container object */
			virtual ~list()
			{
				clear();
				_alloc.destroy(&_end->data);
				_node_alloc.destroy(_end);
				_node_alloc.deallocate(_end, 1);
			}

			/* Assigns new contents to the container, replacing its current contents, and modifying its size accordingly */
			list& operator= (const list& x)
			{
				
				if (this != &x)
				{
					if (_end != NULL)
					{
						clear();
						_alloc.destroy(&_end->data);
						_node_alloc.destroy(_end);
						_node_alloc.deallocate(_end, 1);
					}
					_alloc = x._alloc;
					_node_alloc = x._node_alloc;
					_size = 0;
					list_node *t = x._start;
					list_node *tmp = NULL;
					_start = NULL;
					do
					{
						_end = _node_alloc.allocate(1);
						_node_alloc.construct(_end, list_node());
						_alloc.construct(&_end->data, t->data);
						if (tmp != NULL)
						{
							tmp->next = _end;
							_end->prev = tmp;
						}
						if (_start == NULL)
							_start = _end;
						tmp = _end;
						if (t != x._end)
							_size++;
						t = t->next;
					} while (t != x._start);
					_end->next = _start;
					_start->prev = _end;
				}
				return *this;
			}

			/* Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0 */
			void clear()
			{
				list_node *tmp;
				
				_size = 0;
				while (_start != _end)
				{
					tmp = _start->next;
					_alloc.destroy(&_start->data);
					_node_alloc.destroy(_start);
					_node_alloc.deallocate(_start, 1);
					_start = tmp;
				}
				_end->next = _start;
				_end->prev = _start;
			}

			/* Returns whether the list container is empty (i.e. whether its size is 0) */
			bool empty() const
			{
				if (_start == _end)
					return true;
				return false;
			}
			
			/* Returns the number of elements in the list container */
			size_type size() const
			{
				return _size;
			}

			/* Returns the maximum number of elements that the list container can hold */
			size_type max_size() const { return _node_alloc.max_size();	}

			/* Returns a reference to the first element in the list container */
			reference front() { return _start->data; }
			
			/* Returns a reference to the first element in the list container */
			const_reference front() const {	return _start->data; }

			/* Returns a reference to the last element in the list container */
			reference back() { return _end->prev->data;	}
			
			/* Returns a reference to the last element in the list container */
			const_reference back() const { return _end->prev->data;	}

			/* Returns an iterator pointing to the first element in the list container */
			iterator begin() { return _start; }
			
			/* Returns an iterator pointing to the first element in the list container. */
			const_iterator begin() const { return _start; }

			/* Returns an iterator referring to the past-the-end element in the list container */
			iterator end() { return _end; }

			/* Returns an iterator referring to the past-the-end element in the list container */
			const_iterator end() const { return _end; }

			/* Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning) */
			reverse_iterator rbegin() { return reverse_iterator(_end); }
			
			/* Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning) */
			const_reverse_iterator rbegin() const { return const_reverse_iterator(_end); }

			/* Returns a reverse iterator pointing to the theoretical element preceding the first element 
			in the list container (which is considered its reverse end) */
			reverse_iterator rend() { return reverse_iterator(_start); }

			/* Returns a reverse iterator pointing to the theoretical element preceding the first element 
			in the list container (which is considered its reverse end) */
			const_reverse_iterator rend() const { return const_reverse_iterator(_start); }

			/* Inserts a new element at the beginning of the list, right before its current first element. 
			The content of val is copied (or moved) to the inserted element */
			void push_front (const value_type& val)
			{
				list_node *new_node = NULL;

				new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, list_node());
				_alloc.construct(&new_node->data, val);
				_size++;
				new_node->next = _start;
				_start->prev = new_node;
				_start = new_node;
				_end->next = _start;
				_start->prev = _end;
			}

			/* Removes the first element in the list container, effectively reducing its size by one */
			void pop_front()
			{
				list_node *tmp = _start->next;
				
				if (_start != _end)
				{
					_size--;
					tmp->prev = NULL;
					_alloc.destroy(&_start->data);
					_node_alloc.destroy(_start);
					_node_alloc.deallocate(_start, 1);
					_start = tmp;
					_end->next = _start;
					_start->prev = _end;
				}
			}

			/* Adds a new element at the end of the list container, after its current last element. 
			The content of val is copied (or moved) to the new element */
			void push_back (const value_type& val)
			{
				list_node *new_node = NULL;

				new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, list_node());
				_alloc.construct(&_end->data, val);
				new_node->prev = _end;
				_end->next = new_node;
				new_node->prev = _end;
				_end = new_node;
				_size++;
				_end->next = _start;
				_start->prev = _end;
			}

			/* Removes the last element in the list container, effectively reducing the container size by one */
			void pop_back()
			{
				list_node *tmp = _end->prev;

				if (_start != _end)
				{
					tmp->next = NULL;
					_alloc.destroy(&tmp->data);
					_node_alloc.destroy(_end);
					_node_alloc.deallocate(_end, 1);
					_end = tmp;
					_size--;
					_end->next = _start;
					_start->prev = _end;
				}
			}

			/* Exchanges the content of the container by the content of x, which is another list of the same type. 
			Sizes may differ */
			void swap(list& x)
			{
				list_node *tmp = x._start;
				size_type t = x._size;
				
				x._start = _start;
				x._size = _size;
				_start = tmp;
				_size = t;
				tmp = x._end;
				x._end = _end;
				_end = tmp;
			}

			/* Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly */
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL)
			{
				clear();
				for (; first != last; first++)
					push_back(*first);
			}

			/* Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly */
			void assign (size_type n, const value_type& val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			/* The container is extended by inserting new elements before the element at the specified position */
			iterator insert (iterator position, const value_type& val)
			{
				list_node *node = _find_node(position);
				list_node *new_node = NULL;

				new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, list_node());
				_alloc.construct(&new_node->data, val);
				new_node->next = node;
				new_node->prev = node->prev;
				if (node == _start)
					_start = new_node;
				else
					node->prev->next = new_node;
				node->prev = new_node;
				_size++;
				_end->next = _start;
				_start->prev = _end;
				return new_node;
			}

			/* The container is extended by inserting new elements before the element at the specified position */
			void insert (iterator position, size_type n, const value_type& val)
			{
				list_node *node = _find_node(position);
				list_node *new_node = NULL;
				list_node *tmp = node;
				list_node *start_node = NULL;
				bool fl = true;

				if (node == _start)
					fl = false;
				for (size_type i = 0; i < n; i++)
				{
					new_node = _node_alloc.allocate(1);
					_node_alloc.construct(new_node, list_node());
					_alloc.construct(&new_node->data, val);
					if (start_node == NULL)
						start_node = new_node;
					new_node->next = tmp;
					new_node->prev = tmp->prev;
					if (tmp->prev != NULL)
						tmp->prev->next = new_node;
					tmp->prev = new_node;
					_size++;
				}
				if (!fl)
					_start = start_node;
				_end->next = _start;
				_start->prev = _end;
			}
			
			/* The container is extended by inserting new elements before the element at the specified position */
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL)
			{
				list_node *node = _find_node(position);
				list_node *new_node = NULL;
				list_node *tmp = node;
				list_node *start_node = NULL;
				bool fl = true;

				if (node == _start)
					fl = false;
				for (; first != last; first++)
				{
					new_node = _node_alloc.allocate(1);
					_node_alloc.construct(new_node, list_node());
					_alloc.construct(&new_node->data, *first);
					if (start_node == NULL)
						start_node = new_node;
					new_node->next = tmp;
					new_node->prev = tmp->prev;
					if (tmp->prev != NULL)
						tmp->prev->next = new_node;
					tmp->prev = new_node;
					_size++;
				}
				if (!fl)
					_start = start_node;
				_end->next = _start;
				_start->prev = _end;
			}

			/* Removes from the list container either a single element */
			iterator erase(iterator position)
			{
				list_node *node = _find_node(position);
				list_node *tmp = node->next;
				
				if (node != _start)
					node->prev->next = tmp;
				else
					_start = tmp;
				tmp->prev = node->prev;
				_alloc.destroy(&node->data);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
				_size--;
				_end->next = _start;
				_start->prev = _end;
				return (tmp);
			}

			/* Removes from the list container either a range of elements */
			iterator erase(iterator first, iterator last)
			{
				list_node *node = _find_node(first);
				list_node *tmp = node->next;
				bool fl = false;

				if (_start == node)
					fl = true;
				for (; first != last; first++)
				{
					if (!fl)
						node->prev->next = tmp;
					tmp->prev = node->prev;
					_alloc.destroy(&node->data);
					_node_alloc.destroy(node);
					_node_alloc.deallocate(node, 1);
					node = tmp;
					tmp = tmp->next;
					_size--;
				}
				if (fl)
					_start = node;
				_end->next = _start;
				_start->prev = _end;
				return node;
			}

			/* Removes from the container all the elements that compare equal to val. 
			This calls the destructor of these objects and reduces the container size 
			by the number of elements removed */
			void remove (const value_type& val)
			{
				list_node *save;
				for (list_node *tmp = _start; tmp != _end;)
				{
					save = tmp->next;
					if (tmp->data == val)
						erase(tmp);
					tmp = save;
				}
			}

			/* Removes from the container all the elements for which Predicate pred 
			returns true. This calls the destructor of these objects and reduces the 
			container size by the number of elements removed. */
			template <class Predicate>
  			void remove_if (Predicate pred)
			{
				list_node *save;
				
				for (list_node *tmp = _start; tmp != _end;)
				{
					save = tmp->next;
					if (pred(tmp->data))
						erase(tmp);
					tmp = save;
				}
			}

			/* Removes all but the first element from every consecutive group of equal elements in the container */
			void unique()
			{
				for (list_node *tmp = _start; tmp != _end; tmp = tmp->next)
					if (tmp != _start)
						if (tmp->data == tmp->prev->data)
							erase(tmp->prev);
			}

			/* Takes as argument a specific comparison function that determine 
			the "uniqueness" of an element. In fact, any behavior can be implemented 
			(and not only an equality comparison), but notice that the function will call 
			binary_pred(*i,*(i-1)) for all pairs of elements (where i is an iterator to an element, 
			starting from the second) and remove i from the list if the predicate returns true */
			template <class BinaryPredicate>
  			void unique (BinaryPredicate binary_pred)
			{
				for (list_node *tmp = _start; tmp != _end; tmp = tmp->next)
					if (tmp != _start)
						if (binary_pred(tmp->data, tmp->prev->data))
							erase(tmp->prev);
			}

			/* Reverses the order of the elements in the list container */
			void reverse()
			{
				if (!empty())
				{
					list_node *node = _start->next;
					list_node *tmp;

					_start->next = _end;
					node->prev = NULL;
					_end->prev = _start;
					for (;node != _end;)
					{
						tmp = node->next;
						node->next = _start;
						_start->prev = node;
						node->prev = NULL;
						_start = node;
						node = tmp;
					}
					_end->next = _start;
					_start->prev = _end;
				}
			}

			/* Transfers elements from x into the container, inserting them at position. 
			Transfers all the elements of x into the container */
			void splice (iterator position, list& x)
			{
				while (!x.empty())
				{
					insert(position, x.front());
					x.pop_front();
				}
			}

			/* Transfers elements from x into the container, inserting them at position.
			Transfers only the element pointed by i from x into the container */
			void splice (iterator position, list& x, iterator i)
			{
				insert(position, *i);
				x.erase(i);
			}

			/* Transfers elements from x into the container, inserting them at position. 
			transfers the range [first,last) from x into the container. */
			void splice (iterator position, list& x, iterator first, iterator last)
			{
				for (; first != last;)
				{
					insert(position, *first);
					first = x.erase(first);
				}
			}

			/* Resizes the container so that it contains n elements */
			void resize (size_type n, value_type val = value_type())
			{
				size_type max = n > _size ? n : _size;
				iterator k(_start);

				for (size_type i = 0; i < max; i++)
				{
					if (i >= n)
						k = erase(k);
					else
						if (i >= _size)
							push_back(val);
						else
							k++;
				}
				_end->next = _start;
				_start->prev = _end;
			}

			/* Sorts the elements in the list, altering their position within the container */
			void sort()
			{
				list_node *min;
				list_node *tmp;
				list_node *tmp1;
				for (tmp = _start; tmp != _end; )
				{
					min = tmp;
					for (tmp1 = tmp; tmp1 != _end; tmp1 = tmp1->next)
						if (min->data > tmp1->data)
							min = tmp1;
					if (tmp->next != NULL)
						tmp->next->prev = min;
					if (min->next != NULL)
						min->next->prev = tmp;
					list_node *save = tmp->next;
					tmp->next = min->next;
					min->next = save;
					if (tmp->prev != NULL)
						tmp->prev->next = min;
					if (min->prev != NULL)
						min->prev->next = tmp;
					save = tmp->prev;
					tmp->prev = min->prev;
					min->prev = save;
					if (tmp == _start)
						_start = min;
					tmp = min->next;
				}
				_end->next = _start;
				_start->prev = _end;
			}

			/* Sorts the elements in the list, altering their position within the container */
			template <class Compare>
  			void sort (Compare comp)
			{
				list_node *min;
				list_node *tmp;
				list_node *tmp1;
				for (tmp = _start; tmp != _end; )
				{
					min = tmp;
					for (tmp1 = tmp; tmp1 != _end; tmp1 = tmp1->next)
						if (comp(tmp1->data, min->data))
							min = tmp1;
					if (tmp->next != NULL)
						tmp->next->prev = min;
					if (min->next != NULL)
						min->next->prev = tmp;
					list_node *save = tmp->next;
					tmp->next = min->next;
					min->next = save;
					if (tmp->prev != NULL)
						tmp->prev->next = min;
					if (min->prev != NULL)
						min->prev->next = tmp;
					save = tmp->prev;
					tmp->prev = min->prev;
					min->prev = save;
					if (tmp == _start)
						_start = min;
					tmp = min->next;
				}
				_end->next = _start;
				_start->prev = _end;
			}

			/* Merges x into the list by transferring all of its elements at their respective 
			ordered positions into the container (both containers shall already be ordered) */
			void merge (list& x)
			{
				if (&x != this)
				{
					list_node *t_node = _start;
					list_node *x_node = x._start;
					list_node *save1;

					while (t_node != _end && x_node != x._end)
					{
						if (x_node->data < t_node->data)
						{
							save1 = x_node->next;
							if (t_node->prev != NULL)
								t_node->prev->next = x_node;
							x_node->prev = t_node->prev;
							x_node->next->prev = NULL;
							x_node->next = t_node;
							t_node->prev = x_node;
							x._size--;
							if (t_node == _start)
								_start = x_node;
							x_node = save1;
							_size++;
						}
						else
							t_node = t_node->next;
					}
					if (x_node != x._end)
					{
						while (x_node != x._end)
						{
							save1 = x_node->next;
							
							x_node->next = _end;
							x_node->prev = _end->prev;
							if (_end->prev)
								_end->prev->next = x_node;
							_end->prev = x_node;
							save1->prev = NULL;
							x._size--;
							_size++;
							x_node = save1;
						}
					}
					x._start = x._end;
					_end->next = _start;
					_start->prev = _end;
					x._end->next = x._start;
					x._start->prev = x._end;
				}
			}

			/* Merges x into the list by transferring all of its elements at their respective 
			ordered positions into the container (both containers shall already be ordered) */
			template <class Compare>
  			void merge (list& x, Compare comp)
			{
				if (&x != this)
				{
					list_node *t_node = _start;
					list_node *x_node = x._start;
					list_node *save1;

					while (t_node != _end && x_node != x._end)
					{
						if (comp(x_node->data, t_node->data))
						{
							save1 = x_node->next;
							if (t_node->prev != NULL)
								t_node->prev->next = x_node;
							x_node->prev = t_node->prev;
							x_node->next->prev = NULL;
							x_node->next = t_node;
							t_node->prev = x_node;
							x._size--;
							if (t_node == _start)
								_start = x_node;
							x_node = save1;
							_size++;
						}
						else
							t_node = t_node->next;
					}
					if (x_node != x._end)
					{
						while (x_node != x._end)
						{
							save1 = x_node->next;
							
							x_node->next = _end;
							x_node->prev = _end->prev;
							if (_end->prev)
								_end->prev->next = x_node;
							_end->prev = x_node;
							save1->prev = NULL;
							x._size--;
							_size++;
							x_node = save1;
						}
					}
					x._start = x._end;
					_end->next = _start;
					_start->prev = _end;
					x._end->next = x._start;
					x._start->prev = x._end;
				}
			}

		protected:

			typedef ft::bidirectional_nodes<T>			list_node;
			typedef typename std::allocator<list_node>	node_allocator_type;

			allocator_type			_alloc;
			list_node				*_start;
			list_node				*_end;
			size_type				_size;
			node_allocator_type		_node_alloc;

			/* find node from iterator */
			list_node* _find_node(iterator p)
			{
				list_node *tmp = _start;
				
				for (iterator k(_start); k != p; k++)
					tmp = tmp->next;
				return tmp;
			}
			
	};

	/* The contents of container x are exchanged with those of y. Both container objects 
	must be of the same type (same template parameters), although sizes may differ.The contents of 
	container x are exchanged with those of y. Both container objects must be of the same type (same 
	template parameters), although sizes may differ */
	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y)
	{ x.swap(y); }
	
	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		typename ft::list<T>::const_iterator k = lhs.begin();
		typename ft::list<T>::const_iterator s = rhs.begin();

		for (; k != lhs.end() && s != rhs.end(); k++, s++)
			if (*k != *s)
				return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		typename ft::list<T>::const_iterator first1 = lhs.begin();
		typename ft::list<T>::const_iterator last1 = lhs.end();
		typename ft::list<T>::const_iterator first2 = rhs.begin();
		typename ft::list<T>::const_iterator last2 = rhs.end();
	
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else 
				if (*first1 < *first2) 
					return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}
	
	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{ return !(lhs == rhs); }

	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{ return !(rhs < lhs); }

	template <class T, class Alloc>
  	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{ return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{ return !(lhs < rhs); }
}


#endif
