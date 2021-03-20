/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:56:27 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/16 11:32:04 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>
#include <istream>
#include "../StatusCode.hpp"
#include "../BNF.hpp"

/* 
	RFC7230 has a generic algorithm to determine field_name and field_value.
	However, format of field_value is specific to each header. This class
	implements generic parsing algorithm while child of this class implements specific
	algorithm for field_value part.
*/

class Header {
private:
	/* parsed field name in pair "field_name: field_value" defined in RFC7230 Section 3.2 */
	std::string		m_field_name;

	Header();
public:
	Header(const std::string &field_name): m_field_name(field_name) {}
	Header(const Header &header): m_field_name(header.m_field_name), m_status_code(header.m_status_code) {}
	Header	&operator=(const Header &header) {
		m_field_name = header.m_field_name;
		m_status_code = header.m_status_code;
		return *this;
	}
	virtual ~Header() {}

	/* Generic parsing algorithm. After successful parsing it calls parse_field_value() automatically and returns true. */
	/* If fails status_code will be set to StatusCode::BadRequest and returns false. */
	/* You should check get_status_code() to be StatusCode::OK that means success of parsing of field_value part. */
	bool				parse_header_field(const ViewData &header_field);

	/* field_value contains sequence of characters specified in RFC7230 Section-3.2. */
	/* Should return true in case of success, and false on failure. */
	/* On call moment status code value is StatusCode::OK. If failure occured */
	/* this function must set status_code to appropriate StatusCode:: value */
	virtual void		parse_field_value(const ViewData &field_value) = 0;

	const StatusCode	&get_status_code() const {
		return m_status_code;
	}
	const std::string	&get_field_name() const {
		return m_field_name;
	}

	/* Returns sequence of characters that satisfying to header_field requirements. */
	/* If Header in the invalid state it returns empty string. */
	std::string			construct_header_field() const;

	virtual Header		*clone() const = 0;



	/* Returns sequence of characters that satisfying to field_value requirements. */
	/* Header will be in a valid state on the call moment. */
	virtual std::string		construct_field_value() const = 0;

protected:
	/* after generic algorithm status_code can be either StatusCode::BadRequest or StatusCode::OK */
	/* childs of this class can set status_code to some other status code defined in StatusCode::* */
	/* if header was parsed successfully status code must be StatusCode::OK */
	StatusCode		m_status_code;


};

#endif /* HEADER_HPP */
