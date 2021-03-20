/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeaderSection.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:12:27 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/16 11:35:13 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HeaderSection.hpp"
#include "../HeaderParser.hpp"

HeaderSection::~HeaderSection() {
	for (size_t i = 0; i < m_headers.size(); i += 1) {
		delete m_headers[i];
	}
}

bool	HeaderSection::add_header(Header *header) {
	bool	result = false;

	if (header) {
		m_headers.push_back(header);
		result = true;
	}
	return (result);
}

bool	HeaderSection::add_header(const ViewData &header_field) {
	HeaderParser	parser;
	Header			*header;
	bool			result = false;
	ViewData		view(header_field);

	header = parser.construct_header_from_header_field(header_field);
	if (header) {
		result = add_header(header);
	} else {
		bool	match = g_bnf.match("header-field", view);
		bool	zero = view.size() == 0;
		if (match && zero) {
			m_unrecognized_header_fields.push_back(header_field.to_string());
			result = true;
		}
	}
	return (result);
}

void	HeaderSection::remove_header(const ViewData &field_name) {
	std::vector<Header *>::iterator	it = m_headers.begin();

	for (; it != m_headers.end();) {
		if (field_name.exact_caseins_equals((*it)->get_field_name())) {
			delete *it;
			it = m_headers.erase(it);
		} else {
			++it;
		}
	}
}

bool	HeaderSection::transfer_headers_from(HeaderSection &section) {
	for (size_t i = 0; i < section.m_headers.size(); i += 1) {
		m_headers.push_back(section.m_headers[i]);
	}
	section.m_headers.clear();
	for (size_t i = 0; i < section.m_unrecognized_header_fields.size(); i += 1) {
		m_unrecognized_header_fields.push_back(section.m_unrecognized_header_fields[i]);
	}
	section.m_unrecognized_header_fields.clear();
	return (true);
}

Header	*HeaderSection::find_header(const ViewData &field_name, size_t appearance) const {
	Header	*result = 0;

	for (size_t i = 0; i < m_headers.size(); i += 1) {
		if (ViewData(m_headers[i]->get_field_name()).exact_caseins_equals(field_name)) {
			if (appearance == 0) {
				result = m_headers[i];
			} else {
				appearance -= 1;
			}
		}
	}
	return (result);
}

HeaderSection::ValidationResult	HeaderSection::validate() const {
	ValidationResult	result;

	result.status_code = StatusCode::OK;
	for (size_t i = 0; i < m_headers.size(); i += 1) {
		result.status_code = m_headers[i]->get_status_code();
		if (result.status_code != StatusCode::OK) {
			break ;
		}
	}
	if (result.status_code == StatusCode::OK) {
		result = child_validate();
	}
	return (result);
}

std::string		HeaderSection::to_string() const {
	std::ostringstream	text;

	if (!m_disabled) {
		text << start_line_to_string();
		for (size_t i = 0; i < m_headers.size(); i += 1) {
			text << m_headers[i]->construct_header_field() << "\r\n";
		}
		for (size_t i = 0; i < m_unrecognized_header_fields.size(); i += 1) {
			text << m_unrecognized_header_fields[i] << "\r\n";
		}
		text << "\r\n";
	}
	return (text.str());
}

void			HeaderSection::clear() {
	for (size_t index = 0; index < m_headers.size(); index += 1) {
		delete m_headers[index];
	}
	m_headers.clear();
	m_unrecognized_header_fields.clear();
}

ViewData	HeaderSection::get_unrecognized_header_field_name(size_t index) const {
	ViewData	view(get_unrecognized_header(index));
	BNF::ViewTree	tree = g_bnf.make_tree("header-field", view);
	return tree.begin().get("field-name").value();
}

ViewData	HeaderSection::get_unrecognized_header_field_value(size_t index) const {
	ViewData	view(get_unrecognized_header(index));
	BNF::ViewTree	tree = g_bnf.make_tree("header-field", view);
	return tree.begin().get("field-value").value();
}

int			HeaderSection::find_unrecognized_header(const ViewData &field_name) const {
	size_t index = 0;

	for (index = 0; index < m_unrecognized_header_fields.size(); index += 1) {
		ViewData		view(m_unrecognized_header_fields[index]);
		BNF::ViewTree	tree = g_bnf.make_tree("header-field", view);

		if (tree.begin().get("field-name").value().exact_caseins_equals(field_name)) {
			break ;
		}
	}
	return (index < m_unrecognized_header_fields.size() ? index : -1);
}
