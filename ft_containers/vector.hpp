/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:39:00 by tclaudin          #+#    #+#             */
/*   Updated: 2021/05/02 14:18:49 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "iterator.hpp"
#include "exception.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::RandomAccessIterator<value_type>		iterator;
		typedef ft::RandomAccessIterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		/* Default constructor*/
		explicit vector(const allocator_type& alloc = allocator_type()): 
			_array(NULL), _capacity(0), _size(0), _alloc(alloc)
		{
		}

		/* Fill constructor */
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc)
		{
			_size = n;
			_capacity = n;

			T 	*p;
			_array = _alloc.allocate(n);
			p = _array;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(p++, val);
		}

		/* Range constructor */
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
		char (*)[sizeof(*first)] = NULL): _alloc(alloc)
		{
			size_type	size = 0;
			value_type	*p;
			for (InputIterator i = first; i != last; i++)
				size++;
			_array = _alloc.allocate(size);
			_capacity = size;
			_size = size;
			p = _array;
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(p++, *first++);
		}

		/* Copy constructor */
		vector (const vector& x)
		{
			*this = x;
		}

		/* Destructor */
		virtual ~vector()
		{
			clear();
			_alloc.deallocate(_array, _capacity);
			_array = NULL;
		}

		/* Assigment operator */
		vector& operator= (const vector& x)
		{
			if (_array != NULL && _capacity != 0)
			{
				clear();
				_alloc.deallocate(_array, _capacity);
				_array = NULL;
				_capacity = 0;
			}
			if (this != &x)
			{
				T 	*p;
				
				_size = x._size;
				_alloc = x._alloc;
				_capacity = x._capacity;
				_array = _alloc.allocate(_capacity);
				p = _array;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(p++, x._array[i]);
			}
			return *this;
		}

		/* Access operator */
		reference operator[] (size_type n)
		{
			return _array[n];
		}

		/* Const Access operator */
		const_reference operator[] (size_type n) const
		{
			return _array[n];
		}

		/* Size of array */
		size_type size() const
		{
			return _size;
		}

		/* Max number of elements T */
		size_type max_size() const
		{
			return _alloc.max_size();
		}

		/* Resize array. If new size > old size then add new elements, else delete last */
		void resize(size_type n, value_type val = value_type())
		{
			T *new_array;
			T *p;
			
			new_array = _alloc.allocate(n);
			p = new_array;
			for (size_type i = 0; i < n; i++)
				if (i < _size)
					_alloc.construct(p++, _array[i]);
				else
					_alloc.construct(p++, val);
			clear();
			_alloc.deallocate(_array, _capacity);
			_array = new_array;
			_size = n;
			if (n > _capacity)
				_capacity = n;
		}

		/* Size of allocated memory */
		size_type capacity() const
		{
			return _capacity;
		}

		/* Check Does vector have any elements? */
		bool empty() const
		{
			if (_size > 0)
				return false;
			return true;
		}

		/* Change capacity to store at least n number of elements */
		void reserve (size_type n)
		{
			if (_capacity < n)
			{
				T *new_array, *p;
				size_type save_size = _size;

				new_array = _alloc.allocate(n);
				p = new_array;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(p++, _array[i]);
				clear();
				_alloc.deallocate(_array, _capacity);
				_size = save_size;
				_array = new_array;
				_capacity = n;
			}
		}

		/* Returns a reference to the element at position n */
		reference at (size_type n)
		{
			if (n < 0 || n > _size)
				throw ft::IndexOutOfRangeException();
			return _array[n];
		}

		/* Returns a constant reference to the element at position n */
		const_reference at (size_type n) const
		{
			if (n < 0 || n > _size)
				throw ft::IndexOutOfRangeException();
			return _array[n];
		}

		/* Returns a reference to the first element in the vector */
		reference front() { return _array[0]; }

		/* Returns a constant reference to the first element in the vector */
		const_reference front() const { return _array[0]; }

		/* Returns a reference to the last element in the vector */
		reference back() { return _array[_size - 1]; }

		/* Returns a constant reference to the last element in the vector */
		const_reference back() const { return _array[_size - 1]; }

		/* Removes all elements from the vector (which are destroyed), leaving the container with a size of 0 */
		void clear()
		{
			T *p;

			p = _array;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(p++);
			_size = 0;
		}

		/* Adds a new element at the end of the vector, after its current last element. The content of val is copied 
		(or moved) to the new element. */
		void push_back (const value_type& val)
		{
			size_type old_size = _size;
			size_type old_capacity = _capacity;
			size_type new_capacity = _capacity * 2;
			T *new_array, *p;

			if (_size + 1 >= _capacity)
			{
				if (new_capacity == 0)
					new_capacity = 2;
				new_array = _alloc.allocate(new_capacity);
				p = new_array;

				for (size_type i = 0; i < _size; i++)
					_alloc.construct(p++, _array[i]);

				clear();
				_alloc.deallocate(_array, old_capacity);
				_size = old_size;
				_array = new_array;
				_capacity = new_capacity;
			}
			_alloc.construct(_array + _size, val);
			_size++;
		}

		/* Removes the last element in the vector, effectively reducing the container size by one */
		void pop_back()
		{
			_alloc.destroy(_array + _size - 1);
			_size--;
		}

		/* Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly */
		void assign(size_type n, const value_type& val)
		{
			T *new_array = _array, *p;
			clear();
			if (_capacity < n)
			{
				new_array = _alloc.allocate(n);
				p = new_array;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(p++, val);
				_alloc.deallocate(_array, _capacity);
				_capacity = n;
			}
			else
			{
				p = new_array;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(p++, val);
			}
			_size = n;
			_array = new_array;
		}

		/* Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL)
		{
			size_type size = 0;
			
			for (InputIterator i = first; i != last; i++)
				size++;
			T *new_array = _array, *p;
			clear();
			if (_capacity < size)
			{
				new_array = _alloc.allocate(size);
				p = new_array;
				for (; first != last; first++)
					_alloc.construct(p++, *first);
				_alloc.deallocate(_array, _capacity);
				_capacity = size;
			}
			else
			{
				p = new_array;
				for (; first != last; first++)
					_alloc.construct(p++, *first);
			}
			_size = size;
			_array = new_array;
		}

		/* Exchanges the content of the container by the content of x, which is another vector object of the same type. 
		Sizes may differ */
		void swap(vector& x)
		{
			T *save_array = _array;
			size_type save_size = _size;
			size_type save_capacity = _capacity;
			
			_array = x._array;
			_size = x._size;
			_capacity = x._capacity;

			x._array = save_array;
			x._size = save_size;
			x._capacity = save_capacity;
		}

		/* Returns an iterator pointing to the first element in the vector */
		iterator begin() {return _array;}

		/* Returns an iterator pointing to the first element in the vector */
		const_iterator begin() const {return _array;}

		/* Returns an iterator referring to the past-the-end element in the vector container */
		iterator end()
		{
			if (empty())
				return _array;
			return _array + _size;
		}

		/* Returns an iterator referring to the past-the-end element in the vector container */
		const_iterator end() const
		{
			if (empty())
				return _array;
			return _array + _size;
		}

		/* Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning) */
		reverse_iterator rbegin() {return reverse_iterator(end());}
		
		/* Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning) */
		const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}

		/* Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
		(which is considered its reverse end) */
		reverse_iterator rend() {return reverse_iterator(begin());}

		/* Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector 
		(which is considered its reverse end) */
		const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

		/* The vector is extended by inserting new elements before the element at the specified position, effectively 
		increasing the container size by the number of elements inserted */
		iterator insert (iterator position, const value_type& val)
		{
			value_type	*new_array, *p;
			size_type	old_size = _size;
			size_type	new_cap = _capacity;
			bool		fl = false;
			bool		hs_rt = false;
			iterator	ret;

			fl = true;
			if (_size + 1 >= _capacity)
			{
				new_cap *= 2;
				if (new_cap == 0)
					new_cap = 1;
			}
			new_array = _alloc.allocate(new_cap);
			p = new_array;
			for (iterator k = begin(); k < end(); k++)
			{
				if (k == position)
				{
					ret = iterator(p);
					_alloc.construct(p++, val);
					hs_rt = true;
				}
				_alloc.construct(p++, *k);
			}
			if (p == new_array)
				_alloc.construct(p++, val);
			if (fl)
			{
				clear();
				_alloc.deallocate(_array, _capacity);
				_capacity = new_cap;
			}
			_size = old_size + 1;
			_array = new_array;
			if (!hs_rt)
				return begin();
			return ret;
		}

		/* The vector is extended by inserting new elements before the element at the specified position, effectively 
		increasing the container size by the number of elements inserted */
		void insert (iterator position, size_type n, const value_type& val)
		{
			value_type	*new_array, *p;
			size_type	old_size = _size;
			size_type	new_capacity = _capacity;
			bool		fl = false;

			fl = true;
			if (_size + n >= _capacity)
			{
				if (_capacity == 0)
					new_capacity = 1;
				while (new_capacity <= _size + n)
					new_capacity *= 2;
			}			
			new_array = _alloc.allocate(new_capacity);
			p = new_array;
			for (iterator k = begin(); k < end(); k++)
			{
				if (k == position)
					for (size_type i = 0; i < n; i++)
						_alloc.construct(p++, val);
				_alloc.construct(p++, *k);
			}
			if (p == new_array)
				for (size_type i = 0; i < n; i++)
						_alloc.construct(p++, val);
			if (fl)
			{
				clear();
				_alloc.deallocate(_array, _capacity);
				_capacity = new_capacity;
			}
			_size = old_size + n;
			_array = new_array;
		}

		/* The vector is extended by inserting new elements before the element at the specified position, effectively 
		increasing the container size by the number of elements inserted */
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL)
		{
			value_type	*new_array, *p;
			size_type	old_size = _size;
			size_type	new_capacity = _capacity;
			size_type	n = ft::distance(first, last);
			bool		fl = false;

			fl = true;
			if (_size + n >= _capacity)
			{
				if (_capacity == 0)
					new_capacity = 1;
				while (new_capacity <= _size + n)
					new_capacity *= 2;
			}			
			new_array = _alloc.allocate(new_capacity);
			p = new_array;
			for (iterator k = begin(); k < end(); k++)
			{
				if (k == position)
					for (; first < last; first++)
						_alloc.construct(p++, *first);
				_alloc.construct(p++, *k);
			}
			if (p == new_array)
				for (size_type i = 0; i < n; i++)
						_alloc.construct(p++, *first);
			if (fl)
			{
				clear();
				_alloc.deallocate(_array, _capacity);
				_capacity = new_capacity;
			}
			_size = old_size + n;
			_array = new_array;
		}

		/* Removes from the vector either a single element (position) */
		iterator erase (iterator position)
		{
			iterator ret;

			ret = position + 1;
			for (iterator i = position + 1; i < end(); i++)
			{
				_alloc.destroy((i - 1).base());
				_alloc.construct((i - 1).base(), *i);
			}
			_size--;
			if (_size == 0)
				return end();
			ret--;
			return ret;
		}

		/* Removes from the vector either a range of elements ([first,last)) */
		iterator erase (iterator first, iterator last)
		{
			iterator ret = first;
			size_type	n = 0;
			for (iterator i = first; i < last; i++)
				n++;
			for (;first < end(); first++)
			{
				_alloc.destroy(first.base());
				if (first + n < end())
					_alloc.construct(first.base(), *(first + n));
			}
			_size -= n;
			return ret;
		}

	protected:
		T				*_array;
		size_t			_capacity;
		size_t			_size;
		allocator_type	_alloc;
	};

	/* The contents of container x are exchanged with those of y. Both container objects must be of the same type 
	(same template parameters), although sizes may differ. */
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;		
		return true;
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs == rhs)
			return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		size_t i;
		
		for (i = 0; i < lhs.size(); i++)
		{
			if (i == rhs.size() || rhs[i] < lhs[i])
				return false;
			else if (lhs[i] < rhs[i])
				return true;
		}
		return (i != rhs.size());
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }
	
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
}

#endif
