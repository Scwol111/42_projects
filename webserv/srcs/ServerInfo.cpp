/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerInfo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:52:41 by tclaudin          #+#    #+#             */
/*   Updated: 2021/03/14 19:47:50 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerInfo.hpp"

ServerInfo::ServerInfo()
{
	_mime_types = NULL;
}

ServerInfo::ServerInfo(const ServerInfo &copy)
	: _names(copy._names)
	, _host(copy._host)
	, _lock(copy._lock)
	, _standart(copy._standart)
	, _port(copy._port)
{
	_mime_types = new std::map<std::string, std::string>(copy._mime_types->begin(), copy._mime_types->end());
}

ServerInfo::~ServerInfo()
{
	if (_mime_types != NULL)
		delete _mime_types;
}

ServerInfo::ServerInfo(const std::vector<std::string> &str): _host("127.0.0.1"), _port(8080)
{
	bool						location_finded = false;
	std::stack<char>			st;
	std::vector<std::string>	location_name;
	std::vector<std::vector<std::string> > locations;
	bool						add = false;
	bool						listen = false;

	_mime_types = NULL;
	_mime_types = new std::map<std::string, std::string>();
	setupTypes();

	for (size_t i = 0; i < str.size(); i++)
	{
		std::vector<std::string>	&vec = locations.back();
		std::string					res = " " + str[i];
		std::string 				idx;
		int							p;
		size_t 						r;
		char						*k;
	
		remakeString(res);
		if (!location_finded && res.size() != 0)
			switch (parse(res))
			{
			case LISTEN:
				if (listen)
					throw DoubleListenException();
				listen = true;
				res = std::string(res, 8, res.size() - 9);
				if ((r = res.find(":")) != NPOS)
				{
					if (res.find(":", r + 1) != NPOS)
						throw BadParamException();
					_port = static_cast<int>(std::strtol(res.c_str() + r + 1, &k, 10));
					_host = std::string(res, 0, r);
				}
				else
					_port = static_cast<int>(std::strtol(res.c_str(), &k, 10));			
				break;
			case SERVER_NAME: {
				ViewData	view(res);
				
				_standart.clearIndex();
				view.move_pointer(13);
				while (view.skip_ws()) {
					int until_ws = view.count_chars_until_ws();
					std::string	name = ViewData(view, until_ws < 0 ? view.size() : until_ws).to_string();
					_names.push_back(name);
					view.move_pointer(until_ws < 0 ? view.size() : until_ws);
				}
			} break ;
			case CLIENT_MAX_BODY_SIZE:
				_standart.setMaxBodySize(std::stol(std::string(res, 22, res.size() - 23)));
				break;
			case ROOT:
				_standart.setRoot(std::string(res, 6, res.size() - 7) + "/");
				break;
			case INDEX: {
				ViewData	view(res);

				view.move_pointer(7);
				_standart.clearIndex();
				while (view.skip_ws()) {
					ViewData	indexfile(view.subview_trunc(view.count_chars_until_ws()));
					_standart.addIndex(indexfile.to_string());
					view.move_pointer(indexfile.size());
				}
			} break ;
			case AUTOINDEX:
				idx = std::string(res, 11, res.size() - 12);
				if (idx == "off")
					_standart.setAutoindex(false);
				else if (idx == "on")
						_standart.setAutoindex(true);
					else
						throw UnknownParamException();
				break;
			case ERROR_PAGE:
				_standart.addErrors(std::string(res, 11, res.size() - 12));
				break;
			case LOCATION: {
				ViewData	view(res);

				location_name.push_back("");
				locations.push_back(std::vector<std::string>(1));
				location_finded = true;
				view.move_pointer(10);
				if (view.skip_ws()) {
					if (view[0] != '{') {
						location_name.back() = view.subview_trunc(view.count_chars_until_some_char(" {\n\r\f\v\t")).to_string();
					} else {
						location_name.back() = "/";
					}
				} else {
					location_name.back() = "/";
				}
			} break ;
			case CGI_PASS: {
				ViewData	view(res);

				view.move_pointer(10);
				if (view.skip_ws()) {
					ViewData	path(view.subview_trunc(view.count_chars_until_ws()));

					view.move_pointer(path.size());
					if (view.skip_ws()) {
						ViewData	extension(view.subview_trunc(view.count_chars_until_ws()));

						if (extension[0] == '"') {
							extension.move_pointer();
							extension = extension.subview_trunc(extension.count_chars_until('"'));
						}
						_standart.setCGIserver(path.to_string(), extension.to_string());
					} else {
						std::cerr << "webserv: Config: Location: extension of CGI scripts not found in cgi_pass directive" << std::endl;
					}
				} else {
					std::cerr << "webserv: Config: Location: path to CGI binary not found in cgi_pass directive" << std::endl;
				}
				view.move_pointer(10);
			} break ;
			case CGI_PARAM:
				res = std::string(res, 10, res.size() - 10);
				p = findCGI(res);
				_standart.changeCGIparam(p, res);
				break;
			case INTERNAL:
				_standart.setIternal(true);
				break;
			case RETURN:
				res = std::string(res, 8, res.size() - 9);
				_standart.setReturnCode(static_cast<int>(std::strtol(res.c_str(), &k, 10)));
				res = std::string(res, k - res.c_str() + 1);
				_standart.setReturnUri(res);
				break;
			case AUTH_BASIC_USER_FILE:
				res = std::string(res, 22, res.size() - 23);
				_standart.setUserPassFile(res);
				break;
			case AUTH_BASIC: {
				ViewData	view(res);
				int			until_ws;

				view.move_pointer(12);
				if (view.skip_ws()) {
					until_ws = view.count_chars_until_ws();
					until_ws = until_ws < 0 ? view.size() : until_ws;
					_standart.setUserPassFile(ViewData(view, until_ws).to_string());
					view.move_pointer(until_ws);
					if (view.skip_ws()) {
						if (view[0] == '"') {
							view.move_pointer();
							until_ws = view.count_chars_until_not_escaped('"');
						} else {
							until_ws = view.count_chars_until_ws();
						}
						_standart.setRealm(view.subview_trunc(until_ws).to_string());
					} else {
						std::cerr << "webserv: Config: Location: the realm is not found in auth_basic directive" << std::endl;
					}
				} else {
					std::cerr << "webserv: Config: Location: the auth filename is not found in auth_basic directive" << std::endl;
				}
			} break ;
			case ALLOW_METHODS: {
				ViewData	view(res);

				view.move_pointer(15);
				_standart.clearMethods();
				while (view.skip_ws()) {
					ViewData	method_view(view.subview_trunc(view.count_chars_until_ws()));

					for (size_t method_index = 0; method_index < Method::Count; method_index += 1) {
						Method	method = Method::from_int(method_index);
						if (method_view.exact_equals(method.to_string())) {
							_standart.setMethod(method);
							break ;
						}
						if (method_index + 1 >= Method::Count) {
							std::cerr << "webserv: Config: Location: invalid method in allow_methods directive (" << method_view << ")" << std::endl;
						}
					}
					view.move_pointer(method_view.size());
				}
			} break ;
			case DENY_METHODS: {
				ViewData	view(res);

				view.move_pointer(14);
				while (view.skip_ws()) {
					ViewData	method_view(view.subview_trunc(view.count_chars_until_ws()));

					for (size_t method_index = 0; method_index < Method::Count; method_index += 1) {
						Method	method = Method::from_int(method_index);
						if (method_view.exact_equals(method.to_string())) {
							_standart.unsetMethod(method);
							break ;
						}
						if (method_index + 1 >= Method::Count) {
							std::cerr << "webserv: Config: Location: invalid method in allow_methods directive (" << method_view << ")" << std::endl;
						}
					}
					view.move_pointer(method_view.size());
				}
			} break ;
			case CGI_ALLOW_METHODS: {
				ViewData	view(res);

				view.move_pointer(19);
				_standart.clearCGIMethods();
				while (view.skip_ws()) {
					ViewData	method_view(view.subview_trunc(view.count_chars_until_ws()));

					for (size_t method_index = 0; method_index < Method::Count; method_index += 1) {
						Method	method = Method::from_int(method_index);
						if (method_view.exact_equals(method.to_string())) {
							_standart.setCGIMethod(method);
							break ;
						}
						if (method_index + 1 >= Method::Count) {
							std::cerr << "webserv: Config: Location: invalid method in cgi_allow_methods directive (" << method_view << ")" << std::endl;
						}
					}
					view.move_pointer(method_view.size());
				}
			} break ;
			case CGI_DENY_METHODS: {
				ViewData	view(res);

				view.move_pointer(18);
				while (view.skip_ws()) {
					ViewData	method_view(view.subview_trunc(view.count_chars_until_ws()));

					for (size_t method_index = 0; method_index < Method::Count; method_index += 1) {
						Method	method = Method::from_int(method_index);
						if (method_view.exact_equals(method.to_string())) {
							_standart.unsetCGIMethod(method);
							break ;
						}
						if (method_index + 1 >= Method::Count) {
							std::cerr << "webserv: Config: Location: invalid method in cgi_deny_methods directive (" << method_view << ")" << std::endl;
						}
					}
					view.move_pointer(method_view.size());
				}
			} break ;
			case DEFAULT_METHOD_BODY: {
				ViewData	view(res);

				view.move_pointer(21);
				if (view.skip_ws()) {
					ViewData	method_view(view.subview_trunc(view.count_chars_until_ws()));
					Method		method;

					for (size_t method_index = 0; method_index < Method::Count; method_index += 1) {
						method = Method::from_int(method_index);
						if (method_view.exact_equals(method.to_string())) {
							break ;
						}
						if (method_index + 1 >= Method::Count) {
							std::cerr << "webserv: Config: Location: invalid method in default_method_body directive (" << method_view << ")" << std::endl;
							method = Method::Invalid;
						}
					}
					view.move_pointer(method_view.size());
					if (method != Method::Invalid && view.skip_ws()) {
						if (view[0] == '"') {
							view.move_pointer();
							view = view.subview_trunc(view.count_chars_until('"'));
						}
						Location::MethodBody	body;
						body.ok = true;
						body.body = view.to_string();
						_standart.setDefaultMethodBody(method, body);
					} else {
						std::cerr << "webserv: Config: Location: body not found in default_method_body directive" << std::endl;
					}
				} else {
					std::cerr << "webserv: Config: Location: method not found in default_method_body directive" << std::endl;
				}
			} break ;
			case TIMEOUT: {
				ViewData	view(res);

				view.move_pointer(9);
				if (view.skip_ws()) {
					ViewData	number(view.subview_trunc(view.count_chars_until_ws()));

					_standart.setTimeout(number.to_long());
				}
			} break ;
			default:
				throw UnknownFeature();
				break;
			}
		if (location_finded)
		{
			if (res.find("{") != NPOS)
			{
				st.push('{');
				if (st.size() == 1)
					add = false;
			}
			if (res.find("}") != NPOS)
			{
				if (st.empty())
					throw NeedOpenParthenesException();
				st.pop();
				if (st.empty())
				{
					location_finded = false;
					add = false;
				}
			}
			if (location_finded && add)
				vec.push_back(res);
			add = true;
		}
	}
	for (size_t i = 0; i < locations.size(); i++)
	{
		if (locations[i].size() != 0)
		{
			_lock.push_back(_standart);
			_lock.back().construct(locations[i], location_name[i]);
		}
	}
}

ServerInfo &ServerInfo::operator=(const ServerInfo &copy)
{
	_names = copy._names;
	_host = copy._host;
	_lock = copy._lock;
	_standart = copy._standart;
	_port = copy._port;

	return *this;
}

void ServerInfo::setupTypes()
{
	std::pair<std::string, std::string> _save[] = 
	{
		std::pair<std::string,std::string>( "html", "text/html" ), 
		std::pair<std::string,std::string>( "htm", "text/html" ),
		std::pair<std::string,std::string>( "stml", "text/html" ),
		std::pair<std::string,std::string>( "css", "text/css" ),
		std::pair<std::string,std::string>( "xml", "text/xml" ),
		std::pair<std::string,std::string>( "rss", "text/xml" ),
		std::pair<std::string,std::string>( "txt", "text/plain" ),
		std::pair<std::string,std::string>( "htc", "text/x-component" ),
		std::pair<std::string,std::string>( "mml", "text/mathml" ),
		std::pair<std::string,std::string>( "gif", "image/gif" ),
		std::pair<std::string,std::string>( "jpeg", "image/jpeg" ),
		std::pair<std::string,std::string>( "jpg", "image/jpeg" ),
		std::pair<std::string,std::string>( "png", "image/png" ),
		std::pair<std::string,std::string>( "ico", "image/x-icon" ),
		std::pair<std::string,std::string>( "jng", "image/x-jng" ),
		std::pair<std::string,std::string>( "wbmp", "image/vnd.wap.wbmp" ),
		std::pair<std::string,std::string>( "js", "application/x-javascript" ),
		std::pair<std::string,std::string>( "jar", "application/java-archive" ),
		std::pair<std::string,std::string>( "war", "application/java-archive" ),
		std::pair<std::string,std::string>( "ear", "application/java-archive" ),
		std::pair<std::string,std::string>( "hqx", "application/mac-binhex40" ),
		std::pair<std::string,std::string>( "pdf", "application/pdf" ),
		std::pair<std::string,std::string>( "cco", "application/x-cocoa" ),
		std::pair<std::string,std::string>( "jardiff", "application/x-java-archive-diff" ),
		std::pair<std::string,std::string>( "jnlp", "application/x-java-jnlp-file" ),
		std::pair<std::string,std::string>( "run", "application/x-makeself" ),
		std::pair<std::string,std::string>( "pl", "application/x-perl" ),
		std::pair<std::string,std::string>( "pm", "application/x-perl" ),
		std::pair<std::string,std::string>( "prc", "application/x-pilot" ),
		std::pair<std::string,std::string>( "pdb", "application/x-pilot" ),
		std::pair<std::string,std::string>( "rar", "application/x-rar-compressed" ),
		std::pair<std::string,std::string>( "rpm", "application/x-redhat-package-manager" ),
		std::pair<std::string,std::string>( "sea", "application/x-sea" ),
		std::pair<std::string,std::string>( "swf", "application/x-shockwave-flash" ),
		std::pair<std::string,std::string>( "sit", "application/x-stuffit" ),
		std::pair<std::string,std::string>( "tcl", "application/x-tcl" ),
		std::pair<std::string,std::string>( "tk", "application/x-tcl" ),
		std::pair<std::string,std::string>( "der", "application/x-x509-ca-cert" ),
		std::pair<std::string,std::string>( "pem", "application/x-x509-ca-cert" ),
		std::pair<std::string,std::string>( "crt", "application/x-x509-ca-cert" ),
		std::pair<std::string,std::string>( "xpi", "application/x-xpinstall" ),
		std::pair<std::string,std::string>( "zip", "application/zip" ),
		std::pair<std::string,std::string>( "deb", "application/octet-stream" ),
		std::pair<std::string,std::string>( "bin", "application/octet-stream" ),
		std::pair<std::string,std::string>( "exe", "application/octet-stream" ),
		std::pair<std::string,std::string>( "dll", "application/octet-stream" ),
		std::pair<std::string,std::string>( "dmg", "application/octet-stream" ),
		std::pair<std::string,std::string>( "eot", "application/octet-stream" ),
		std::pair<std::string,std::string>( "iso", "application/octet-stream" ),
		std::pair<std::string,std::string>( "img", "application/octet-stream" ),
		std::pair<std::string,std::string>( "msi", "application/octet-stream" ),
		std::pair<std::string,std::string>( "msp", "application/octet-stream" ),
		std::pair<std::string,std::string>( "msm", "application/octet-stream" ),
		std::pair<std::string,std::string>( "mp3", "audio/mpeg" ),
		std::pair<std::string,std::string>( "ra", "audio/x-realaudio" ),
		std::pair<std::string,std::string>( "mp3", "audio/mpeg" ),
		std::pair<std::string,std::string>( "mpeg", "video/mpeg" ),
		std::pair<std::string,std::string>( "mpg", "video/mpeg" ),
		std::pair<std::string,std::string>( "mov", "video/quicktime" ),
		std::pair<std::string,std::string>( "flv", "video/x-flv" ),
		std::pair<std::string,std::string>( "avi", "video/x-msvideo" ),
		std::pair<std::string,std::string>( "wmv", "video/x-ms-wmv" ),
		std::pair<std::string,std::string>( "asx", "video/x-ms-asf" ),
		std::pair<std::string,std::string>( "asf", "video/x-ms-asf" ),
		std::pair<std::string,std::string>( "mng", "video/x-mng" )
	};
	for (int i = 0; i < 65; i++)
		_mime_types->insert(_save[i]);
}

int		ServerInfo::findCGI(std::string &str)
{
	if (str.find(" AUTH_TYPE ") != NPOS)
	{
		str = std::string(str, 11, str.size() - 12);
		return Location::AUTH_TYPE;
	}
	if (str.find(" CONTENT_LENGTH ") != NPOS)
	{
		str = std::string(str, 16, str.size() - 17);
		return Location::CONTENT_LENGTH;
	}
	if (str.find(" CONTENT_TYPE ") != NPOS)
	{
		str = std::string(str, 14, str.size() - 15);
		return Location::CONTENT_TYPE;
	}
	if (str.find(" GATEWAY_INTERFACE ") != NPOS)
	{
		str = std::string(str, 19, str.size() - 20);
		return Location::GATEWAY_INTERFACE;
	}
	if (str.find(" PATH_INFO ") != NPOS)
	{
		str = std::string(str, 11, str.size() - 12);
		return Location::PATH_INFO;
	}
	if (str.find(" PATH_TRANSLATED ") != NPOS)
	{
		str = std::string(str, 17, str.size() - 18);
		return Location::PATH_TRANSLATED;
	}
	if (str.find(" QUERY_STRING ") != NPOS)
	{
		str = std::string(str, 14, str.size() - 15);
		return Location::QUERY_STRING;
	}
	if (str.find(" REMOTE_ADDR ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return Location::REMOTE_ADDR;
	}
	if (str.find(" REMOTE_IDENT ") != NPOS)
	{
		str = std::string(str, 14, str.size() - 15);
		return Location::REMOTE_IDENT;
	}
	if (str.find(" REMOTE_USER ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return Location::REMOTE_USER;
	}
	if (str.find(" REQUEST_METHOD ") != NPOS)
	{
		str = std::string(str, 16, str.size() - 17);
		return Location::REQUEST_METHOD;
	}
	if (str.find(" REQUEST_URI ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return Location::REQUEST_URI;
	}
	if (str.find(" SCRIPT_NAME ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return Location::SCRIPT_NAME;
	}
	if (str.find(" SERVER_NAME ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return Location::SERVER_NAME;
	}
	if (str.find(" SERVER_PORT ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return Location::SERVER_PORT;
	}
	if (str.find(" SERVER_PROTOCOL ") != NPOS)
	{
		str = std::string(str, 17, str.size() - 18);
		return Location::SERVER_PROTOCOL;
	}
	if (str.find(" SERVER_SOFTWARE ") != NPOS)
	{
		str = std::string(str, 17, str.size() - 18);
		return Location::SERVER_SOFTWARE;
	}
	throw UnknownCGIParamException();
	return UNKNOWN;
}

int		ServerInfo::parse(std::string const &str)
{
	if (str.find(" listen ") != std::string::npos)
		return LISTEN;
	if (str.find(" server_name ") != std::string::npos)
		return SERVER_NAME;
	if (str.find(" client_max_body_size ") != std::string::npos)
		return CLIENT_MAX_BODY_SIZE;
	if (str.find(" root ") != std::string::npos)
		return ROOT;
	if (str.find(" index ") != std::string::npos)
		return INDEX;
	if (str.find(" autoindex ") != std::string::npos)
		return AUTOINDEX;
	if (str.find(" error_page ") != std::string::npos)
		return ERROR_PAGE;
	if (str.find(" location ") != std::string::npos)
		return LOCATION;
	if (str.find(" internal ") != std::string::npos)
		return INTERNAL;
	if (str.find(" cgi_pass ") != NPOS)
		return CGI_PASS;
	if (str.find(" cgi_param ") != NPOS)
		return CGI_PARAM;
	if (str.find(" return ") != NPOS)
		return RETURN;
	if (str.find(" auth_basic ") != NPOS)
		return AUTH_BASIC;
	if (str.find(" auth_basic_user_file ") != NPOS)
		return AUTH_BASIC_USER_FILE;
	if (str.find(" allow_methods ") != NPOS)
		return ALLOW_METHODS;
	if (str.find(" deny_methods ") != NPOS)
		return DENY_METHODS;
	if (str.find(" cgi_allow_methods ") != NPOS)
		return CGI_ALLOW_METHODS;
	if (str.find(" cgi_deny_methods ") != NPOS)
		return CGI_DENY_METHODS;
	if (str.find(" default_method_body ") != NPOS)
		return CGI_DENY_METHODS;
	if (str.find(" timeout ") != NPOS)
		return CGI_DENY_METHODS;
	return UNKNOWN;
}

void ServerInfo::remakeString(std::string &str)
{
	bool spc = true;
	std::string	out;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (std::isprint(str[i]) && str[i] != ' ')
		{
			out += str[i];
			spc = true;
		}
		else
		{
			if (spc)
			{
				out += ' ';
				spc = false;
			}
		}
	}
	str = out + " ";
}

const std::string &ServerInfo::getServerName(size_t index) const
{
	return _names[index];
}

size_t	ServerInfo::getServerNamesCount() const {
	return _names.size();
}

const std::string &ServerInfo::getHost() const
{
	return _host;
}

int	ServerInfo::getPort() const
{
	return _port;
}

void ServerInfo::Validator()
{
	_standart.Validator();
	for (size_t i = 0; i < _lock.size(); i++)
		_lock[i].Validator();
}

std::string ServerInfo::getMimeTypes(std::string const &str) const
{
	std::map<std::string, std::string>::iterator k;
	if ((k = _mime_types->find(str)) != _mime_types->end())
		return k->second;
	return "";
}

const Location	*ServerInfo::findLocation(Path const &request_path, Path &location_path) const
{
	const Location	*result = 0;

	for (size_t i = 0; result == 0 && i < _lock.size(); i++) {
		result = _lock[i].findLocation(request_path, location_path);
	}
	if (!result) {
		result = &_standart;
	}
	return (result);
}

const Location	*ServerInfo::getRootLocation() const {
	return &_standart;
}
