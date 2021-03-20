/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:57:36 by tclaudin          #+#    #+#             */
/*   Updated: 2021/03/16 11:49:37 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <iostream>
#include <exception>
#include <arpa/inet.h>
#include <sys/select.h>
#include <fcntl.h>

struct CannotPrepareServer : std::exception {
	std::string	reason;

	CannotPrepareServer(size_t index) {
		std::ostringstream	text;

		text << "ServerInfo index: " << index;
		reason = text.str();
	}
	~CannotPrepareServer() throw() {}
	const char	*what() const throw() {
		return reason.c_str();
	}
};

struct server_info { std::string host; int port; };

bool	g_print = false;

int main(int argc, char *argv[]) {
	int		return_code = 0;

	try {
		Config				config(argc >= 2 ? argv[1] : "webserv.conf");
		std::vector<Server>	servers;
		bool		should_continue = true;
		fd_set		read_set;
		fd_set		write_set;
		int			max_fd;
		int			selected;
		struct timeval	timeout = { 15, 0 };

		servers.reserve(config.get_server_count()); /* note: prevent reallocation during filling (destructor closes servers' sockets) */
		{
			std::vector<server_info> servers_info;

			for (size_t index = 0; index < config.get_server_count(); index += 1) {
				const ServerInfo	&info = config.get_server_info(index);
				bool				found = false;

				for (size_t server_index = 0; server_index < servers_info.size(); server_index += 1) {
					if (servers_info[server_index].port == info.getPort() && servers_info[server_index].host == info.getHost()) {
						found = true;
						break ;
					}
				}
				if (found) {
					continue ;
				} else {
					servers.push_back(Server(info));
					if (!servers.back().prepare()) {
						throw CannotPrepareServer(index);
					} else {
						servers_info.push_back((server_info){ info.getHost(), info.getPort() });
						for (size_t next = index + 1; next < config.get_server_count(); next += 1) {
							if (config.get_server_info(next).getPort() == info.getPort() && config.get_server_info(next).getHost() == info.getHost()) {
								servers.back().add_server_info(config.get_server_info(next));
							}
						}
					}
				}
			}
		}
		do {
			FD_ZERO(&read_set);
			FD_ZERO(&write_set);
			max_fd = 0;
			for (size_t index = 0; index < servers.size(); index += 1) {
				max_fd = std::max(max_fd, servers[index].construct_fd_sets_and_return_maximum_fd(read_set, write_set));
			}
			timeout.tv_sec = 15;
			timeout.tv_usec = 0;
			selected = select(max_fd + 1, &read_set, &write_set, 0, &timeout);
			if (selected < 0) {
				perror("webserv: select");
				return_code = 2;
				should_continue = false;
			} else if (selected == 0) {
				if (g_print) std::cerr << "select timeout" << std::endl;
			}
			for (size_t index = 0; index < servers.size(); index += 1) {
				return_code = servers[index].evaluate(read_set, write_set);
				if (return_code != 0) {
					should_continue = false;
					break ;
				}
			}
		} while (should_continue);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return_code = 1;
	}
	return (return_code);
}
