/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DummyHeader.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:10:22 by jsandsla          #+#    #+#             */
/*   Updated: 2021/02/16 14:21:13 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HEADER_HPP
#define DUMMY_HEADER_HPP

#include <string>
#include "Header.hpp"

class DummyHeader : public Header {
private:

	DummyHeader();
public:
	DummyHeader(const std::string &field_name): Header(field_name) {}
	DummyHeader(const DummyHeader &dummy): Header(dummy) {}
	~DummyHeader() {}
	DummyHeader	&operator=(const DummyHeader &dummy) {
		Header::operator=(dummy);
		return *this;
	}

	Header		*clone() const {
		return new DummyHeader(*this);
	}

	void		parse_field_value(const ViewData &field_value) {
		(void)field_value;
	}

private:
	std::string		construct_field_value() const {
		return "";
	}
};

#endif /* DUMMY_HEADER_HPP */
