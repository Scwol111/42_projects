/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHeaderSection.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:12:51 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/14 16:09:37 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HEADER_SECTION_HPP
#define REQUEST_HEADER_SECTION_HPP

#include "HeaderSection.hpp"
#include "../URI.hpp"
#include "../ViewData.hpp"
#include "../Method.hpp"

class RequestHeaderSection : public HeaderSection {
private:
	Method		m_method;
	std::string	m_request_target;

	static const char	*m_list_of_accepted_field_names[64];

	RequestHeaderSection(const RequestHeaderSection &);
	RequestHeaderSection	&operator=(const RequestHeaderSection &);
public:
	RequestHeaderSection() {};
	~RequestHeaderSection() {};

	HeaderSection::ValidationResult	child_validate() const;
	bool			is_header_valid(Header *) const;
	std::string		start_line_to_string() const;

	bool			parse_start_line(const ViewData &start_line);

	const Method		&get_method() const;
	const std::string	&get_request_target() const;

	void				clear();

};

#endif /* REQUEST_HEADER_SECTION_HPP */
