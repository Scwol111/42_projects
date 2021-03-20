/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:42:37 by tclaudin          #+#    #+#             */
/*   Updated: 2021/03/14 18:00:29 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Location.hpp"
#include <sstream>

Location::Location()
	: _index()
	, _root("./")
	, _cgi_info(MAXIMALS)
	, _iternal(false)
	, _autoindex(false)
	, _max_body_size(100000000)
	, _cgi(false)
	, _realm("off")
	, _timeout(600)
{
}

Location::Location(const Location &copy)
{
	*this = copy;
}

Location::~Location()
{
}

void Location::construct(std::vector<std::string> &str, std::string const &name)
{
	bool						location_finded = false;
	std::stack<char>			st;
	std::vector<std::vector<std::string> >	locations;
	std::vector<std::string> 				location_name;
	bool						add = false;

	_name = name;
	for (size_t i = 0; i < str.size(); i++)
	{
		std::vector<std::string>	&vec = locations.back();
		std::string	res = str[i];
		std::string idx;
		int		p;
		// size_t	r;
		char	*k;

		if (!location_finded && res.size() != 0)
			switch (parse(res))
			{
			case CLIENT_MAX_BODY_SIZE:
				setMaxBodySize(std::stol(std::string(res, 22, res.size() - 23)));
				break;
			case ROOT:
				setRoot(std::string(res, 6, res.size() - 7));
				break;
			case INDEX: {
				ViewData	view(res);

				_index.clear();
				view.move_pointer(7);
				while (view.skip_ws()) {
					ViewData	indexfile(view.subview_trunc(view.count_chars_until_ws()));
					addIndex(indexfile.to_string());
					view.move_pointer(indexfile.size());
				}
			} break ;
			case AUTOINDEX:
				idx = std::string(res, 11, res.size() - 12);
				if (idx == "off")
					setAutoindex(false);
				else if (idx == "on")
						setAutoindex(true);
					else
						throw UnknownParamException();
				break;
			case ERROR_PAGE:
				addErrors(std::string(res, 11, res.size() - 12));
				break;
			case LOCATION: {
				ViewData	view(res);

				location_finded = true;
				location_name.push_back("");
				locations.push_back(std::vector<std::string>(1));
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
						setCGIserver(path.to_string(), extension.to_string());
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
				changeCGIparam(p, res);
				break;
			case INTERNAL:
				setIternal(true);
				break;
			case RETURN:
				res = std::string(res, 8, res.size() - 9);
				setReturnCode(static_cast<int>(std::strtol(res.c_str(), &k, 10)));
				res = std::string(res, k - res.c_str() + 1);
				setReturnUri(res);
				break;
			case AUTH_BASIC: {
				ViewData	view(res);
				int			until_ws;

				view.move_pointer(12);
				if (view.skip_ws()) {
					until_ws = view.count_chars_until_ws();
					until_ws = until_ws < 0 ? view.size() : until_ws;
					setUserPassFile(ViewData(view, until_ws).to_string());
					view.move_pointer(until_ws);
					if (view.skip_ws()) {
						if (view[0] == '"') {
							view.move_pointer();
							until_ws = view.count_chars_until_not_escaped('"');
						} else {
							until_ws = view.count_chars_until_ws();
						}
						setRealm(view.subview_trunc(until_ws).to_string());
					} else {
						std::cerr << "webserv: Config: Location: the realm is not found in auth_basic directive" << std::endl;
					}
				} else {
					std::cerr << "webserv: Config: Location: the auth filename is not found in auth_basic directive" << std::endl;
				}
			} break ;
			case ALLOW_METHODS: {
				ViewData	view(res);

				_allow_methods.clear();
				view.move_pointer(15);
				while (view.skip_ws()) {
					ViewData	method_view(view.subview_trunc(view.count_chars_until_ws()));

					for (size_t method_index = 0; method_index < Method::Count; method_index += 1) {
						Method	method = Method::from_int(method_index);
						if (method_view.exact_equals(method.to_string())) {
							_allow_methods.set(method);
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
							_allow_methods.unset(method);
							break ;
						}
						if (method_index + 1 >= Method::Count) {
							std::cerr << "webserv: Config: Location: invalid method in deny_methods directive (" << method_view << ")" << std::endl;
						}
					}
					view.move_pointer(method_view.size());
				}
			} break ;
			case CGI_ALLOW_METHODS: {
				ViewData	view(res);

				view.move_pointer(19);
				_cgi_allow_methods.clear();
				while (view.skip_ws()) {
					ViewData	method_view(view.subview_trunc(view.count_chars_until_ws()));

					for (size_t method_index = 0; method_index < Method::Count; method_index += 1) {
						Method	method = Method::from_int(method_index);
						if (method_view.exact_equals(method.to_string())) {
							_cgi_allow_methods.set(method);
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
							_cgi_allow_methods.unset(method);
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
						_default_method_body[method].ok = true;
						_default_method_body[method].body = view.to_string();
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

					_timeout = number.to_long();
				}
			} break ;
			default:
				std::cout << res.size() << res << std::endl;
				throw UnknownFeature(res);
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
			{
				vec.push_back(res);
			}
			add = true;
		}
	}
	for (size_t i = 0; i < locations.size(); i++)
	{
		if (locations[i].size() != 0)
		{
			_lock.push_back(*this);
			_lock.back().construct(locations[i], location_name[i]);
		}
	}
}

int		Location::findCGI(std::string &str)
{
	if (str.find(" AUTH_TYPE ") != NPOS)
	{
		str = std::string(str, 11, str.size() - 12);
		return AUTH_TYPE;
	}
	if (str.find(" CONTENT_LENGTH ") != NPOS)
	{
		str = std::string(str, 16, str.size() - 17);
		return CONTENT_LENGTH;
	}
	if (str.find(" CONTENT_TYPE ") != NPOS)
	{
		str = std::string(str, 14, str.size() - 15);
		return CONTENT_TYPE;
	}
	if (str.find(" GATEWAY_INTERFACE ") != NPOS)
	{
		str = std::string(str, 19, str.size() - 20);
		return GATEWAY_INTERFACE;
	}
	if (str.find(" PATH_INFO ") != NPOS)
	{
		str = std::string(str, 11, str.size() - 12);
		return PATH_INFO;
	}
	if (str.find(" PATH_TRANSLATED ") != NPOS)
	{
		str = std::string(str, 17, str.size() - 18);
		return PATH_TRANSLATED;
	}
	if (str.find(" QUERY_STRING ") != NPOS)
	{
		str = std::string(str, 14, str.size() - 15);
		return QUERY_STRING;
	}
	if (str.find(" REMOTE_ADDR ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return REMOTE_ADDR;
	}
	if (str.find(" REMOTE_IDENT ") != NPOS)
	{
		str = std::string(str, 14, str.size() - 15);
		return REMOTE_IDENT;
	}
	if (str.find(" REMOTE_USER ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return REMOTE_USER;
	}
	if (str.find(" REQUEST_METHOD ") != NPOS)
	{
		str = std::string(str, 16, str.size() - 17);
		return REQUEST_METHOD;
	}
	if (str.find(" REQUEST_URI ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return REQUEST_URI;
	}
	if (str.find(" SCRIPT_NAME ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return SCRIPT_NAME;
	}
	if (str.find(" SERVER_NAME ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return SERVER_NAME;
	}
	if (str.find(" SERVER_PORT ") != NPOS)
	{
		str = std::string(str, 13, str.size() - 14);
		return SERVER_PORT;
	}
	if (str.find(" SERVER_PROTOCOL ") != NPOS)
	{
		str = std::string(str, 17, str.size() - 18);
		return SERVER_PROTOCOL;
	}
	if (str.find(" SERVER_SOFTWARE ") != NPOS)
	{
		str = std::string(str, 17, str.size() - 18);
		return SERVER_SOFTWARE;
	}
	throw UnknownCGIParamException();
	return UNKNOWN;
}

int		Location::parse(std::string const &str)
{
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
		return DEFAULT_METHOD_BODY;
	if (str.find(" timeout ") != NPOS)
		return TIMEOUT;
	return UNKNOWN;
}

Location &Location::operator=(const Location &copy)
{
	_index = copy._index;
	_name = copy._name;
	_root = copy._root;
	_cgi_info = copy._cgi_info;
	_lock = copy._lock;
	_iternal = copy._iternal;
	_autoindex = copy._autoindex;
	_max_body_size = copy._max_body_size;
	_errors = copy._errors;
	_cgi_serv = copy._cgi_serv;
	_cgi_ext = copy._cgi_ext;
	_cgi = copy._cgi;
	_return_uri = copy._return_uri;
	_return_code = copy._return_code;
	_realm = copy._realm;
	_user_pass_file = copy._user_pass_file;
	_allow_methods = copy._allow_methods;
	_cgi_allow_methods = copy._cgi_allow_methods;
	for (size_t index = 0; index < Method::Count; index += 1) {
		_default_method_body[index] = copy._default_method_body[index];
	}
	_timeout = copy._timeout;
	return *this;
}

void	Location::setAutoindex(bool fl)
{
	_autoindex = fl;
}

void	Location::setIternal(bool fl)
{
	_iternal = fl;
}

void	Location::setRoot(const std::string &str)
{
	_root = str;
}

void	Location::addIndex(const std::string &str)
{
	_index.push_back(str);
}

void	Location::setName(const std::string &str)
{
	_name = str;
}

void	Location::setMaxBodySize(const long n)
{
	_max_body_size = n;
}

void	Location::setRealm(std::string const &str)
{
	_realm = str;
}

void	Location::setUserPassFile(std::string const &str)
{
	_user_pass_file = str;
}

void	Location::setDefaultMethodBody(Method method, MethodBody const &body) {
	_default_method_body[method] = body;
}

void	Location::clearMethods() {
	_allow_methods.clear();
}

void	Location::setMethod(const Method &method) {
	_allow_methods.set(method);
}

void	Location::unsetMethod(const Method &method) {
	_allow_methods.unset(method);
}

void	Location::setTimeout(time_t time) {
	_timeout = time;
}

void	Location::clearCGIMethods() {
	_cgi_allow_methods.clear();
}

void	Location::setCGIMethod(const Method &method) {
	_cgi_allow_methods.set(method);
}

void	Location::unsetCGIMethod(const Method &method) {
	_cgi_allow_methods.unset(method);
}

void	Location::changeCGIparam(const int i, const std::string &str)
{
	if (i < MAXIMALS && i >= 0)
		_cgi_info[i] = str;
}

size_t	Location::getMaxBodySize() const
{
	return _max_body_size;
}

const std::string	&Location::getRoot() const
{
	return _root;
}

const std::string	&Location::getCGIparam(cgi_params i) const
{
	if (i >= MAXIMALS || i < 0)
		throw OutOfRangeException();
	return _cgi_info[i];	
}

const std::string &Location::getName() const
{
	return _name;
}

const std::string &Location::getCGIserver() const
{
	return _cgi_serv;
}

const std::string	&Location::getCGIextension() const {
	return _cgi_ext;
}

void Location::setCGIserver(std::string const &path, std::string const &ext)
{
	_cgi_serv = path;
	_cgi_ext = ext;
	_cgi = true;
}

bool Location::getInternal() const
{
	return _iternal;
}

bool Location::getAutoindex() const
{
	return _autoindex;
}

const Method::Set	&Location::getMethodSet() const {
	return _allow_methods;
}

const Method::Set	&Location::getCGIMethodSet() const {
	return _cgi_allow_methods;
}

const Location::MethodBody	&Location::getDefaultMethodBody(Method method) const {
	return _default_method_body[method];
}

time_t		Location::getTimeout() const {
	return _timeout;
}

void	Location::addErrors(std::string const &s)
{
	char	*p;
	std::string str(s);
	int x;
	size_t i;

	_errors.push_back(ErrorInfo());
	i = _errors.size() - 1;
	while (true)
	{
		if ((x = static_cast<int>(std::strtol(str.c_str(), &p, 10))) != 0)
			_errors[i].addCode(x);
		else if (str[0] == '=')
		{
			x = static_cast<int>(std::strtol(str.c_str() + 1, &p, 10));
			_errors.back().setRequest(x);
		}
		else
			break ;
		str = std::string(str, p - str.c_str() + 1);
	}
	_errors.back().setName(str);
}

void	Location::Validator()
{
	
}

const Location	*Location::findLocation(Path const &request_path, Path &location_path) const
{
	const Location	*result = 0;

	if (location_path.is_intermediate_subpath_of(ViewData(_name), request_path)) {
		location_path.append_segments(_name);
 		location_path.reduce_dot_segments();
		for (size_t i = 0; result == 0 && i < _lock.size(); i++) {
			result = _lock[i].findLocation(request_path, location_path);
		}
		if (!result) {
			result = this;
		}
	}
	return (result);
}

void	Location::setReturnCode(int code)
{
	_return_code = code;
}

void	Location::setReturnUri(std::string const &str)
{
	_return_uri = str;
}

std::string Location::remakeString(std::string &str) const
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
	return out;
}

std::string Location::createErrorHTML(StatusCode x, const std::string &message)
{
	std::ostringstream	text;

	text << "<html><head><title>Error " << x.to_int() << "</title></head><body><table><tr><h1 align=\"center\">Error ";
	text << x.to_int() << ": " + x.to_string() << "</h1></tr><tr><h3 align=\"center\">" << (message.size() > 0 ? message : "webserv/1.0") << "</h3></tr></table></body></html>";
	return text.str();
}

bool	Location::hasCGIServ() const
{
	return _cgi;
}

std::string Location::getErrorPage(StatusCode x, const std::string &message) const
{
	std::string res, buff;

	for (size_t i = 0; i < _errors.size(); i++)
		if ((res = _errors[i].findError(x.to_int())) != "")
			break;
	if (res == "")
		return createErrorHTML(x, message);

	std::ifstream ifs(res);
	if (!ifs.is_open())
		return createErrorHTML(x, message);
	res = "";
	while (std::getline(ifs, buff, '\n'))
		res += remakeString(buff);
	return res;
}

int	Location::getReturnCode() const
{
	return _return_code;
}

const std::string	&Location::getReturnUri() const
{
	return _return_uri;
}

const std::string &Location::getRealm() const
{
	return _realm;
}

const std::string &Location::getUserPassFile() const
{
	return _user_pass_file;
}

bool				Location::isAuthNeeded() const {
	return (_user_pass_file.size() > 0 && _realm.size() > 0);
}

size_t				Location::getIndexFilesCount() const {
	return (_index.size());
}

const std::string	&Location::getIndexFileName(size_t index) const {
	return (_index[index]);
}

void	Location::clearIndex()
{
	_index.clear();
}
