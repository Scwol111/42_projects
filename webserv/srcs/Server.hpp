/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:44:14 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/14 16:11:14 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <string>
#include <list>

#include "Client.hpp"
#include "Config.hpp"

class Server {
private:

	std::vector<const ServerInfo *>	m_server_infos;
	int								m_socket;

	std::list<Client>	m_clients;

public:
	Server(const ServerInfo &server_info);
	Server(const Server &);
	~Server();
	Server	&operator=(const Server &);

	bool	prepare();

	int		construct_fd_sets_and_return_maximum_fd(fd_set &read_set, fd_set &write_set);
	int		evaluate(fd_set &read_set, fd_set &write_set);

	void	add_server_info(const ServerInfo &);
	int		get_socket() const {
		return m_socket;
	}

private:

	int		grub_fd_from_clients_and_return_maximum_fd(fd_set &read_set, fd_set &write_set);
	void	evaluate_clients_code(fd_set &read_set, fd_set &write_set);

	const ServerInfo	*find_server_info_by_host(const ViewData &host);

};

#endif /* SERVER_HPP */
