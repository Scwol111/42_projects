/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:55:07 by jsandsla          #+#    #+#             */
/*   Updated: 2021/02/21 13:57:59 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include "ServerInfo.hpp"
// #include "Location.hpp"


/* Configuration state of the server. */
/* Constructor must throw exception if error occurred while parsing the config file. */

class Config {
private:
	std::vector<ServerInfo> _servers;

	Config();
	Config(const Config &);
	void	validation();
	Config	&operator=(const Config &);
	
public:
	Config(const std::string &filename);
	~Config();

	ServerInfo &get_server_info(size_t);
	size_t get_server_count() const;
	
	class UnknownParams: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class BadConfgFile: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NotEnoughParthenes: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NeedOpenParthenesException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class OutOfRangeException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif /* CONFIG_HPP */
