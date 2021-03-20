/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseHeaderSection.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:27:14 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/14 16:09:55 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HEADER_SECTION_HPP
#define RESPONSE_HEADER_SECTION_HPP

#include "HeaderSection.hpp"
#include "../StatusCode.hpp"

class ResponseHeaderSection : public HeaderSection {
private:

	StatusCode	m_status_code;

	ResponseHeaderSection(const ResponseHeaderSection &);
	ResponseHeaderSection	&operator=(const ResponseHeaderSection &);
public:
	ResponseHeaderSection() : HeaderSection() {}
	~ResponseHeaderSection();

	void		set_status_code(StatusCode);
	StatusCode	get_status_code() const;

	HeaderSection::ValidationResult	child_validate() const; /* todo: implement */
	bool					is_header_valid(Header *) const;
	std::string				start_line_to_string() const;

	void					clear();
};




#endif /* RESPONSE_HEADER_SECTION_HPP */
