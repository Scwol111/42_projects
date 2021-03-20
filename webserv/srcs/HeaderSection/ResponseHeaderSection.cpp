/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseHeaderSection.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:30:34 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/12 13:52:02 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResponseHeaderSection.hpp"
#include <sstream>

/*

Allow
Content-Language
Content-Length
Content-Location
Content-Type
Date
Last-Modified
Location
Retry-After
Transfer-Encoding
WWW-Authenticate


Content-Language
Content-Length
Content-Location
Content-Type
Date
Last-Modified

*/

ResponseHeaderSection::~ResponseHeaderSection() {
}

void			ResponseHeaderSection::set_status_code(StatusCode code) {
	m_status_code = code;
}

StatusCode		ResponseHeaderSection::get_status_code() const {
	return (m_status_code);
}

HeaderSection::ValidationResult	ResponseHeaderSection::child_validate() const {
	HeaderSection::ValidationResult	result;

	result.status_code = StatusCode::OK;
	return (result);
}

bool					ResponseHeaderSection::is_header_valid(Header *header) const {
	(void)header;
	return (true);
}

std::string				ResponseHeaderSection::start_line_to_string() const {
	std::ostringstream	text;

	text << "HTTP/1.1 ";
	text << m_status_code.to_int();
	text << ' ';
	text << m_status_code.to_string();
	text << "\r\n";
	return text.str();
}

void					ResponseHeaderSection::clear() {
	m_status_code = StatusCode::Invalid;
	HeaderSection::clear();
}
