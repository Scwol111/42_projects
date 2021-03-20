/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   URI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:02:55 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/14 16:25:59 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef URI_HPP
#define URI_HPP

#include "BNF.hpp"
#include <vector>
#include <string>

#include <iostream>

class URI {
public:
	class Reference {
	private:
		BNF::ViewTree	m_tree;

	public:
		Reference(const std::string &ref) {
			ViewData	view(ref);
			m_tree = g_bnf.make_tree("URI-reference", view);
			if (view.size() != 0) {
				m_tree.clear();
			}
		}
		Reference(const Reference &ref): m_tree(ref.m_tree) {}
		~Reference() {}
		Reference	&operator=(const Reference &ref) {
			m_tree = ref.m_tree;
			return *this;
		}

		void			clear() {
			m_tree.clear();
		}
		std::string		to_string() const {
			return m_tree.begin().value().to_string();
		}
		BNF::ViewTree::Iter	begin() const {
			return m_tree.begin();
		}
		bool	is_ok() const {
			return !m_tree.empty();
		}
	};

private:
	BNF::ViewTree	m_tree;

public:
	URI() {}
	URI(const std::string &uri) {
		ViewData	view(uri);
		m_tree = g_bnf.make_tree("URI", view);
		if (view.size() != 0) {
			m_tree.clear();
		}
	}
	~URI() {}
	URI(const URI &uri): m_tree(uri.m_tree) {}
	URI		&operator=(const URI &uri) {
		m_tree = uri.m_tree;
		return *this;
	}

	void			clear() {
		m_tree.clear();
	}
	std::string		to_string() const {
		return m_tree.begin().value().to_string();
	}
	BNF::ViewTree	to_base_URI() const {
		BNF::ViewTree	tree = m_tree;
		tree.begin().get("[ '#' fragment ]").unlink();
		return (tree);
	}
	BNF::ViewTree::Iter	begin() const {
		return m_tree.begin();
	}
	bool			is_ok() const {
		return !m_tree.empty();
	}



	URI			transform_reference(const Reference &ref) const;
	std::string	transform_reference_to_string(const Reference &ref) const;

	bool				is_authority() const;
	const ViewData	&get_scheme() const;
	const ViewData	&get_authority() const;
	const ViewData	&get_path() const;
	const ViewData	&get_query() const;
	const ViewData	&get_fragment() const;

	std::string	get_merged_path_string(const ViewData &) const;

	static	std::string	remove_dot_segments_from_path(const ViewData &);

};


#endif /* URI_HPP */
