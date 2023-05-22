/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:42:24 by tclaudin          #+#    #+#             */
/*   Updated: 2021/05/02 13:48:17 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include "nodes.hpp"

namespace ft
{
	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct forward_iterator_tag {};
	struct output_iterator_tag {};
	struct input_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&> 
	class iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};

	template <class Iterator> 
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t					difference_type;
			typedef T							value_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef random_access_iterator_tag	iterator_category;
	};
	template <class T> 
	class iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t					difference_type;
			typedef T							value_type;
			typedef const T*					pointer;
			typedef const T&					reference;
			typedef random_access_iterator_tag	iterator_category;
	};

	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n)
	{
		for (; n >= 0; n--)
			it++;
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		for (;first != last; first++) n++;
		return n;
	}

	template <class T>
	class RandomAccessIterator: public iterator<random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef T*																			pointer;
			typedef T&																			reference;
		
			RandomAccessIterator() {_data = NULL;}
			RandomAccessIterator(RandomAccessIterator const &x) {_data = x._data;}
			RandomAccessIterator(T* x) {_data = x;}
			virtual ~RandomAccessIterator() {}
			
			RandomAccessIterator& operator=(const RandomAccessIterator &x) 
			{
				if (this == &x)
					return *this;
				_data = x._data; 
				return *this;
			}
			pointer base() const {return _data;}
			reference operator* () {return *_data;}
			pointer operator-> () {return this->_data;}
			RandomAccessIterator operator++ () {return ++_data;}
			RandomAccessIterator operator++ (int) 
			{
				RandomAccessIterator copy(*this);
				_data++;
				return copy;
			}
			RandomAccessIterator operator-- () {return --_data;}
			RandomAccessIterator operator-- (int)
			{
				RandomAccessIterator copy(*this);
				_data--;
				return copy;
			}
			RandomAccessIterator operator+ (difference_type n) const {return (_data + n);}
			RandomAccessIterator operator- (difference_type n) const {return (_data - n);}
			RandomAccessIterator operator+= (difference_type n)
			{
				_data += n;
				return _data;
			}
			RandomAccessIterator operator-= (difference_type n)
			{
				_data -= n;
				return _data;
			}
			RandomAccessIterator operator= (difference_type n)
			{
				_data -= n;
				return _data;
			}
			reference operator[] (difference_type n)
			{
				return (*(_data + n));
			}
		protected:
			value_type* _data;
	};

	template <class T>
	typename RandomAccessIterator<T>::difference_type operator== (const RandomAccessIterator<T> a, const RandomAccessIterator<T> b) 
	{
		return (a.base() == b.base());
	}
	template <class T>
	typename RandomAccessIterator<T>::difference_type operator!= (const RandomAccessIterator<T> a, const RandomAccessIterator<T> b) 
	{
		return (a.base() != b.base());
	}
	template <class T>
	typename RandomAccessIterator<T>::difference_type operator< (const RandomAccessIterator<T> a, const RandomAccessIterator<T> b)
	{
		return (a.base() < b.base());
	}
	template <class T>
	typename RandomAccessIterator<T>::difference_type operator<= (const RandomAccessIterator<T> a, const RandomAccessIterator<T> b)
	{
		return (a.base() <= b.base());
	}
	template <class T>
	typename RandomAccessIterator<T>::difference_type operator> (const RandomAccessIterator<T> a, const RandomAccessIterator<T> b)
	{
		return (a.base() > b.base());
	}
	template <class T>
	typename RandomAccessIterator<T>::difference_type operator>= (const RandomAccessIterator<T> a, const RandomAccessIterator<T> b)
	{
		return (a.base() >= b.base());
	}

	template <class T>
	class BidirectionalIterator: public iterator<bidirectional_iterator_tag, T>
	{
		protected:
			typedef typename ft::bidirectional_nodes<T> node_type;
			
			node_type	*_node;
			
		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef T*																			pointer;
			typedef T&																			reference;

			BidirectionalIterator() { _node = NULL;}
			BidirectionalIterator(const node_type &x) { _node = &x; }
			BidirectionalIterator(node_type const *x) { _node = x; }
			BidirectionalIterator(const BidirectionalIterator &x) { _node = x._node; }

			BidirectionalIterator(node_type *const x) { _node = x;}

			virtual ~BidirectionalIterator() {}

			BidirectionalIterator &operator= (const BidirectionalIterator &x)
			{
				if (&x != this)
					_node = x._node;
				return  *this;
			}
			reference				operator* () {return _node->data;}
			pointer					operator-> () {return &_node->data;}
			BidirectionalIterator	operator++ ()
			{
				_node = _node->next;
				return *this;
			}
			BidirectionalIterator	operator++ (int)
			{
				BidirectionalIterator ret(*this);
				_node = _node->next;
				return ret;
			}
			BidirectionalIterator operator-- ()
			{
				_node = _node->prev;
				return *this;
			}
			BidirectionalIterator	operator-- (int)
			{
				BidirectionalIterator ret(*this);
				_node = _node->prev;
				return ret;
			}
			friend difference_type operator== (const BidirectionalIterator<T> lhs, const BidirectionalIterator<T> rhs)
			{
				return (lhs._node == rhs._node);
			}
			friend difference_type operator!= (const BidirectionalIterator<T> lhs, const BidirectionalIterator<T> rhs)
			{
				return (lhs._node != rhs._node);
			}
	};

	template <class T>
	class BinaryTreeIterator: public iterator<bidirectional_iterator_tag, T>
	{
		protected:
			typedef typename ft::binary_tree_nodes<T> node_type;
			
			node_type	*_node;
			
		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef T*																			pointer;
			typedef T&																			reference;

			BinaryTreeIterator() { _node = NULL;}
			BinaryTreeIterator(const node_type &x) { _node = &x; }
			BinaryTreeIterator(node_type const *x) { _node = x; }
			BinaryTreeIterator(const BinaryTreeIterator &x) { _node = x._node; }
			BinaryTreeIterator(node_type *const x) { _node = x;}

			virtual ~BinaryTreeIterator() {}

			BinaryTreeIterator		&operator= (const BinaryTreeIterator &x)
			{
				if (&x != this)
					_node = x._node;
				return  *this;
			}
			reference				operator* () { return _node->data; }
			pointer					operator-> () { return &_node->data; }
			BinaryTreeIterator		operator++ ()
			{
				node_type *tmp;

				if (_node->right)
				{
					tmp = _node->right;
					while (tmp->left != NULL)
						tmp = tmp->left;
				}
				else
				{
					tmp = _node->prev;
					while (tmp->prev && _node->data > tmp->data)
						tmp = tmp->prev;
				}
				_node = tmp;
				return *this;
			}
			BinaryTreeIterator		operator++ (int)
			{
				BinaryTreeIterator ret(*this);

				operator++();
				return ret;
			}
			BinaryTreeIterator		operator--()
			{
				node_type *tmp;

				if (_node->left)
				{
					tmp = _node->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
				}
				else
				{
					tmp = _node->prev;
					while (tmp->prev && tmp->prev->data > _node->data)
						tmp = tmp->prev;
				}
				_node = tmp;
				return *this;
			}
			BinaryTreeIterator		operator-- (int)
			{
				BinaryTreeIterator ret(*this);

				operator--();
				return ret;
			}
			friend difference_type operator== (const BinaryTreeIterator<T> lhs, const BinaryTreeIterator<T> rhs)
			{
				return (lhs._node == rhs._node);
			}
			friend difference_type operator!= (const BinaryTreeIterator<T> lhs, const BinaryTreeIterator<T> rhs)
			{
				return (lhs._node != rhs._node);
			}
	};
	

	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type		value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer			pointer;
			typedef typename ft::iterator_traits<Iterator>::reference		reference;
			
			reverse_iterator(): _data() {}
			explicit reverse_iterator (iterator_type it): _data(it) {}
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it): _data(rev_it._data) {}
			virtual ~reverse_iterator() {}

			iterator_type base() const {return _data;}
			reference operator*() const 
			{
				iterator_type tmp = _data;
				return *(--tmp);
			}
			reverse_iterator operator+ (difference_type n) const {return (reverse_iterator(_data - n));}
			reverse_iterator& operator++() 
			{
				--_data;
				return *this;
			}
			reverse_iterator  operator++(int)
			{
				reverse_iterator tmp = *this;
				--_data;
				return tmp;
			}
			reverse_iterator& operator+= (difference_type n)
			{
				_data -= n;
				return *this;
			}
			reverse_iterator operator- (difference_type n) const {return (reverse_iterator(_data + n));}
			reverse_iterator& operator--()
			{
				_data++;
				return *this;
			}
			reverse_iterator  operator--(int)
			{
				reverse_iterator tmp = *this;
				_data++;
				return tmp;
			}
			reverse_iterator& operator-= (difference_type n)
			{
				_data += n;
				return *this;
			}
			reverse_iterator& operator= (reverse_iterator &iter) 
			{
				_data = iter._data;
				return *this;
			}
			pointer operator->() const {return &(operator*());}
			reference operator[] (difference_type n) const {return (base()[-n - 1]);}

		protected:
			iterator_type	_data;
	};
	
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, 
	const reverse_iterator<Iterator>& rev_it) {return (rev_it + n);}
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- 
	(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (lhs.base() - rhs.base());}

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (lhs.base() == rhs.base());}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return ((lhs.base() != rhs.base()));}

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return ((lhs.base() > rhs.base()));}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return ((lhs.base() >= rhs.base()));}

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return ((lhs.base() < rhs.base()));}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return ((lhs.base() <= rhs.base()));}

}

#endif
