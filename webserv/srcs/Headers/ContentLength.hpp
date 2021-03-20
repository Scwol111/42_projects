/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContentLength.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:32:51 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/16 11:27:03 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTENT_LENGTH_HPP
#define CONTENT_LENGTH_HPP

#include "Header.hpp"
#include <sstream>

class ContentLength : public Header {
private:
	int		length;

public:
	ContentLength(): Header("Content-Length"), length(0) {}
	ContentLength(int length): Header("Content-Length"), length(length) {}
	~ContentLength() {};

	void		parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Content-Length", view) && view.size() == 0) {
			length = field_value.to_long();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Content-Length field_value" << std::endl;
		}
	}
	std::string		construct_field_value() const {
		std::ostringstream	text;
		text << length;
		return text.str();
	}

	size_t		getLength() {
		return length;
	}

	Header			*clone() const {
		return new ContentLength(*this);
	}
};


#endif /* CONTENT_LENGTH_HPP */
