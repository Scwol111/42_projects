/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 20:23:09 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/09 14:45:52 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"
#include <sstream>

bool				Header::parse_header_field(const ViewData &header_field) {
	bool			result = false;
	ViewData		view(header_field);
	BNF::ViewTree	tree = g_bnf.make_tree("header-field", view);

	if (!tree.empty()) {
		if (tree.begin().get("field-name").value().exact_caseins_equals(ViewData(m_field_name))) {
			m_status_code = StatusCode::OK;
			parse_field_value(tree.begin().get("field-value").value());
			result = (m_status_code == StatusCode::OK);
		}
	}
	return result;
}

std::string		Header::construct_header_field() const {
	std::ostringstream	text;

	text << m_field_name << ": " << construct_field_value();
	return text.str();
}


