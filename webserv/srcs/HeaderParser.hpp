/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeaderParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:33:42 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/15 12:32:37 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_CREATOR_HPP
#define HEADER_CREATOR_HPP

#include <cstddef>
#include <vector>
#include "Headers/Header.hpp"



/* Purpose of this class is to construct valid Header from header_field that */
/* defined in RFC7230 Section-3.2. */

/* include your implementation's header file here */
#include "Headers/Allow.hpp"
#include "Headers/Host.hpp"
#include "Headers/AcceptCharset.hpp"
#include "Headers/AcceptLanguage.hpp"
#include "Headers/ContentLanguage.hpp"
#include "Headers/Authorization.hpp"
#include "Headers/WWWAuthenticate.hpp"
#include "Headers/ContentLength.hpp"
#include "Headers/ContentType.hpp"
#include "Headers/ContentLocation.hpp"
#include "Headers/IfModifiedSince.hpp"
#include "Headers/LastModified.hpp"
#include "Headers/TransferEncoding.hpp"
#include "Headers/ServerHeader.hpp"
#include "Headers/ContentType.hpp"
#include "Headers/LocationHeader.hpp"
#include "Headers/Expect.hpp"
#include "Headers/RetryAfter.hpp"
#include "Headers/UserAgent.hpp"
#include "Headers/ContentLocation.hpp"
#include "Headers/Referer.hpp"

class HeaderParser {

	struct ImplementationList {
		std::vector<Header *>	headers;

		ImplementationList() {
			/* add new instance of your Header implementation here */
			/* headers.push_back(new MyHeaderImplementation()); */
			headers.push_back(new Host(""));
			headers.push_back(new UserAgent());
			headers.push_back(new RetryAfter());
			headers.push_back(new Referer());
			headers.push_back(new Allow(""));
			headers.push_back(new AcceptCharset(""));
			headers.push_back(new AcceptLanguage(""));
			headers.push_back(new ContentLocation(""));
			headers.push_back(new ContentLanguage(""));
			headers.push_back(new Authorization(""));
			headers.push_back(new WWWAuthenticate(""));
			headers.push_back(new ContentLength(0));
			headers.push_back(new ContentType(""));
			headers.push_back(new IfModifiedSince(""));
			headers.push_back(new LastModified());
			headers.push_back(new TransferEncoding(""));
			headers.push_back(new ServerHeader());
			headers.push_back(new ContentType(""));
			headers.push_back(new LocationHeader(""));
			headers.push_back(new Expect());
		}
		~ImplementationList() {
			for (size_t i = 0; i < headers.size(); i += 1) {
				delete headers[i];
			}
		}
	};

	/* This static field holds all implementations of Headers. */
	/* If you has created a new implementation you should add new instance of */
	/* your implementation to this list in HeaderParser.cpp file */
	static ImplementationList	implementation_list;

	HeaderParser(const HeaderParser &);
	HeaderParser	&operator=(const HeaderParser &);
public:
	HeaderParser() {}
	~HeaderParser() {}

	/* This method clones Header instance from implementation_list in which the field_name is same as in the header_field */
	/* The header_field defined in RFC7230 Section-3.2 */
	/* If the approriate implementation does not found NULL is returned. */
	/* If the header_field is syntactically incorrect (field_value does not in count) NULL is returned */
	/* You should check Header::get_status_code() to be StatusCode::OK that means success of parsing of field_value */
	Header		*construct_header_from_header_field(const ViewData &header_field) const;

};

#endif /* HEADER_CREATOR_HPP */
