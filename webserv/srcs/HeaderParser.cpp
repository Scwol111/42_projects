/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeaderParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:54:56 by jsandsla          #+#    #+#             */
/*   Updated: 2021/02/19 22:42:50 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HeaderParser.hpp"

#include "Headers/DummyHeader.hpp"

HeaderParser::ImplementationList	HeaderParser::implementation_list;


Header	*HeaderParser::construct_header_from_header_field(const ViewData &header_field) const {
	Header	*result = NULL;

	for (size_t i = 0; i < HeaderParser::implementation_list.headers.size(); i += 1) {
		DummyHeader		dummy(HeaderParser::implementation_list.headers[i]->get_field_name());

		if (dummy.parse_header_field(header_field) && dummy.get_status_code() == StatusCode::OK) {
			result = HeaderParser::implementation_list.headers[i]->clone();
			if (!result->parse_header_field(header_field)) {
				delete result;
				result = NULL;
			}
			break ;
		}
	}
	return result;
}
