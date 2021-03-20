/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeaderSection.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:30:54 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/14 16:08:46 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_SECTION
#define HEADER_SECTION

#include <cstddef>
#include <string>
#include <vector>
#include "../StatusCode.hpp"
#include "../Headers/Header.hpp"
#include "../ViewData.hpp"

/* This class is a representation of header section. */
/* The representation is defined in RFC7230 Section-3 (without MessageBody) */

class HeaderSection {
public:
	struct ValidationResult {
		StatusCode	status_code;
		std::string	description;
	};

protected:
	std::vector<Header *>		m_headers;
	std::vector<std::string>	m_unrecognized_header_fields;
	bool						m_disabled;

private:

	HeaderSection(const HeaderSection &);
	HeaderSection	&operator=(const HeaderSection &);
public:
	HeaderSection(): m_disabled(false) {}
	virtual ~HeaderSection(); /* todo: do not forget to implement! */

	bool	add_header(Header *);
	bool	add_header(const ViewData &header_field);
	void	remove_header(const ViewData &field_name);
	bool	transfer_headers_from(HeaderSection &);

	/* There is can be more then one header with same field_name. */
	/* Its allowed only for certain headers. */
	/* Second parameter is for indexing headers with the same field_name */
	Header	*find_header(const ViewData &field_name, size_t appearance = 0) const;

	/* Check if all headers and start_line in a valid state */
	/* On success ValidationResult::status_code will be StatusCode::OK */
	/* On failure ValidationResult::status_code will be with appropriate StatusCode:: value */
	/* and ValidationResult::description may contain text description of failure. */
	ValidationResult	validate() const;

	/* Translate internal structure to string */
	std::string		to_string() const;

	void		clear();

	size_t		headers_count() const {
		return m_headers.size();
	}
	Header		*get_header(size_t index) const {
		return m_headers[index];
	}
	void		disable() {
		m_disabled = true;
	}
	void		enable() {
		m_disabled = false;
	}
	bool		is_enabled() {
		return !m_disabled;
	}

	size_t	unrecognized_headers_count() const {
		return m_unrecognized_header_fields.size();
	}
	const std::string	&get_unrecognized_header(size_t index) const {
		return m_unrecognized_header_fields[index];
	}
	ViewData	get_unrecognized_header_field_name(size_t index) const;
	ViewData	get_unrecognized_header_field_value(size_t index) const;

	int			find_unrecognized_header(const ViewData &field_name) const;

protected:

	/* Child method for validation of headers. */
	/* On success ValidationResult::status_code must be StatusCode::OK */
	/* On failure ValidationResult::status_code must be with appropriate StatusCode:: value */
	/* and ValidationResult::description should contain text description of failure. */
	virtual ValidationResult	child_validate() const = 0;

	virtual bool			is_header_valid(Header *) const = 0;

	virtual std::string		start_line_to_string() const = 0;

};


#endif /* HEADER_SECTION */
