/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:39:05 by tclaudin          #+#    #+#             */
/*   Updated: 2021/05/02 14:23:40 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include "nodes.hpp"
#include "iterator.hpp"
#include <memory>

namespace ft
{
    template < class Key, class T,class Compare = ft::less<Key>,class Alloc = std::allocator<ft::pair<const Key,T> > > 
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<key_type, mapped_type>				value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			typedef ft::BinaryTreeIterator<value_type>			iterator;
			typedef ft::BinaryTreeIterator<value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			class value_compare
			{   
				friend class map<Key, T, Compare, Alloc>;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			/* Constructs an empty container, with no elements */
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _node_alloc(), _size(0), _comp(comp)
			{
				_end = _node_alloc.allocate(1);
				_node_alloc.construct(_end, node_type());
			}

			/* Constructs a container with as many elements as the range [first,last), with each 
			element constructed from its corresponding element in that range */
			template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), 
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _node_alloc(), _size(0), _comp(comp)
			{
				bool fl = false;
				_end = _node_alloc.allocate(1);
				_node_alloc.construct(_end, node_type());
				for (; first != last; first++)
				{
					value_type tmp((*first).first, (*first).second);
					_add_node(tmp, fl);
				}
			}

			/* Constructs a container with a copy of each of the elements in x */
			map (const map& x): _alloc(x._alloc), _node_alloc(), _end(NULL), _size(0), _comp(x._comp)
			{
				bool fl = false;
				_end = _node_alloc.allocate(1);
				_node_alloc.construct(_end, node_type());
				for (iterator k = x.begin(); k != x.end(); k++)
					_add_node(*k, fl);
			}

			/* Destroys the container object. */
			~map()
			{
				clear();
				_node_alloc.destroy(_end);
				_node_alloc.deallocate(_end, 1);
			}

			/* Assigns new contents to the container, replacing its current content */
			map& operator= (const map& x)
			{
				_destroy_all_nodes(_end);

				bool fl = false;
				_end = _node_alloc.allocate(1);
				_node_alloc.construct(_end, node_type());
				for (iterator k = x.begin(); k != x.end(); k++)
					_add_node(*k, fl);
			}

			/* Removes all elements from the map container (which are destroyed), leaving the container with a size of 0 */
			void clear()
			{
				_destroy_all_nodes(_end->left);
				_end->left = NULL;
			}

			/* Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ */
			void swap (map& x)
			{
				node_type *tmp = x._end;
				x._end = _end;
				_end = tmp;

				difference_type size_tmp = x._size;
				x._size = _size;
				_size = size_tmp;
			}

			/* Returns an iterator referring to the first element in the map container */
			iterator begin()
			{
				node_type *tmp = _end;

				while (tmp->left)
					tmp = tmp->left;
				return (tmp);
			}

			/* Returns an iterator referring to the first element in the map container */
			const_iterator begin() const
			{
				node_type *tmp = _end;

				while (tmp->left)
					tmp = tmp->left;
				return (tmp);
			}

			/* Returns an iterator referring to the past-the-end element in the map container */
			iterator end() { return _end; }

			/* Returns an iterator referring to the past-the-end element in the map container */
			const_iterator end() const { return _end; }

			/* Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning) */
			reverse_iterator rbegin() { return reverse_iterator(_end); }

			/* Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning) */
			const_reverse_iterator rbegin() const { return const_reverse_iterator(_end); }

			/* Returns a reverse iterator pointing to the theoretical element right before the first element in 
			the map container (which is considered its reverse end) */
			reverse_iterator rend()
			{
				node_type *tmp = _end;

				while (tmp->left)
					tmp = tmp->left;
				return reverse_iterator(tmp);
			}

			/* Returns a reverse iterator pointing to the theoretical element right before the first element in 
			the map container (which is considered its reverse end) */
			const_reverse_iterator rend() const
			{
				node_type *tmp = _end;

				while (tmp->left)
					tmp = tmp->left;
				return const_reverse_iterator(tmp);
			}

			/* Returns the number of elements in the map container */
			size_type size() const { return _size; }

			/* Returns whether the map container is empty (i.e. whether its size is 0) */
			bool empty() const 
			{ return (_end->left == NULL); }

			/* Returns the maximum number of elements that the map container can hold */
			size_type max_size() const 
			{
				return _node_alloc.max_size();
			}

			/* Extends the container by inserting new elements, effectively increasing the container 
			size by the number of elements inserted */
			ft::pair<iterator, bool> insert (const value_type& val)
			{
				bool x = false;
				node_type *node = _add_node(val, x);

				return make_pair<iterator, bool>(node, x);
			}

			/* Extends the container by inserting new elements, effectively increasing the container 
			size by the number of elements inserted */
			iterator insert (iterator position, const value_type& val)
			{
				bool fl = false;
				node_type *node = _add_node(val, fl);

				(void)position;
				return node;
			}

			/* Extends the container by inserting new elements, effectively increasing the container 
			size by the number of elements inserted */
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				bool fl = false;

				for (; first != last; first++)
				{
					value_type val((*first).first, (*first).second);
					_add_node(val, fl);
				}
			}

			/* If k matches the key of an element in the container, the function returns a reference to its mapped value. 
			If k does not match the key of any element in the container, the function inserts a new element with that key 
			and returns a reference to its mapped value. Notice that this always increases the container size by one, even
			 if no mapped value is assigned to the element (the element is constructed using its default constructor) */
			mapped_type& operator[] (const key_type& k)
			{
				bool fl = false;
				node_type *node = _find_node(k);

				if (node == NULL)
				{
					node = _add_node(value_type(k, mapped_type()), fl);
				}
				return node->data.second;
			}			

			/* Returns a copy of the comparison object used by the container to compare keys */
			key_compare key_comp() const {return key_compare();}

			/* Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second */
			value_compare value_comp() const { return (value_compare(key_compare())); }

			/* Searches the container for an element with a key equivalent to k and returns an iterator to 
			it if found, otherwise it returns an iterator to map::end */
			iterator find (const key_type& k)
			{
				node_type *node = _find_node(k);

				if (node == NULL)
					return end();
				return node;
			}

			/* Searches the container for an element with a key equivalent to k and returns an iterator to 
			it if found, otherwise it returns an iterator to map::end */
			const_iterator find (const key_type& k) const
			{
				node_type *node = _find_node(k);

				if (node == NULL)
					return end();
				return node;
			}

			/* Searches the container for elements with a key equivalent to k and returns the number of matches */
			size_type count (const key_type& k) const
			{
				node_type *node = _find_node(k);

				return node == NULL ? 0 : 1;
			}

			/* Removes from the map container a single element */
			void erase (iterator position)
			{
				node_type *node = _find_node((*position).first);

				if (node != NULL)
					_destroy_node(node);
			}

			/* Removes from the map container a single element */
			size_type erase(const key_type& k)
			{
				size_type result = 0;
				node_type *node;

				while ((node = _find_node(k)) != NULL)
				{
					if (node != NULL)
						_destroy_node(node);
					result++;
				}
				return result;
			}

			/* Removes from the map container a range of elements */
			void erase (iterator first, iterator last)
			{
				node_type *node;
				iterator save;

				for (; first != last; )
				{
					save = first;
					++save;
					node = _find_node((*first).first);
					if (node)
						_destroy_node(node);
					first = save;
				}
			}

			/* Returns an iterator pointing to the first element in the container 
			whose key is not considered to go before k (i.e., either it is equivalent or goes after) */
			iterator lower_bound (const key_type& k)
			{ return _lower_bound(k); }

			/* Returns an iterator pointing to the first element in the container 
			whose key is not considered to go before k (i.e., either it is equivalent or goes after) */
			const_iterator lower_bound (const key_type& k) const
			{ return _lower_bound(k); }

			/* Returns an iterator pointing to the first element in the container whose key is considered to go after k */
			iterator upper_bound (const key_type& k)
			{
				node_type *node = _lower_bound(k);
				iterator tmp(node);

				if (node->data.first <= k)
					++tmp;
				return tmp;
			}
			
			/* Returns an iterator pointing to the first element in the container whose key is considered to go after k */
			const_iterator upper_bound (const key_type& k) const
			{
				node_type *node = _lower_bound(k);
				iterator tmp(node);

				if (node->data.first <= k)
					++tmp;
				return tmp;
			}

			/* Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k */
			ft::pair<iterator,iterator>             equal_range(const key_type& k)
			{ return make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));	}

			/* Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k */
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{ return make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));	}

		protected:
			typedef typename ft::binary_tree_nodes<value_type>	node_type;
			typedef typename std::allocator<node_type>			node_allocator_type;

			allocator_type		_alloc;
			node_allocator_type	_node_alloc;
			node_type			*_end;
			difference_type		_size;
			const Compare		&_comp;

			void	_destroy_all_nodes(node_type *node)
			{
				if (node != NULL)
				{
					_destroy_all_nodes(node->left);
					_destroy_all_nodes(node->right);
					_size--;
					_node_alloc.destroy(node);
					_node_alloc.deallocate(node, 1);
				}
			}

			node_type	*_add_node(value_type const &x, bool &add)
			{
				node_type	*tmp = _end->left;
				node_type	*new_node;
				bool		fl = false;

				if (_end->left != NULL)
				{
					while (true)
					{
						if (x.first == tmp->data.first)
							return tmp;
						if (_comp(x.first, tmp->data.first))
						{
							fl = false;
							if (tmp->left == NULL)
								break;
							tmp = tmp->left;
						}
						else
						{
							fl = true;
							if (tmp->right == NULL)
								break;
							tmp = tmp->right;
						}
					}
				}
				else
					tmp = _end;
				new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, node_type());
				new_node->data = x;
				if (!fl)
					tmp->left = new_node;
				else
					tmp->right = new_node;
				new_node->prev = tmp;
				_size++;
				_insert_case1(new_node);
				add = true;
				return new_node;
			}

			node_type *_find_node(const key_type &k) const
			{
				node_type *tmp = _end->left;

				while (tmp)
				{
					if (_comp(tmp->data.first, k))
						tmp = tmp->right;
					else
					{
						if (_comp(k, tmp->data.first))
							tmp = tmp->left;
						else
							break;
					}
				}
				return tmp;
			}

			node_type *_grandparent(node_type *n)
			{
				if ((n != NULL) && (n->prev != NULL))
					return n->prev->prev;
				else
					return NULL;
			}

			node_type *_uncle(node_type *n)
			{
				node_type *g = _grandparent(n);
				if (g == NULL)
					return NULL;
				if (n->prev == g->left)
					return g->right;
				else
					return g->left;
			}

			void _rotate_left(node_type *n)
			{
				node_type *pivot = n->right;
				
				pivot->prev = n->prev;
				if (n->prev != NULL)
				{
					if (n->prev->left == n)
						n->prev->left = pivot;
					else
						n->prev->right = pivot;
				}		
				
				n->right = pivot->left;
				if (pivot->left != NULL)
					pivot->left->prev = n;
				n->prev = pivot;
				pivot->left = n;
			}

			void _rotate_right(node_type *n)
			{
				node_type *pivot = n->left;
				
				pivot->prev = n->prev;
				if (n->prev != NULL) {
					if (n->prev->left==n)
						n->prev->left = pivot;
					else
						n->prev->right = pivot;
				}
				n->left = pivot->right;
				if (pivot->right != NULL)
					pivot->right->prev = n;
				n->prev = pivot;
				pivot->right = n;
			}

			void _insert_case1(node_type *n)
			{
				if (n->prev == _end)
					n->color = 'b';
				else
					_insert_case2(n);
			}

			void _insert_case2(node_type *n)
			{
				if (n->prev->color == 'b')
					return;
				else
					_insert_case3(n);
			}

			void _insert_case3(node_type *n)
			{
				node_type *u = _uncle(n), *g;

				if ((u != NULL) && (u->color == 'r')) 
				{
					n->prev->color = 'b';
					u->color = 'b';
					g = _grandparent(n);
					g->color = 'r';
					_insert_case1(g);
				}
				else
					_insert_case4(n);
			}

			void _insert_case4(node_type *n)
			{
				node_type *g = _grandparent(n);

				if ((n == n->prev->right) && (n->prev == g->left)) 
				{
					_rotate_left(n->prev);
					n = n->left;
				}
				else
					if ((n == n->prev->left) && (n->prev == g->right)) 
					{
						_rotate_right(n->prev);
						n = n->right;
					}
				_insert_case5(n);
			}

			void _insert_case5(node_type *n)
			{
				node_type *g = _grandparent(n);

				n->prev->color = 'b';
				g->color = 'r';
				if ((n == n->prev->left) && (n->prev == g->left))
					_rotate_right(g);
				else
					_rotate_left(g);
			}

			node_type *_lower_bound(const key_type &k) const
			{
				node_type *tmp = _end->left;

				if (!_end->left)
					return _end;
				while (tmp)
				{
					if (_comp(tmp->data.first, k))
						if (tmp->right)
							tmp = tmp->right;
						else
							break;
					else
					{
						if (_comp(k, tmp->data.first))
							if (tmp->left)
								tmp = tmp->left;
							else
								break;
						else
							break;
					}
				}
				return tmp;
			}

			node_type *_sibling(node_type *n)
			{
				if (n == n->prev->left)
					return n->prev->right;
				return n->prev->left;
			}

			void _replace_node(node_type *n, node_type *child) 
			{
				if (child == child->prev->left)
					child->prev->left = NULL;
				else
					child->prev->right = NULL;
				child->prev = n->prev;
				if (n == n->prev->left)
					n->prev->left = child;
				else
					n->prev->right = child;
			}

			void _destroy_node(node_type *node)
			{
				if (node->left && node->right)
				{
					node_type *tmp = node->left;

					while (tmp->right)
						tmp = tmp->right;
					node->data = tmp->data;
					_destroy_one_node(tmp);
				}
				else
					_destroy_one_node(node);
			}

			void _destroy_one_node(node_type *n)
			{
				node_type *child = n->right == NULL ? n->left : n->right;
				
				if (child != NULL)
				{
					_replace_node(n, child);
					if (n->color == 'b')
					{
						if (child->color == 'r')
							child->color = 'b';
						else
							_delete_case1(child->prev);
					}
				}
				else
					if (n == n->prev->left)
						n->prev->left = NULL;
					else
						n->prev->right = NULL;
				_size--;
				_node_alloc.destroy(n);
				_node_alloc.deallocate(n, 1);
			}

			void _delete_case1(node_type *n)
			{
				if (n->prev && n->prev != _end)
					_delete_case2(n);
			}

			void _delete_case2(node_type *n)
			{
				node_type *s = _sibling(n);

				if (s)
				{
					if (s->color == 'r')
					{
						n->prev->color = 'r';
						s->color = 'b';
						if (n == n->prev->left)
							_rotate_left(n->prev);
						else
							_rotate_right(n->prev);
					}
					_delete_case3(n);
				}
			}

			void _delete_case3(node_type *n)
			{
				node_type *s = _sibling(n);
				
				if (s)
				{
					if ((n->prev->color == 'b') && (s->color == 'b') && (!s->left || s->left->color == 'b') 
					&& (!s->right || s->right->color == 'b'))
					{
						s->color = 'r';
						_delete_case1(n->prev);
					}
					else
						_delete_case4(n);
				}
			}

			void _delete_case4(node_type *n)
			{
				node_type *s = _sibling(n);

				if ((n->prev->color == 'r') && (s->color == 'b') && (!s->left || s->left->color == 'b') 
				&& (!s->right || s->right->color == 'b'))
				{
					s->color = 'r';
					n->prev->color = 'b';
				}
				else
					_delete_case5(n);
			}

			void _delete_case5(node_type *n)
			{
				node_type *s = _sibling(n);

				if  (s->color == 'b') 
				{
					if ((n == n->prev->left) && (!s->right || s->right->color == 'b') && (s->left->color == 'r'))
					{
						s->color = 'r';
						s->left->color = 'b';
						_rotate_right(s);
					}
					else if ((n == n->prev->right) && (s->left->color == 'b') && (s->right->color == 'r'))
					{
						s->color = 'r';
						s->right->color = 'b';
						_rotate_left(s);
					}
				}
				_delete_case6(n);
			}

			void _delete_case6(node_type *n)
			{
				node_type *s = _sibling(n);

				s->color = n->prev->color;
				n->prev->color = 'b';

				if (n == n->prev->left)
				{
					s->right->color = 'b';
					_rotate_left(n->prev);
				}
				else
				{
					s->left->color = 'b';
					_rotate_right(n->prev);
				}
			}
	};

	/* Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ */
	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs )
	{ lhs.swap(rhs); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::map<Key,T,Compare,Alloc>::iterator it1 = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::iterator it2 = rhs.begin();

		for (; it1 != lhs.end(); it1++, it2++)
			if (*it1 != *it2)
				return false;
		return true;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		typename ft::map<Key,T,Compare,Alloc>::iterator first1 = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::iterator last1 = lhs.end();
		typename ft::map<Key,T,Compare,Alloc>::iterator first2 = rhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::iterator last2 = rhs.end();
	
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

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{ return !(lhs == rhs); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{ return !(rhs < lhs); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{ return (rhs < lhs); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{ return !(lhs < rhs); }
}

#endif
