/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:02:01 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/15 19:09:50 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP


#include "MessageBody.hpp"
#include "ViewData.hpp"
#include "Path.hpp"
#include "ServerInfo.hpp"
#include "Headers/Header.hpp"
#include "HeaderParser.hpp"
#include "HeaderSection/RequestHeaderSection.hpp"
#include "HeaderSection/ResponseHeaderSection.hpp"

class Client {
public:
	struct Info {
		std::string	ip;
		unsigned	port;
	};

private:

	enum	StateEnum {
		State_Read_Request,
		State_Choose_Server_Info,
		State_Auth,
		State_Read_Request_Body,
		State_Write_File,
		State_Read_File,
		State_Launch_CGI,
		State_Write_CGI,
		State_Read_CGI_Headers,
		State_Read_CGI_Body,
		State_CGI_Select,
		State_CGI_Checker,
		State_CGI_Finish,
		State_Response,
		State_Keep_Connection,
		State_Finish,
		State_Invalid,
	};

	static const std::string m_state_to_string[State_Invalid];

	struct	RequestBodyState {
		enum	InternalStateEnum {
			Initial,
			Read_Sized,
			Read_Chunked_Header,
			Read_Chunked_Body,
			Read_Chunked_Trailing,
			Finish,
			Count,
		};

		size_t				size;
		size_t				start_size;
		bool				is_chunked;
		StateEnum			next_state;
		InternalStateEnum	state;
		std::string			remainer;

		static const std::string	strings[Count];
	};

	struct CGIState {
		std::string	binary_path;
		pid_t		pid;
		size_t		written;
		size_t		readed;
		int			read_fd;
		int			write_fd;
		bool		ok;
		bool		write_done;
		bool		headers_done;
		bool		body_done;
		std::string	remainer;

		CGIState(): pid(-1), written(0), readed(0), read_fd(-1), write_fd(-1), ok(true), write_done(false), headers_done(false), body_done(false) {}
	};

	struct CgiParam {
		static const std::string	strings[Location::MAXIMALS];
	};

	struct Auth {
		enum EnumType {
			None,
			Basic,
		};
		EnumType	type;
		std::string	username;
		size_t		index;

		Auth(): type(None) {}
	};

	struct ResponseState {
		bool		is_headers_sended;
		size_t		body_sended;
		StateEnum	next_state;
		bool		header_check;
		bool		disable_body;
		std::string	remainer;

		ResponseState(): is_headers_sended(false), body_sended(0), next_state(State_Keep_Connection), header_check(true), disable_body(false) {}
	};

private:

	const ServerInfo	*m_server_info;
	const Location		*m_location;

	int			m_socket;
	time_t		m_time;

	std::string	m_line_buffer;

	Path		m_location_subtracted_path;
	Path		m_fs_root_path;
	Path		m_requested_resource_path;
	Path		m_fs_requested_resource_path;
	Path		m_fs_script_path;
	Path		m_script_name;
	Path		m_script_path_info;
	Path		m_script_path_translated;

	StateEnum	m_state;

	RequestBodyState		m_request_body_state;
	RequestHeaderSection	m_request;
	MessageBody				m_request_body;
	ResponseHeaderSection	m_response;
	MessageBody				m_response_body;

	std::vector<std::string>	m_read_path;
	size_t						m_read_path_index;

	CGIState				m_cgi;
	Auth					m_auth;
	Info					m_info;
	ResponseState			m_response_state;

	bool		m_debug_print;

	Client();
	Client	&operator=(const Client &);
public:
	Client(int socket, time_t birth_time_secs, Info);
	Client(const Client &);
	~Client();

	void	do_work(bool is_read, bool is_write, time_t current_time);
	int		select_read_fd();
	int		select_write_fd();
	bool	bypass_select(StateEnum = State_Invalid) const;
	bool	kill_me();
	void	check_time(time_t secs);

	void	free_resources();

	bool		is_need_choose_server_info() const;
	std::string	get_host_header() const;
	void		set_server_info(const ServerInfo &);

private:

	StateEnum	read_request();
	StateEnum	read_request_body();
	StateEnum	analyze_request();
	StateEnum	send_response();

	bool	read_file(const ViewData &filename, MessageBody &output);

	void	make_errorpage_response(StatusCode, const std::string &message = "");
	void	make_unauthorized_response();
	void	make_autoindex_response();
	void	make_redirect_response(StatusCode, const std::string &uri);
	void	make_default_method_body_response(Method);
	void	make_method_not_allowed_response();
	StateEnum	make_continue(StateEnum next_state);

	static bool		is_file_exists(const std::string &path);
	static bool		is_directory(const std::string &path);
	static size_t	get_file_size(const std::string &path);

	bool		is_script_path(const Path &);

	StateEnum	execute_cgi();
	StateEnum	write_cgi();
	StateEnum	read_cgi_headers();
	StateEnum	read_cgi_body();
	std::string	make_cgi_parameter_value(Location::cgi_params);
	static std::string	field_name_to_cgi_param_format(const std::string &);

	bool			make_script_path();
	static ViewData	get_query_part(const ViewData &);
	bool			make_request_body_state();

	bool				get_auth_from_request(std::string &username, std::string &password) const;
	static std::string	decode_base64_string(const ViewData &);
	StateEnum			auth(const ViewData &auth_username, const ViewData &auth_password);

};


#endif /* CLIENT_HPP */
