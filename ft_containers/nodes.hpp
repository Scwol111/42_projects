/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:46:50 by tclaudin          #+#    #+#             */
/*   Updated: 2021/04/23 16:18:59 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_HPP
#define NODES_HPP

namespace ft
{
	template <class T>
	struct bidirectional_nodes
	{
		T					data;
		bidirectional_nodes	*prev;
		bidirectional_nodes	*next;

		bidirectional_nodes(): data()
		{
			prev = NULL;
			next = NULL;
		}
		bidirectional_nodes(const bidirectional_nodes &x)
		{
			data = x.data;
			prev = x.prev;
			next = x.next;
		}
		bidirectional_nodes(const bidirectional_nodes *x)
		{
			data = x->data;
			next = x->next;
			prev = x->prev;
		}
		bidirectional_nodes(const T &x): data(x)
		{
			next = NULL;
			prev = NULL;
		}
		bidirectional_nodes(const T *x): data(*x)
		{
			next = NULL;
			prev = NULL;
		}
		bidirectional_nodes(const T& d, bidirectional_nodes *p, bidirectional_nodes *n): data(d)
		{
			prev = p;
			next = n;
		}
	};
	
	template <class T>
	struct binary_tree_nodes
	{
		T					data;
		binary_tree_nodes	*left;
		binary_tree_nodes	*right;
		binary_tree_nodes	*prev;
		char				color;

		binary_tree_nodes(): data()
		{
			prev = NULL;
			left = NULL;
			right = NULL;
			color = 'r';
		}
		binary_tree_nodes(const binary_tree_nodes &x)
		{
			data = x.data;
			prev = x.prev;
			left = x.left;
			right = x.right;
			color = 'r';
		}
		binary_tree_nodes(const binary_tree_nodes *x)
		{
			data = x->data;
			left = x->left;
			prev = x->prev;
			right = x->right;
			color = 'r';
		}
		binary_tree_nodes(const T &x): data(x)
		{
			prev = NULL;
			left = NULL;
			right = NULL;
			color = 'r';
		}
		binary_tree_nodes(const T *x): data(*x)
		{
			prev = NULL;
			left = NULL;
			right = NULL;
			color = 'r';
		}
		binary_tree_nodes(const T& d, binary_tree_nodes *p, binary_tree_nodes *l, binary_tree_nodes *r): data(d)
		{
			prev = p;
			left = l;
			right = r;
			color = 'r';
		}
		
	};
}

#endif