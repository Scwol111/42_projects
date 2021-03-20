/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:54:32 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/14 16:28:10 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <fcntl.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

Server::Server(const ServerInfo &server_info)
	: m_socket(-1)
	{ m_server_infos.push_back(&server_info); }

Server::~Server() {
	if (m_socket >= 0) {
		close(m_socket);
	}
}

Server::Server(const Server &server)
	: m_server_infos(server.m_server_infos)
	, m_socket(server.m_socket)
	, m_clients(server.m_clients)
	{}

bool	Server::prepare() {
	struct sockaddr_in	in_addr;
	bool				result = false;

	bzero(&in_addr, sizeof(in_addr));
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(m_socket >= 0) {
		fcntl(m_socket, F_SETFL, O_NONBLOCK);
		in_addr.sin_family = AF_INET;
		std::cerr << "port: " << m_server_infos[0]->getPort() << std::endl;
		in_addr.sin_port = htons(m_server_infos[0]->getPort());
		std::cerr << "host: " << m_server_infos[0]->getHost() << std::endl;
		inet_aton(m_server_infos[0]->getHost().c_str(), &in_addr.sin_addr);
		if ((bind(m_socket, reinterpret_cast<struct sockaddr *>(&in_addr), sizeof (struct sockaddr))) >= 0) {
			if (listen(m_socket, 1000) >= 0) {
				result = true;
			} else {
				perror("listen error");
			}
		} else {
	    	perror("bind error");
		}
	} else {
		perror("socket error");
	}
	return (result);
}

int		Server::construct_fd_sets_and_return_maximum_fd(fd_set &read_set, fd_set &write_set) {
	FD_SET(m_socket, &read_set);
	return std::max(m_socket, grub_fd_from_clients_and_return_maximum_fd(read_set, write_set));
}

int		Server::evaluate(fd_set &read_set, fd_set &write_set) {
	int		code = 0;

	if (FD_ISSET(m_socket, &read_set)) {
		struct sockaddr_in	in_addr;
		socklen_t			len;
		int					client_socket;

		client_socket = accept(m_socket, reinterpret_cast<struct sockaddr *>(&in_addr), &len);
		if (client_socket >= 0) {
			Client::Info	info;
			struct timeval	tv;

			gettimeofday(&tv, 0);
			info.ip = inet_ntoa(in_addr.sin_addr);
			info.port = ntohs(in_addr.sin_port);
			int		boolean = 1;
			setsockopt(client_socket, SOL_SOCKET, SO_NOSIGPIPE, &boolean, sizeof (int));
			setsockopt(client_socket, SOL_SOCKET, SO_KEEPALIVE, &boolean, sizeof (int));
			m_clients.push_back(Client(client_socket, tv.tv_sec, info));
		} else {
			perror("webserv: accept");
			code = 3;
		}
	}
	if (code == 0) {
		evaluate_clients_code(read_set, write_set);
	}
	return (code);
}

void	Server::add_server_info(const ServerInfo &server_info) {
	m_server_infos.push_back(&server_info);
}

int		Server::grub_fd_from_clients_and_return_maximum_fd(fd_set &read_set, fd_set &write_set) {
	int							max_fd = -1;
	std::list<Client>::iterator	it;

	it = m_clients.begin();
	while (it != m_clients.end()) {
		int		fd;

		fd = it->select_read_fd();
		if (fd >= 0) {
			FD_SET(fd, &read_set);
			max_fd = std::max(max_fd, fd);
		}
		fd = it->select_write_fd();
		if (fd >= 0) {
			FD_SET(fd, &write_set);
			max_fd = std::max(max_fd, fd);
		}
		++it;
	}
	return (max_fd);
}

void	Server::evaluate_clients_code(fd_set &read_set, fd_set &write_set) {
	std::list<Client>::iterator	it;
	struct timeval	tv;

	gettimeofday(&tv, 0);
	it = m_clients.begin();
	while (it != m_clients.end()) {
		int		fd;
		bool	is_read, is_write;

		fd = it->select_read_fd();
		if (fd >= 0) {
			is_read = FD_ISSET(fd, &read_set);
		} else {
			is_read = false;
		}
		fd = it->select_write_fd();
		if (fd >= 0) {
			is_write = FD_ISSET(fd, &write_set);
		} else {
			is_write = false;
		}
		it->check_time(tv.tv_sec);
		if (is_read || is_write || it->bypass_select()) {
			it->do_work(is_read, is_write, tv.tv_sec);
			if (it->is_need_choose_server_info()) {
				std::string	host = it->get_host_header();
				it->set_server_info(*find_server_info_by_host(host));
				if (it->bypass_select()) {
					it->do_work(false, false, tv.tv_sec);
				}
			}
		}
		if (it->kill_me()) {
			it->free_resources();
			it = m_clients.erase(it);
		} else {
			++it;
		}
	}
}

const ServerInfo	*Server::find_server_info_by_host(const ViewData &host_) {
	const ServerInfo	*result = m_server_infos[0];
	int					until_colon = host_.count_chars_until(':');
	ViewData			host(host_, until_colon < 0 ? host_.size() : until_colon);

	if (host.size() > 0) {
		for (size_t server_info_index = 0; server_info_index < m_server_infos.size(); server_info_index += 1) {
			const ServerInfo	*info = m_server_infos[server_info_index];
			size_t name_index = 0;

			for (; name_index < info->getServerNamesCount(); name_index += 1) {
				if (ViewData(info->getServerName(name_index)).exact_equals(host)) {
					break ;
				}
			}
			if (name_index < info->getServerNamesCount()) {
				result = info;
				break ;
			}
		}
	}
	return (result);
}
