/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHeaderSection.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:14:16 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/12 13:50:49 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestHeaderSection.hpp"

/* copied from https://en.wikipedia.org/wiki/List_of_HTTP_header_fields#Request_fields */
const char	*RequestHeaderSection::m_list_of_accepted_field_names[64] = {
	"A-IM", "Accept", "Accept-Charset", "Accept-Datetime", "Accept-Encoding",
	"Accept-Language", "Access-Control-Request-Method", "Access-Control-Request-Headers",
	"Authorization", "Cache-Control", "Connection", "Content-Encoding", "Content-Length",
	"Content-MD5", "Content-Type", "Cookie", "Date", "Expect", "Forwarded", "From",
	"Host", "HTTP2-Settings", "If-Match", "If-Modified-Since", "If-None-Match", "If-Range",
	"If-Unmodified-Since", "Max-Forwards", "Origin", "Pragma", "Proxy-Authorization",
	"Range", "Referer", "TE", "Trailer", "Transfer-Encoding", "User-Agent", "Upgrade",
	"Via", "Warning",
};

/*

	"Accept-Charset",
	"Accept-Language",
	"Authorization", "Content-Length",
	"Content-Type", "Date", 
	"Host", "Referer", "Transfer-Encoding", "User-Agent"

*/

HeaderSection::ValidationResult	RequestHeaderSection::child_validate() const {
	HeaderSection::ValidationResult	result;

	for (size_t i = 0; i < m_headers.size(); i += 1) {
		if (!is_header_valid(m_headers[i])) {
			result.status_code = StatusCode::BadRequest;
			result.description = "Forbidden Header Field (" + m_headers[i]->get_field_name() + ")";
		}
	}
	return (result);
}

bool		RequestHeaderSection::is_header_valid(Header *header) const {
	bool	found = false;

	for (size_t i = 0; m_list_of_accepted_field_names[i]; i += 1) {
		if (ViewData(header->get_field_name()).partial_caseins_equals(m_list_of_accepted_field_names[i])) {
			found = true;
			break ;
		}
	}
	return (found);
}

std::string	RequestHeaderSection::start_line_to_string() const {
	std::string		result;

	if (m_method != Method::Invalid) {
		result += m_method.to_string();
		result += " " + m_request_target + " HTTP/1.1\r\n";
	}
	return (result);
}

bool			RequestHeaderSection::parse_start_line(const ViewData &start_line) {
	ViewData	view(start_line);
	bool		result = false;
	BNF::ViewTree	tree = g_bnf.make_tree("request-line", view);
	if (!tree.empty() && view.size() == 0) {
		m_method = Method::Invalid;
		for (size_t method_index = 0; method_index < Method::Invalid; method_index += 1) {
			Method	method = Method::from_int(method_index);
			if (tree.begin().get("method").value().exact_equals(method.to_string())) {
				m_method = method;
			}
		}
		m_request_target = tree.begin().get("request-target").value().to_string();
		result = true;
	}
	return (result);
}

const Method	&RequestHeaderSection::get_method() const {
	return m_method;
}

const std::string	&RequestHeaderSection::get_request_target() const {
	return m_request_target;
}

void				RequestHeaderSection::clear() {
	m_method = Method();
	m_request_target.clear();
	HeaderSection::clear();
}
