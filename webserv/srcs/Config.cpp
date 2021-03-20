/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:57:25 by jsandsla          #+#    #+#             */
/*   Updated: 2021/02/21 14:01:53 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

Config::Config()
{
	std::ifstream ifs("webserv.conf");
	std::string str;
	std::stack<char> st;
	std::vector<std::string> res;
	bool			server_get = false;
	bool			add = false;

	if (!ifs.is_open())
		throw BadConfgFile();
	
	while (std::getline(ifs, str, '\n'))
	{
		if (!server_get)
			if (str.find("server") != std::string::npos && str.find("server_name") == std::string::npos)
			{
				server_get = true;
				add = false;
			}
		if(server_get)
		{
			if (str.find("{") != std::string::npos)
			{
				st.push('{');
				if (st.size() == 1)
					add = false;
			}	
			else if (str.find("}") != std::string::npos)
			{
				if (st.empty())
					throw NeedOpenParthenesException();
				st.pop();
				if (st.empty())
				{
					_servers.push_back(ServerInfo(res));
					res.clear();
					server_get = false;
					add = false;
				}
			}
			if (server_get && add)
			{
				size_t end = str.find(';');
				size_t start;
				for (start = 0; start < str.size() && !std::isprint(str[start]) && str[start] != ' '; ) 
					start++;
				if (end == std::string::npos)
					end = str.size();
				std::string new_string(str, start, end - start);
				if (new_string.size() != 0)
					res.push_back(new_string);
			}
			add = true;
		}
	}
	validation();
}

Config::Config(const std::string &filename)
{
	std::ifstream ifs(filename);
	std::string str;
	std::stack<char> st;
	std::vector<std::string> res;
	bool			server_get = false;
	bool			add = false;

	if (!ifs.is_open())
		throw BadConfgFile();
	
	while (std::getline(ifs, str, '\n'))
	{
		if (!server_get)
			if (str.find("server") != std::string::npos && str.find("server_name") == std::string::npos)
			{
				server_get = true;
				add = false;
			}
		if(server_get)
		{
			if (str.find("{") != std::string::npos)
			{
				st.push('{');
				if (st.size() == 1)
					add = false;
			}	
			else if (str.find("}") != std::string::npos)
			{
				if (st.empty())
					throw NeedOpenParthenesException();
				st.pop();
				if (st.empty())
				{
					_servers.push_back(ServerInfo(res));
					res.clear();
					server_get = false;
					add = false;
				}
			}
			if (server_get && add)
			{
				size_t end = str.find(';');
				size_t start;
				for (start = 0; start < str.size() && !std::isprint(str[start]) && str[start] != ' '; ) 
					start++;
				if (end == std::string::npos)
					end = str.size();
				std::string new_string(str, start, end - start);
				if (new_string.size() != 0)
					res.push_back(new_string);
			}
			add = true;
		}
	}
	validation(); // need it
}

Config::Config(const Config &copy)
{
	*this = copy;
}

Config::~Config()
{
}

Config	&Config::operator=(const Config &copy)
{
	_servers = copy._servers;
	return *this;
}

ServerInfo &Config::get_server_info(size_t n)
{
	if (n < _servers.size())
		return _servers[n];
	throw OutOfRangeException();
}

size_t Config::get_server_count() const
{
	return _servers.size();
}

void	Config::validation()
{
	for (size_t i = 0; i < _servers.size(); i++)
		_servers[i].Validator();
}

const char *Config::UnknownParams::what() const throw()
{
	return "Unknown parametrs in configurtion file";
}

const char *Config::BadConfgFile::what() const throw()
{
	return "Bad configuration file";
}

const char *Config::NeedOpenParthenesException::what() const throw()
{
	return "Configuration file have closed parthenes, but don't have opened parthenes";
}

const char *Config::NotEnoughParthenes::what() const throw()
{
	return "Need parentheses";
}

const char *Config::OutOfRangeException::what() const throw()
{
	return "Index out of range";
}