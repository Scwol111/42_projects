/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:41:23 by tclaudin          #+#    #+#             */
/*   Updated: 2021/03/15 14:17:24 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <fstream>

#include "ErrorInfo.hpp"
#include "StatusCode.hpp"
#include "Path.hpp"
#include "Method.hpp"

#ifndef NPOS
# define NPOS std::string::npos
#endif //NPOS

class Location
{
public:
	struct MethodBody {
		bool		ok;
		std::string	body;

		MethodBody(): ok(false) {}
	};

private:
	enum Tokens
	{
		CLIENT_MAX_BODY_SIZE, ROOT, INDEX, AUTOINDEX, ERROR_PAGE, 
		LOCATION, CGI_PASS, CGI_PARAM , INTERNAL, RETURN, AUTH_BASIC,
		AUTH_BASIC_USER_FILE, ALLOW_METHODS, DENY_METHODS,
		CGI_ALLOW_METHODS, CGI_DENY_METHODS, DEFAULT_METHOD_BODY,
		TIMEOUT, UNKNOWN,
	};
	std::vector<std::string>	_index;
	std::string 				_name;
	std::string					_root;
	std::vector<std::string>	_cgi_info;
	std::vector<Location> 		_lock;
	bool						_iternal;
	bool						_autoindex;
	size_t						_max_body_size;
	std::vector<ErrorInfo> 		_errors;
	std::string					_cgi_serv;
	std::string					_cgi_ext;
	bool						_cgi;
	std::string					_return_uri;
	int							_return_code;
	std::string					_realm;
	std::string					_user_pass_file;
	Method::Set					_allow_methods;
	Method::Set					_cgi_allow_methods;
	MethodBody					_default_method_body[Method::Count];
	time_t						_timeout;

	int			parse(std::string const &);
	int			findCGI(std::string &);
	std::string	remakeString(std::string &) const;

public:

	enum cgi_params
	{
		AUTH_TYPE, CONTENT_LENGTH, CONTENT_TYPE, GATEWAY_INTERFACE, PATH_INFO,
		PATH_TRANSLATED, QUERY_STRING, REMOTE_ADDR,	REMOTE_IDENT, REMOTE_USER,
		REQUEST_METHOD, REQUEST_URI, SCRIPT_NAME, SERVER_NAME, SERVER_PORT,	SERVER_PROTOCOL,
		SERVER_SOFTWARE, MAXIMALS
	};
	Location();
	Location(std::string &);
	Location(const Location &);
	~Location();
	Location &operator=(const Location &);
	void	construct(std::vector<std::string> &, std::string const &/*, const Location &*/);
	void	Validator();
	void	setAutoindex(bool);
	void	setIternal(bool);
	void	setRoot(const std::string &);
	void	setName(const std::string &);
	void	setMaxBodySize(const long);
	void	addIndex(const std::string &);
	void	changeCGIparam(const int, const std::string &);
	void	addErrors(std::string const &);
	void	setCGIserver(std::string const &path, std::string const &ext);
	void	setReturnCode(int);
	void	setReturnUri(std::string const &);
	void	setRealm(std::string const &);
	void	setUserPassFile(std::string const &);
	void	setDefaultMethodBody(Method, MethodBody const &);
	void	clearMethods();
	void	setMethod(Method const &);
	void	unsetMethod(Method const &);
	void	clearCGIMethods();
	void	setCGIMethod(Method const &);
	void	unsetCGIMethod(Method const &);
	void	setTimeout(time_t);
	void	clearIndex();

	size_t				getMaxBodySize() const;
	const std::string	&getRoot() const;
	const std::string	&getCGIparam(cgi_params) const;
	const std::string	&getCGIserver() const;
	const std::string	&getCGIextension() const;
	const std::string	&getName() const;
	const std::string	&getReturnUri() const;
	int					getReturnCode() const;
	const Location 		*findLocation(Path const &request_path, Path &location_path) const;
	std::string 		getErrorPage(StatusCode, const std::string &) const;
	bool				getInternal() const;
	bool				getAutoindex() const;
	const std::string	&getRealm() const;
	const std::string	&getUserPassFile() const;
	const Method::Set	&getMethodSet() const;
	const Method::Set	&getCGIMethodSet() const;
	const MethodBody	&getDefaultMethodBody(Method) const;
	time_t				getTimeout() const;

	bool				isAuthNeeded() const;

	static std::string createErrorHTML(StatusCode, const std::string &message);

	bool		hasCGIServ() const;

	size_t				getIndexFilesCount() const;
	const std::string	&getIndexFileName(size_t index) const;
	
	class OutOfRangeException: public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Error: Index out of range";
			}
	};
	class NeedOpenParthenesException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Configuration file have closed parthenes, but don't have opened parthenes";
			}
	};
	class NotEnoughParthenes: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Need parentheses";
			}
	};
	class UnknownFeature: public std::exception
	{
		std::string	reason;

		public:
			UnknownFeature(const std::string &res) {
				reason = "Unknown feature in configuratuon file: " + res;
			}
			~UnknownFeature() throw() {}

			virtual const char* what() const throw()
			{
				return reason.c_str();
			}
	};
	class UnknownCGIParamException: public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Error: unknown CGI parameter";
			}
	};
	class LocationNotFounded: public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Error: Location not founded";
			}
	};
	class UnknownParamException: public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Error: unknown parameter";
			}
	};
};

#endif /* LOCATION_HPP */
