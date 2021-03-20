/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerInfo.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:52:43 by tclaudin          #+#    #+#             */
/*   Updated: 2021/03/14 19:45:53 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERINFO_HPP
#define SERVERINFO_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>

#include "Location.hpp"
#include "Path.hpp"

#ifndef NPOS
# define NPOS std::string::npos
#endif

class ServerInfo
{
private:
	enum Tokens
	{
		LISTEN, SERVER_NAME, CLIENT_MAX_BODY_SIZE, ROOT, INDEX, AUTOINDEX, 
		ERROR_PAGE, LOCATION, CGI_PASS, CGI_PARAM , INTERNAL, RETURN, AUTH_BASIC,
		AUTH_BASIC_USER_FILE, ALLOW_METHODS, DENY_METHODS,
		CGI_ALLOW_METHODS, CGI_DENY_METHODS, DEFAULT_METHOD_BODY,
		TIMEOUT, UNKNOWN,
	};

	std::vector<std::string>	_names;
	std::string					_host;
	std::vector<Location>		_lock;
	Location 					_standart;
	int							_port;

	int		parse(std::string const &);
	void	remakeString(std::string &);
	int		findCGI(std::string &);
	
	std::map<std::string, std::string> *_mime_types;
	void setupTypes();

	ServerInfo();
public:
	ServerInfo(const std::vector<std::string> &);
	ServerInfo(const ServerInfo &);
	ServerInfo &operator= (const ServerInfo &);
	~ServerInfo();
	void				Validator();
	const std::string 	&getServerName(size_t index = 0) const;
	size_t				getServerNamesCount() const;
	const std::string	&getHost() const;
	int					getPort() const;
	const std::string 	&getErrorPage(int);
	const Location		*findLocation(Path const &request_path, Path &location_path) const;
	std::string 		getMimeTypes(std::string const &) const;
	const Location		*getRootLocation() const;

	class UnknownParamException: public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Error: unknown parameter";
			}
	};
	class BadParamException: public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Configuration error: Bad parameter";
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
		public:
			virtual const char* what() const throw()
			{
				return "Unknown feature in configuratuon file";
			}
	};
	class DoubleListenException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Webserv: Exception: Configuration file have double listen command";
			}
	};
};

#endif
