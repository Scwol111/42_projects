/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusCode.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 20:03:53 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/07 18:03:13 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StatusCode.hpp"

std::string		StatusCode::code_names[StatusCode::Invalid + 1] = {
	"Continue", "Switching Protocols", "OK", "Created", "Accepted",
	"Non-Authoritative Information", "No Content", "Reset Content",
	"Partial Content", "Multiple Choices", "Moved Permanently", "Found",
	"See Other", "Not Modified", "Use Proxy", "Temporary Redirect",
	"Bad Request", "Unauthorized", "Payment Required", "Forbidden",
	"Not Found", "Method Not Allowed", "Not Acceptable",
	"Proxy Authentication Required", "Request Timeout", "Conflict",
	"Gone", "Length Required", "Precondition Failed", "Payload Too Large",
	"URI Too Long", "Unsupported Media Type", "Range Not Satisfiable",
	"Expectation Failed", "Upgrade Required", "Internal Server Error",
	"Not Implemented", "Bad Gateway", "Service Unavailable",
	"Gateway Timeout", "HTTP Version Not Supported", "Invalid"
};

int				StatusCode::code_ints[StatusCode::Invalid + 1] = {
	100, 101, 200, 201, 202, 203, 204, 205, 206, 300, 301, 302, 303, 304,
	305, 307, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411,
	412, 413, 414, 415, 416, 417, 426, 500, 501, 502, 503, 504, 505, 0,
};

StatusCode		StatusCode::from_int(int code) {
	StatusCode	status_code = StatusCode::Invalid;

	for (size_t	index = 0; index < Invalid; index += 1) {
		if (code_ints[index] == code) {
			status_code = static_cast<StatusCode::EnumType>(index);
			break ;
		}
	}
	return (status_code);
}

std::ostream	&operator<<(std::ostream &output, const StatusCode &status) {
	output << status.to_string();
	return output;
}
