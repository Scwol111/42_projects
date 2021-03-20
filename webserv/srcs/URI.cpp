/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   URI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:44:54 by jsandsla          #+#    #+#             */
/*   Updated: 2021/02/24 12:41:53 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "URI.hpp"
#include <cctype>
#include <cstring>
#include <sstream>

std::string		URI::transform_reference_to_string(const Reference &ref) const {
	std::ostringstream	text;
	ViewData	scheme(""), authority(""), path(""), query(""), fragment("");

	if (ref.is_ok()) {
		BNF::ViewTree::Iter	it = ref.begin();
		if (it->name == "URI") {
			scheme = it.get("scheme").value();
			it = it.get("URI");
		} else {
			it = it.get("relative-ref");
		}
		query = it.get("[ '?' query ]").get("query").value();
		fragment = it.get("[ '#' fragment ]").get("fragment").value();
		it = it.get(it.name() == "URI" ? "hier-part" : "relative-part");
		if (it->name == "//") {
			authority = it.get("authority").value();
			path = it.get("path-abempty").value();
		} else {
			path = it->value;
		}
		if (scheme.size() > 0) {
			text << scheme << ':';
			text << "//" << authority;
			text << remove_dot_segments_from_path(path);
			if (query.size() > 0) {
				text << '?' << query;
			}
		} else {
			text << get_scheme() << ':';
			if (authority.size() > 0) {
				text << "//" << authority;
				text << remove_dot_segments_from_path(path);
				if (query.size() > 0) {
					text << '?' << query;
				}
			} else {
				if (is_authority()) {
					text << "//" << get_authority();
				}
				if (path.size() == 0) {
					text << get_path();
					if (query.size() > 0) {
						text << '?' << query;
					} else {
						text << get_query();
					}
				} else {
					if (path[0] == '/') {
						text << remove_dot_segments_from_path(path);
					} else {
						text << remove_dot_segments_from_path(get_merged_path_string(path));
					}
					if (query.size() > 0) {
						text << '?' << query;
					}
				}
			}
		}
		if (fragment.size() > 0) {
			text << '#' << fragment;
		}
	}
	return text.str();
}

URI		URI::transform_reference(const Reference &ref) const {
	return URI(transform_reference_to_string(ref));
}

bool		URI::is_authority() const {
	return begin().get("hier-part").get("authority");
}

const ViewData	&URI::get_scheme() const {
	return begin().get("scheme").value();
}

const ViewData	&URI::get_authority() const {
	return begin().get("hier-part").get("authority").value();
}

const ViewData	&URI::get_path() const {
	BNF::ViewTree::Iter	it = begin().get("hier-part");
	if (it) {
		if (it->name == "//") {
			return it.get("path-abempty").value();
		} else {
			return it->value;
		}
	} else {
		return m_tree.get_empty_view();
	}
}

const ViewData	&URI::get_query() const {
	return begin().get("[ '?' query ]").get("query").value();
}

const ViewData	&URI::get_fragment() const {
	return begin().get("[ '#' fragment ]").get("fragment").value();
}

std::string	URI::get_merged_path_string(const ViewData &cview) const {
	std::string	path = get_path().to_string();
	if (path.size() > 0) {
		if (path.back() == '/') {
			if (cview[0] == '/') {
				path += ViewData(cview).move_pointer().to_string();
			} else {
				path += cview.to_string();
			}
		} else {
			if (cview[0] == '/') {
				path += cview.to_string();
			} else {
				path += "/" + cview.to_string();
			}
		}
	}
	return path;
}

std::string	URI::remove_dot_segments_from_path(const ViewData &cview) {
	ViewData				view(cview);
	std::vector<ViewData>	stack;
	std::ostringstream		text;
	size_t					index;
	bool					last_slash = false;

	if (view[0] == '/') {
		text << '/';
	}
	while (view.size() > 0) {
		if (view[0] == '/') {
			view.move_pointer();
			if (view.size() == 0) {
				last_slash = true;
			}
		} else if (view.partial_equals("../") || (view.partial_equals("..") && view.size() == 2)) {
			if (stack.size() > 0) {
				stack.pop_back();
			}
			view.move_pointer(2);
		} else if (view.partial_equals("./") || (view.partial_equals(".") && view.size() == 1)) {
			view.move_pointer(1);
		} else {
			int		size = view.count_chars_until('/');
			stack.push_back(ViewData(view, size < 0 ? view.size() : size));
			view.move_pointer(stack.back().size());
		}
	}
	index = 0;
	while (index < stack.size()) {
		text << stack[index];
		index += 1;
		if (index < stack.size() || last_slash) {
			text << '/';
		}
	}
	return text.str();
}
