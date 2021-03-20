/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusCode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:03:02 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/11 19:17:30 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_CODE_HPP
#define STATUS_CODE_HPP

#include <string>
#include <ostream>
#include "ViewData.hpp"

/* This class is the representation of the status codes defined in RFC7231 Section-6 */

class StatusCode {
public:

	enum EnumType {
		/* 100 */ Continue,
		/* 101 */ SwitchingProtocols,
		/* 200 */ OK,
		/* 201 */ Created,
		/* 202 */ Accepted,
		/* 203 */ NonAuthoritativeInformation,
		/* 204 */ NoContent,
		/* 205 */ ResetContent,
		/* 206 */ PartialContent,
		/* 300 */ MultipleChoices,
		/* 301 */ MovedPermanently,
		/* 302 */ Found,
		/* 303 */ SeeOther,
		/* 304 */ NotModified,
		/* 305 */ UseProxy,
		/* 307 */ TemporaryRedirect,
		/* 400 */ BadRequest,
		/* 401 */ Unauthorized,
		/* 402 */ PaymentRequired,
		/* 403 */ Forbidden,
		/* 404 */ NotFound,
		/* 405 */ MethodNotAllowed,
		/* 406 */ NotAcceptable,
		/* 407 */ ProxyAuthenticationRequired,
		/* 408 */ RequestTimeout,
		/* 409 */ Conflict,
		/* 410 */ Gone,
		/* 411 */ LengthRequired,
		/* 412 */ PreconditionFailed,
		/* 413 */ PayloadTooLarge,
		/* 414 */ URITooLong,
		/* 415 */ UnsupportedMediaType,
		/* 416 */ RangeNotSatisfiable,
		/* 417 */ ExpectationFailed,
		/* 426 */ UpgradeRequired,
		/* 500 */ InternalServerError,
		/* 501 */ NotImplemented,
		/* 502 */ BadGateway,
		/* 503 */ ServiceUnavailable,
		/* 504 */ GatewayTimeout,
		/* 505 */ HTTPVersionNotSupported,
		/* ??? */ Invalid,
	};

private:
	EnumType	value;

	static std::string		code_names[Invalid + 1 /* amount of codes + Invalid one */];
	static int				code_ints[Invalid + 1];

public:
	StatusCode(): value(Invalid) {}
	StatusCode(EnumType value): value(value) {}
	StatusCode(const StatusCode &status): value(status.value) {}
	~StatusCode() {}
	StatusCode	&operator=(const StatusCode &status) {
		value = status.value;
		return *this;
	}
	StatusCode	&operator=(const EnumType &status) {
		value = status;
		return *this;
	}

	bool operator==(const StatusCode &b) const {
		return value == b.value;
	}
	bool operator!=(const StatusCode &b) const {
		return !(*this == b);
	}
	bool operator==(const EnumType &b) const {
		return value == b;
	}
	bool operator!=(const EnumType &b) const {
		return !(*this == b);
	}

	const std::string	&to_string() const {
		return code_names[value];
	}
	int	to_int() const {
		return code_ints[value];
	}

	static StatusCode	from_int(int code);

};

std::ostream	&operator<<(std::ostream &output, const StatusCode &status);

#endif /* STATUS_CODE_HPP */
