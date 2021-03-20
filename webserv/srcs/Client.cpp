/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:18:22 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/16 11:51:36 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <iostream>

#include "Headers/ServerHeader.hpp"
#include "Headers/ContentLength.hpp"
#include "Headers/ContentType.hpp"
#include "Headers/ContentLanguage.hpp"
#include "Headers/Date.hpp"
#include "Headers/LastModified.hpp"
#include "Headers/ContentLocation.hpp"
#include "Headers/ContentLocation.hpp"
#include "Headers/LocationHeader.hpp"
#include "Path.hpp"

const std::string	Client::CgiParam::strings[Location::MAXIMALS] = {
	"AUTH_TYPE", "CONTENT_LENGTH", "CONTENT_TYPE", "GATEWAY_INTERFACE", "PATH_INFO",
	"PATH_TRANSLATED", "QUERY_STRING", "REMOTE_ADDR", "REMOTE_IDENT", "REMOTE_USER",
	"REQUEST_METHOD", "REQUEST_URI", "SCRIPT_NAME", "SERVER_NAME", "SERVER_PORT",
	"SERVER_PROTOCOL", "SERVER_SOFTWARE",
};

const std::string	Client::m_state_to_string[State_Invalid] = {
	"State_Read_Request",
	"State_Choose_Server_Info",
	"State_Auth",
	"State_Read_Request_Body",
	"State_Write_File",
	"State_Read_File",
	"State_Launch_CGI",
	"State_Write_CGI",
	"State_Read_CGI_Headers",
	"State_Read_CGI_Body",
	"State_CGI_Select",
	"State_CGI_Checker",
	"State_CGI_Finish",
	"State_Response",
	"State_Keep_Connection",
	"State_Finish",
};

const std::string	Client::RequestBodyState::strings[Count] = {
	"Initial",
	"Read_Sized",
	"Read_Chunked_Header",
	"Read_Chunked_Body",
	"Read_Chunked_Trailing",
	"Finish",
};

Client::Client(int socket, time_t birth_time, Info info)
	: m_server_info(0)
	, m_location(0)
	, m_socket(socket)
	, m_time(birth_time)
	, m_state(State_Read_Request)
	, m_info(info)
	, m_debug_print(true)
	{}

Client::Client(const Client &client)
	: m_server_info(client.m_server_info)
	, m_location(client.m_location)
	, m_socket(client.m_socket)
	, m_time(client.m_time)
	, m_state(client.m_state)
	, m_cgi(client.m_cgi)
	, m_info(client.m_info)
	, m_debug_print(client.m_debug_print)
	{}

Client::~Client() {
}

extern bool g_print;

void	Client::free_resources() {
	if (g_print) std::cerr << "Client[" << m_socket << "] killed" << std::endl;
	if (m_socket >= 0) {
		close(m_socket);
	}
	if (m_cgi.read_fd >= 0) {
		close(m_cgi.read_fd);
	}
	if (m_cgi.write_fd >= 0) {
		close(m_cgi.write_fd);
	}
	if (m_cgi.pid >= 0) {
		kill (m_cgi.pid, SIGTERM);
		m_cgi.pid = -1;
	}
}

void	Client::do_work(bool is_read, bool is_write, time_t sec) {
	bool	should_continue = false;

	(void)is_read, (void)is_write;
	m_time = sec;
	do {
		should_continue = false;

		if (m_debug_print && g_print) std::cerr << "state[" << m_socket << "]: " << m_state_to_string[m_state] << std::endl;
		switch (m_state) {
			case State_Read_Request: {
				m_state = read_request();
				if (g_print) {
					std::string reqstr = m_request.to_string();
					std::cerr << "REQUEST[" << reqstr.size() << "] ===" << reqstr << "===" << std::endl;
				}
			} break ;
			case State_Auth: {
				std::string	username, password;

				if (get_auth_from_request(username, password)) {
					m_state = auth(username, password);
				} else {
					make_unauthorized_response();
					m_state = State_Response;
				}
			} break ;
			case State_Read_Request_Body: {
				m_state = read_request_body();
			} break ;
			case State_Read_File: {
				bool	should_continue = false;

				do {
					if (is_file_exists(m_read_path[m_read_path_index])) {
						// if (m_debug_print && g_print) std::cerr << "readfile(" << m_read_path[m_read_path_index] << ")" << std::endl;
						if (read_file (m_read_path[m_read_path_index], m_response_body)) {
							std::string &filename = m_read_path[m_read_path_index];
							ViewData	ext = Path(filename).get_extension();
							std::string mime_type;

							m_response.set_status_code(StatusCode::OK);
							m_response.add_header(new ContentLanguage("en-US"));
							m_response.add_header(new ContentLength(m_response_body.size()));
							m_response.add_header(new Date());
							m_response.add_header(new LastModified(filename));
							if (ext.size() > 0) {
								mime_type = m_server_info->getMimeTypes(ext.to_string());
							}
							if (mime_type.size() > 0) {
								m_response.add_header(new ContentType(mime_type));
							} else {
								m_response.add_header(new ContentType("text/plain"));
							}
							if (g_print) std::cerr << "filename: " << filename << " file extension: " << ext << " mime_type: " << mime_type << std::endl;
							m_state = State_Response;
						} else {
							m_state = State_Read_File;
						}
					} else {
						m_read_path_index += 1;
						should_continue = (m_read_path_index < m_read_path.size());
					}
				} while (should_continue);
				if (m_read_path_index >= m_read_path.size()) {
					make_errorpage_response(StatusCode::NotFound, "no file");
					m_state = State_Response;
				}
			} break;
			case State_Launch_CGI: {
				m_state = execute_cgi();
				if (m_cgi.ok) {
					m_response.enable();
					m_response.clear();
					m_response_state.disable_body = false;
					m_response_body.clear();
				}
			} break ;
			case State_CGI_Select: {
				if (is_write) {
					m_state = State_Write_CGI;
				} else if (is_read) {
					if (m_cgi.headers_done) {
						m_state = State_Read_CGI_Body;
					} else if (!m_cgi.body_done) {
						m_state = State_Read_CGI_Headers;
					} else {
						std::cerr << "ERRrrrrrrr" << std::endl;
					}
				}
				should_continue = true;
			} break ;
			case State_Write_CGI: {
				m_state = write_cgi();
			} break ;
			case State_Read_CGI_Headers: {
				m_state = read_cgi_headers();
			} break ;
			case State_Read_CGI_Body: {
				m_state = read_cgi_body();
			} break ;
			case State_CGI_Checker: {
				if (m_cgi.write_done && m_cgi.headers_done && m_cgi.body_done) {
					m_state = State_CGI_Finish;
				} else {
					m_state = State_CGI_Select;
				}
			} break ;
			case State_CGI_Finish: {
				if (!m_response.find_header("Content-Length")) {
					m_response.add_header(new ContentLength(m_response_body.size()));
				}
				if (!m_response.find_header("Content-Type")) {
					ViewData	extension = m_fs_script_path.get_extension();
					if (extension.size() > 0) {
						std::string	mime_type = m_server_info->getMimeTypes(extension.to_string());
						if (mime_type.size() > 0) {
							m_response.add_header(new ContentType(mime_type));
						}
					}
				}
				int		status_index = m_response.find_unrecognized_header("Status");
				if (status_index >= 0) {
					ViewData	view(m_response.get_unrecognized_header_field_value(status_index));
					BNF::ViewTree	tree = g_bnf.make_tree("Status", view);

					if (!tree.empty() && view.size() == 0) {
						long		code = tree.begin().get("status-code").value().to_long();
						StatusCode	status_code = StatusCode::from_int(code);

						if (status_code != StatusCode::Invalid) {
							m_response.set_status_code(status_code);
						} else {
							m_response.set_status_code(StatusCode::InternalServerError);
						}
					} else {
						m_response.set_status_code(StatusCode::InternalServerError);
					}
				} else {
					m_response.set_status_code(StatusCode::OK);
				}
				m_response.enable();
				m_response_state.disable_body = false;
				m_state = State_Response;
			} break ;
			case State_Write_File: {
				std::string fileName = m_read_path[0];
				// int f = 0;
				int fd;
				if ((fd = open(fileName.c_str(), O_RDONLY)) > 0)
					close(fd);

				Path	paths(fileName);
				Path	dirpath("");
				if (paths.size() > 1) {
					for (size_t index = 0; index < paths.size() - 1; index += 1) {
						//std::cout << "paths = " << paths[index] << "\n";

						dirpath.append_segments(paths[index]);
						mkdir(dirpath.to_string().c_str(), 0777);
					}
				}
				std::ofstream outf;
				outf.open(fileName);
				if (g_print) std::cout << "filename = " << fileName << "\n";
				if (outf.is_open()) {
					outf << m_request_body.rdata();
					m_response.enable();
					m_response.clear();
					if(fd < 0) 
						m_response.set_status_code(StatusCode::Created);
					else
						m_response.set_status_code(StatusCode::NoContent);
					m_response.add_header(new ContentLocation(fileName));
					m_response.add_header(new ServerHeader());
					outf.close();
				} 
				else {
					make_errorpage_response(StatusCode::BadRequest, "couldn't create resource");
				}
				m_state = State_Response;
			} break;
			case State_Response: {
				m_state = send_response();
				if (m_state != State_Response) {
					m_response_state = ResponseState();
					m_response.clear();
					m_response.enable();
				}
			} break ;
			case State_Keep_Connection: {
				if (m_cgi.read_fd >= 0) {
					close(m_cgi.read_fd);
					m_cgi.read_fd = -1;
				}
				if (m_cgi.write_fd >= 0) {
					close(m_cgi.write_fd);
					m_cgi.write_fd = -1;
				}
				if (m_cgi.pid >= 0) {
					kill(m_cgi.pid, SIGTERM);
					m_cgi.pid = -1;
				}
				m_cgi = CGIState();
				m_auth = Auth();
				m_response_state = ResponseState();
				m_request_body_state = RequestBodyState();
				m_line_buffer.clear();

				m_location_subtracted_path.clear();
				m_fs_root_path.clear();
				m_requested_resource_path.clear();
				m_fs_requested_resource_path.clear();
				m_fs_script_path.clear();
				m_script_name.clear();
				m_script_path_info.clear();
				m_script_path_translated.clear();

				m_response_state.disable_body = false;

				m_request.clear();
				m_request_body.clear();
				m_response.clear();
				m_response_body.clear();
				m_read_path.clear();
				m_read_path_index = 0;

				m_server_info = 0;
				m_location = 0;

				m_state = State_Read_Request;
			} break ;
			default: {
			} break ;
		}
	} while (bypass_select() || should_continue);
}

bool		Client::get_auth_from_request(std::string &username, std::string &password) const {
	bool	result = false;
	Header	*header;

	header = m_request.find_header("Authorization");
	if (header) {
		ViewData		view(static_cast<Authorization *>(header)->get_value());
		BNF::ViewTree	tree = g_bnf.make_tree("Authorization", view);
		BNF::ViewTree::Iter	it = tree.begin().get("basic-authorization");

		if (it) {
			ViewData	cred = it.get("basic-credentials").value();
			std::string	decoded = decode_base64_string(cred);
			int			until_colon = ViewData(decoded).count_chars_until(':');

			if (until_colon >= 0) {
				username = ViewData(decoded).truncate_to(until_colon).to_string();
				password = ViewData(decoded).move_pointer(until_colon + 1).to_string();
			} else {
				username = ViewData(decoded).to_string();
			}
			result = true;
		} else {
			std::cerr << "webserv: Auth From Request: invalid auth method from client" << std::endl;
		}
	}
	return (result);
}

std::string	Client::decode_base64_string(const ViewData &view_) {
	std::string	result;
	ViewData	view(view_);
	union {
		char		ch[3];
		struct {
			unsigned	val3:6;
			unsigned	val2:6;
			unsigned	val1:6;
			unsigned	val0:6;
		};
		unsigned	val;
	} window;

	while (view.size() > 0) {
		int		octets = 0;

		window.val = 0;
		while (octets < 4 && view.size() > 0) {
			unsigned	digit64 = 0;

			if (view[0] >= 'A' && view[0] <= 'Z') {
				digit64 = (view[0] - 'A') + 0;
			} else if (view[0] >= 'a' && view[0] <= 'z') {
				digit64 = (view[0] - 'a') + 26;
			} else if (view[0] >= '0' && view[0] <= '9') {
				digit64 = (view[0] - '0') + 52;
			} else if (view[0] == '+') {
				digit64 = 62;
			} else if (view[0] == '/') {
				digit64 = 63;
			} else {
				view.move_pointer(view.size());
			}
			switch (octets) {
				case 0: window.val0 = digit64; break ;
				case 1: window.val1 = digit64; break ;
				case 2: window.val2 = digit64; break ;
				case 3: window.val3 = digit64; break ;
			}
			view.move_pointer();
			octets += 1;
		}
		octets = 0;
		while (octets < 3 && window.ch[2 - octets] != 0) {
			result += window.ch[2 - octets];
			octets += 1;
		}
	}
	return (result);
}

Client::StateEnum	Client::auth(const ViewData &auth_username, const ViewData &auth_password) {
	StateEnum	state;

	Path authfile_path = m_fs_root_path;
	authfile_path.append_segments(m_location->getUserPassFile());
	authfile_path.reduce_dot_segments();
	authfile_path.set_opt_last_slash(false);
	std::string	path = authfile_path.to_string();
	int	fd = open(path.c_str(), O_RDONLY);
	if (fd >= 0) {
		char	buffer[1024];
		int		readed;
		std::string	file;

		file.reserve(get_file_size(path));
		while ((readed = read (fd, buffer, sizeof (buffer))) > 0) {
			file.insert(file.end(), buffer, buffer + readed);
		}
		close(fd);
		{
			ViewData	view(file);
			bool		found = false;
			size_t		index = 0;

			while (!found && view.size() > 0) {
				int			until_nl = view.count_chars_until('\n');
				until_nl = until_nl < 0 ? view.size() : until_nl;
				ViewData	lineview(view, until_nl);

				if (lineview.size() > 0) {
					int until_colon = lineview.count_chars_until(':');

					if (until_colon >= 0) {
						ViewData	username(lineview, until_colon);
						ViewData	password(ViewData(lineview).move_pointer(until_colon + 1));

						if (username.exact_equals(auth_username) && password.exact_equals(auth_password)) {
							found = true;
							break ;
						}
					}
				}
				index += 1;
				view.move_pointer(until_nl + 1);
			}
			if (found) {
				m_auth.type = Auth::Basic;
				m_auth.index = index;
				m_auth.username = auth_username.to_string();
				state = analyze_request();
			} else {
				std::cerr << "webserv: Auth: user not found |" << auth_username << ":" << auth_password << "|" << std::endl;
				make_unauthorized_response();
				state = State_Response;
			}
		}
	} else {
		if (is_file_exists(path)) {
			state = State_Auth;
		} else {
			std::cerr << "webserv: Auth: auth file not found" << std::endl;
			make_errorpage_response(StatusCode::InternalServerError, "Auth file not found");
			state = State_Response;
		}
	}
	return (state);
}

int		Client::select_read_fd() {
	int		fd = -1;

	switch (m_state) {
		case State_Read_Request_Body:
		case State_Read_Request: {
			fd = m_socket;
		} break ;
		case State_CGI_Select: {
			if (!m_cgi.headers_done || !m_cgi.body_done) {
				fd = m_cgi.read_fd;
			} else if (m_cgi.write_done) {
				m_state = State_Response;
			}
		} break ;
		case State_Read_CGI_Headers:
		case State_Read_CGI_Body: {
			std::cerr << "SOMETHING WRONG" << std::endl;
		} break ;
		default: {
			fd = -1;
		} break ;
	}
	return (fd);
}

int		Client::select_write_fd() {
	int		fd = -1;

	switch (m_state) {
		case State_CGI_Select: {
			if (!m_cgi.write_done) {
				fd = m_cgi.write_fd;
			} else if (m_cgi.headers_done && m_cgi.body_done) {
				m_state = State_Response;
				fd = m_socket;
			}
		} break ;
		case State_Write_CGI: {
			std::cerr << "SOMETHING WRONG" << std::endl;
		} break ;
		case State_Response: {
			fd = m_socket;
		} break ;
		default: {
			fd = -1;
		} break ;
	}
	return (fd);
}

bool	Client::bypass_select(StateEnum state) const {
	bool	result = false;

	if (state == State_Invalid) {
		state = m_state;
	}
	switch (state) {
		// case State_Choose_Server_Info:
		case State_Auth:
		case State_Launch_CGI:
		case State_Write_File:
		case State_CGI_Checker:
		case State_CGI_Finish:
		case State_Keep_Connection:
		case State_Read_File: {
			result = true;
		} break ;
		case State_Read_Request_Body: {
			if (m_request_body_state.remainer.size() >= m_request_body_state.size) {
				result = true;
			}
		}
		default: {
		} break ;
	}
	return (result);
}

bool	Client::kill_me() {
	return (m_state == State_Finish);
}

void	Client::check_time(time_t sec) {
	if (sec - m_time >= (m_location ? m_location->getTimeout() : 30)) {
		if (g_print) std::cerr << "Client[" << m_socket << "] timeout on " << m_state_to_string[m_state] << " state" << std::endl;
		if (m_state == State_Read_Request_Body) {
			if (g_print) std::cerr << "Skip State_Read_Request_Body to " << m_state_to_string[m_request_body_state.next_state] << std::endl;
			m_state = m_request_body_state.next_state;
		}
		m_time = sec;
	}
}

bool		Client::is_need_choose_server_info() const {
	return (m_state == State_Choose_Server_Info);
}

std::string	Client::get_host_header() const {
	Header	*header = m_request.find_header("Host");
	std::string	result;

	if (header) {
		result = header->construct_field_value();
	}
	return (result);
}

void		Client::set_server_info(const ServerInfo &info) {
	Path		location_path;
	ViewData	request_view(m_request.get_request_target());
	int			until_query = request_view.count_chars_until('?');
	Path		request_path(ViewData(request_view, until_query < 0 ? request_view.size() : until_query));

	m_server_info = &info;
	m_requested_resource_path = request_path;
	m_location = m_server_info->findLocation(request_path, location_path);
	if (m_debug_print && g_print) std::cerr << "location_path: " << location_path.to_string() << std::endl;
	if (m_debug_print && g_print) std::cerr << "request_path: " << request_path.to_string() << std::endl;
	m_location_subtracted_path = request_path.subtract_from(location_path);
	if (m_debug_print && g_print) std::cerr << "m_location_subtracted_path: " << m_location_subtracted_path.to_string() << std::endl;
	m_fs_root_path.construct(m_location->getRoot());
	m_fs_requested_resource_path = m_fs_root_path;
	m_fs_requested_resource_path.append_path(m_location_subtracted_path);
	if (m_debug_print && g_print) std::cerr << "is root location: " << (m_location == m_server_info->getRootLocation()) << std::endl;
	if (m_debug_print && g_print) std::cerr << "m_fs_requested_resource_path: " << m_fs_requested_resource_path.to_string() << std::endl;
	if (m_location->isAuthNeeded()) {
		m_state = State_Auth;
	} else {
		m_state = analyze_request();
	}
}

Client::StateEnum	Client::read_request() {
	int			readed = 0;
	char		buffer[64];
	bool		end_of_section = false;
	ViewData	view(buffer, 0);
	StatusCode	status_code;
	StateEnum	state;

	status_code = StatusCode::OK;
	while (!end_of_section && (readed = recv(m_socket, buffer, sizeof (buffer), 0)) > 0) {
		int	chars_count;

		m_line_buffer.append(buffer, readed);
		view = ViewData(m_line_buffer);
		chars_count = view.count_chars_until("\r\n");
		if (chars_count >= 0) {
			do {
				ViewData	iview(view, chars_count + 2);
				if (chars_count > 0) {
					if (m_request.get_method() == Method::Invalid) {
						if (!m_request.parse_start_line(iview)) {
							std::cerr << "webserv: ReadRequest: cannot parse start line [" << iview << "]" << std::endl;
							status_code = StatusCode::BadRequest;
							end_of_section = true;
						}
					} else {
						iview.truncate_to(view.get_position() + chars_count);
						if (!m_request.add_header(iview)) {
							std::cerr << "webserv: ReadRequest: cannot parse header [" << iview << "]" << std::endl;
							status_code = StatusCode::BadRequest;
							end_of_section = true;
						}
					}
				} else {
					end_of_section = true;
				}
				view.move_pointer(chars_count + 2);
			} while (!end_of_section && (chars_count = view.count_chars_until("\r\n")) >= 0);
			if (view.size() > 0) {
				m_line_buffer = view.to_string();
			} else {
				m_line_buffer.clear();
			}
		}
	}
	if (end_of_section) {
		if (status_code == StatusCode::OK) {
			state = State_Choose_Server_Info;
			m_request_body_state.remainer = m_line_buffer;
			m_line_buffer.clear();
			if (g_print && m_request_body_state.remainer.size() > 0) std::cerr << "REMAINER!!: " << m_request_body_state.remainer.size() << std::endl;
		} else {
			make_errorpage_response(status_code, "web server cannot parse request");
			state = State_Response;
		}
	} else {
		if (readed == 0) {
			state = State_Finish;
		} else {
			state = State_Read_Request;
		}
	}
	return (state);
}

Client::StateEnum	Client::read_request_body() {
	char				buffer[1024];
	RequestBodyState	&body_state = m_request_body_state;
	StateEnum			state = body_state.next_state;
	int					readed = 0;
	bool				should_continue;
	ViewData			chunked_header_remainer("");

	do {
		should_continue = false;
		if (m_debug_print && g_print) std::cerr << "read_request_body state: " << RequestBodyState::strings[body_state.state] << std::endl;
		switch (body_state.state) {
			case RequestBodyState::Initial: {
				if (body_state.is_chunked) {
					body_state.state = RequestBodyState::Read_Chunked_Header;
					should_continue = true;
				} else if (body_state.size > 0) {
					body_state.state = RequestBodyState::Read_Sized;
					should_continue = true;
				} else {
					make_errorpage_response(StatusCode::InternalServerError, "invalid request body state");
					state = State_Response;
				}
			} break ;
			case RequestBodyState::Read_Sized: {
				size_t	appended = 0;

				if (m_request_body_state.remainer.size() > 0) {
					readed = m_request_body_state.remainer.size();
					appended = std::min(m_request_body.size() + readed, body_state.size) - m_request_body.size();
					m_request_body.append(m_request_body_state.remainer);
					m_request_body_state.remainer.clear();
				}
				while (m_request_body.size() < body_state.size && (readed = recv(m_socket, buffer, sizeof (buffer), 0)) > 0) {
					appended = std::min(m_request_body.size() + readed, body_state.size) - m_request_body.size();
					m_request_body.append(ViewData(buffer, appended));
				}
				if (m_request_body.size() < body_state.size) {
					state = State_Read_Request_Body;
					if (g_print) std::cerr << "Read_Sized: select [" << m_request_body.size() << " < " << body_state.size << "] (" << readed << "; " << appended << ")" << std::endl;
				} else {
					if (g_print) std::cerr << "Read_Sized: End [" << m_request_body.size() << "]" << std::endl;
					if (static_cast<int>(appended) < readed) {
						m_request_body_state.remainer = ViewData(buffer, readed).subview_move(appended).to_string();
					}
				}
				if (readed == 0) {
					if (g_print) std::cerr << "early connection reset" << std::endl;
					make_errorpage_response(StatusCode::BadRequest, "connection reset while reading request body");
					state = State_Response;
				}
			} break ;
			case RequestBodyState::Read_Chunked_Header: {
				bool	should_exit = false;

				while (!should_exit) {
					readed = recv(m_socket, buffer, sizeof (buffer), 0);
					ViewData	view(buffer, readed < 0 ? 0 : readed);
					m_request_body_state.remainer += view.to_string();
					view = ViewData(m_request_body_state.remainer);
					if (view.size() > 0) {
						int		until_crlf = view.count_chars_until("\r\n");

						if (until_crlf >= 0) {
							ViewData	iview(view, until_crlf + 2);
							BNF::ViewTree	tree = g_bnf.make_tree("chunk-header", iview);
							if (!tree.empty() && iview.size() == 0) {
								body_state.size = tree.begin().get("chunk-size").value().to_long(16);
								view.move_pointer(until_crlf + 2);
								if (body_state.size > 0) {
									body_state.state = RequestBodyState::Read_Chunked_Body;
									body_state.start_size = m_request_body.size();
								} else {
									if (!view.partial_equals("\r\n")) {
										body_state.state = RequestBodyState::Read_Chunked_Trailing;
										should_continue = true;
										if (g_print) std::cerr << "viewsize: " << view.size() << " view: |" << view << "|" << std::endl;
									} else {
										view.move_pointer(2);
										body_state.state = RequestBodyState::Finish;
										if (m_request_body.size() > m_location->getMaxBodySize()) {
											make_errorpage_response(StatusCode::PayloadTooLarge, "chunked body too large");
											state = State_Response;
										}
									}
								}
							} else {
								make_errorpage_response(StatusCode::BadRequest, "invalid chunk header format");
								state = State_Response;
							}
						} else {
							state = State_Read_Request_Body;
						}
					}
					if (readed <= 0 || body_state.state != RequestBodyState::Read_Chunked_Header || state == State_Response) {
						should_exit = true;
						if (readed < 0 && body_state.state == RequestBodyState::Read_Chunked_Header) {
							state = State_Read_Request_Body;
						}
						if (body_state.state != RequestBodyState::Read_Chunked_Header) {
							should_continue = true;
							if (view.size() > 0) {
								m_request_body_state.remainer = view.to_string();
							} else {
								m_request_body_state.remainer.clear();
							}
						}
						if (readed == 0 && state == State_Read_Request_Body) {
							make_errorpage_response(StatusCode::BadRequest, "invalid chunk header format (CRLF not found)");
							state = State_Response;
						}
					}
				}
			} break ;
			case RequestBodyState::Read_Chunked_Body: {
				size_t	start_size = body_state.start_size;
				size_t	current_size = m_request_body.size() - start_size;
				size_t	appended = 0;
				if (current_size < body_state.size && m_request_body_state.remainer.size() > 0) {
					appended = std::min(current_size + m_request_body_state.remainer.size(), body_state.size) - current_size;
					ViewData	remainer_view(ViewData(m_request_body_state.remainer).truncate_to(appended));
					m_request_body.append(remainer_view);
					current_size = m_request_body.size() - start_size;
					if (remainer_view.size() < m_request_body_state.remainer.size()) {
						m_request_body_state.remainer = ViewData(m_request_body_state.remainer).move_pointer(remainer_view.size()).to_string();
					} else {
						m_request_body_state.remainer.clear();
					}
				}
				if (current_size < body_state.size) {
					appended = 0;
					while (current_size < body_state.size && (readed = recv(m_socket, buffer, sizeof (buffer), 0)) > 0) {
						appended = std::min(current_size + readed, body_state.size) - current_size;
						m_request_body.append(ViewData(buffer, appended));
						current_size = m_request_body.size() - start_size;
					}
					if (current_size < body_state.size) {
						state = State_Read_Request_Body;
					} else {
						if (readed > static_cast<int>(appended)) {
							m_request_body_state.remainer = ViewData(buffer + appended, readed - appended).to_string();
						}
					}
				}
				if (state != State_Read_Request_Body) {
					bool	should_exit = false;

					while (!should_exit) {
						ViewData	view(m_request_body_state.remainer);

						should_exit = true;
						if (view.size() >= 2) {
							if (view.partial_equals("\r\n")) {
								view.move_pointer(2);
								if (view.size() > 0) {
									m_request_body_state.remainer = view.to_string();
								} else {
									m_request_body_state.remainer.clear();
								}
								body_state.state = RequestBodyState::Read_Chunked_Header;
								should_continue = true;
							} else {
								make_errorpage_response(StatusCode::BadRequest, "invalid chunk ending");
								state = State_Response;
							}
						} else {
							readed = recv(m_socket, buffer, sizeof (buffer), 0);
							if (readed > 0) {
								m_request_body_state.remainer += std::string(buffer, readed);
								should_exit = false;
							} else if (readed < 0) {
								state = State_Read_Request_Body;
							} else {
								make_errorpage_response(StatusCode::BadRequest, "unexpected end of stream");
								state = State_Response;
							}
						}
					}
				}
			} break ;
			case RequestBodyState::Read_Chunked_Trailing: {
				bool	should_exit = false;

				while (!should_exit) {
					ViewData	view(m_request_body_state.remainer);

					if (view.size() > 0) {
						int		until_crlf = view.count_chars_until("\r\n");

						if (until_crlf > 0) {
							ViewData	iview(view, until_crlf);

							if (!m_request.add_header(iview)) {
								make_errorpage_response(StatusCode::BadRequest, "invalid header in chunked body trailing part");
								state = State_Response;
								break ;
							}
							view.move_pointer(until_crlf);
							if (view.size() > 0) {
								m_request_body_state.remainer = view.to_string();
							} else {
								m_request_body_state.remainer.clear();
							}
						} else if (until_crlf == 0) {
							m_request_body_state.remainer = view.move_pointer(2).to_string();
							should_exit = true;
							if (m_request_body.size() > m_location->getMaxBodySize()) {
								make_errorpage_response(StatusCode::PayloadTooLarge, "chunked body too large");
								state = State_Response;
							}
						}
					}
					if (!should_exit) {
						readed = recv(m_socket, buffer, sizeof (buffer), 0);
						if (readed > 0) {
							m_request_body_state.remainer += std::string(buffer, readed);
						} else if (readed < 0) {
							state = State_Read_Request_Body;
							should_exit = true;
						} else {
							make_errorpage_response(StatusCode::BadRequest, "invalid chunked trailing part");
							state = State_Response;
							should_exit = true;
						}
					}
				}
			} break ;
			default: {
			} break ;
		}
	} while (should_continue);

	return (state);
}

Client::StateEnum	Client::analyze_request() {
	StateEnum	state;
	StatusCode	redirect_code = StatusCode::from_int(m_location->getReturnCode());

	if (m_request.get_method() == Method::Invalid) {
		make_method_not_allowed_response();
		state = State_Response;
	} else if (redirect_code != StatusCode::Invalid) {
		make_redirect_response(redirect_code, m_location->getReturnUri());
		state = State_Response;
	} else if (!m_location->getMethodSet().consist(m_request.get_method()) && !(m_location->hasCGIServ() && m_location->getCGIMethodSet().consist(m_request.get_method()))) {
		if (m_location->getDefaultMethodBody(m_request.get_method()).ok) {
			make_default_method_body_response(m_request.get_method());
		} else {
			make_method_not_allowed_response();
			if (m_request.get_method() == Method::POST || m_request.get_method() == Method::HEAD) {
				m_response_state.disable_body = true;
			}
		}
		state = State_Response;
	} else switch (m_request.get_method()) {
		case Method::HEAD:  {
			m_response_state.disable_body = true;
		} /* go through */
		case Method::GET: {
			m_read_path_index = 0;
			if (m_location->hasCGIServ() && is_script_path(m_fs_requested_resource_path)) {
				m_cgi.binary_path = m_location->getCGIserver();
				if (g_print) std::cerr << "cgi path: " << m_cgi.binary_path << std::endl;
				if (make_script_path()) {
					if (g_print) std::cerr << "script paths: " << m_fs_script_path << " " << m_script_path_info << " " << m_script_path_translated << std::endl;
					state = State_Launch_CGI;
				} else {
					if (m_location->getDefaultMethodBody(Method::GET).ok) {
						make_default_method_body_response(Method::GET);
					} else {
						make_errorpage_response(StatusCode::NotFound, "no script file");
					}
					state = State_Response;
				}
			} else {
				state = State_Read_File;
				if (!is_file_exists(m_fs_requested_resource_path.to_string())) {
					if (is_directory(m_fs_requested_resource_path.to_string())) {
						for (size_t i = 0; i < m_location->getIndexFilesCount(); i += 1) {
							Path	path = m_fs_requested_resource_path;

							path.append_segments(m_location->getIndexFileName(i));
							path.reduce_dot_segments();
							if (state == State_Launch_CGI && !path.get_extension().exact_equals(m_location->getCGIextension())) {
								continue ;
							}
							path.set_opt_last_slash(false);
							m_read_path.push_back(path.to_string());
						}
						if (m_read_path.size() <= 0) {
							if (m_location->getDefaultMethodBody(Method::GET).ok) {
								make_default_method_body_response(Method::GET);
							} else {
								make_errorpage_response(StatusCode::NotFound, "no index file");
							}
							state = State_Response;
						}
					} else {
						make_errorpage_response(StatusCode::NotFound);
						state = State_Response;
					}
				} else {
					m_fs_requested_resource_path.set_opt_last_slash(false);
					m_read_path.push_back(m_fs_requested_resource_path.to_string());
				}
			}
		} break ;
		case Method::PUT: {
			Header	*header;

			header = m_request.find_header("Content-Length");
			if (header && static_cast<ContentLength *>(header)->getLength() > m_location->getMaxBodySize()) {
				std::ostringstream	text;

				text << "web server limits payload of uploaded files to " << m_location->getMaxBodySize() << " bytes";
				make_errorpage_response(StatusCode::PayloadTooLarge, text.str());
				state = State_Response;
			} else if (make_request_body_state()) {
				state = make_continue(State_Read_Request_Body);
				m_request_body_state.next_state = State_Write_File;
				if (m_location_subtracted_path.size() <= 0) {
					for (size_t i = 0; i < m_location->getIndexFilesCount(); i += 1) {
						m_read_path.push_back(m_location->getIndexFileName(i));
					}
					if (m_read_path.size() <= 0) {
						make_errorpage_response(StatusCode::NotFound, "no index file");
						state = State_Response;
					}
				} else {
					m_read_path.push_back(m_fs_requested_resource_path.to_string());
				}
			} else {
				make_errorpage_response(StatusCode::BadRequest, "cannot determine request body state");
				state = State_Response;
			}
		} break ;
		case Method::DELETE: {
			struct stat	statbuf;
			std::string	filename = m_fs_requested_resource_path.to_string();

			if (stat (filename.c_str(), &statbuf) == 0) {
				if (S_ISDIR(statbuf.st_mode)) {
					make_errorpage_response(StatusCode::NotFound, "file is directory");
				} else {
					unlink(filename.c_str());
					m_response.enable();
					m_response.clear();
					m_response.set_status_code(StatusCode::NoContent);
				}
			} else {
				make_errorpage_response(StatusCode::NotFound, "file not found");
			}
			state = State_Response;
		} break ;
		case Method::POST: {
			if (m_location->hasCGIServ()) {
				Header	*header;

				header = m_request.find_header("Content-Length");
				if (header && static_cast<ContentLength *>(header)->getLength() > m_location->getMaxBodySize()) {
					std::ostringstream	text;

					text << "web server limits payload of uploaded files to " << m_location->getMaxBodySize() << " bytes";
					make_errorpage_response(StatusCode::PayloadTooLarge, text.str());
					state = State_Response;
				} else if (make_request_body_state()) {
					if (make_script_path()) {
						m_request_body_state.next_state = State_Launch_CGI;
						state = make_continue(State_Read_Request_Body);
						m_cgi.binary_path = m_location->getCGIserver();
					} else {
						if (m_location->getDefaultMethodBody(Method::POST).ok) {
							make_default_method_body_response(Method::POST);
							m_request_body_state.next_state = State_Response;
							state = make_continue(State_Read_Request_Body);
						} else {
							make_errorpage_response(StatusCode::MethodNotAllowed, "no script file");
							state = State_Response;
						}
					}
				} else {
					make_errorpage_response(StatusCode::BadRequest, "cannot determine request body state");
					state = State_Response;
				}
			} else if (m_location->getDefaultMethodBody(Method::POST).ok) {
				make_default_method_body_response(Method::POST);
				state = State_Response;
			} else {
				make_errorpage_response(StatusCode::MethodNotAllowed, "web server does not support POST without CGI route");
				state = State_Response;
			}
		} break ;
		case Method::Invalid: {
			make_errorpage_response(StatusCode::MethodNotAllowed, "method not allowed");
			state = State_Response;
		} break ;
	}
	return (state);
}

bool	Client::make_request_body_state() {
	Header	*header;

	m_request_body_state.state = RequestBodyState::Initial;
	if (m_request_body_state.state == RequestBodyState::Initial) {
		header = m_request.find_header("Content-Length");
		if (header) {
			m_request_body_state.state = RequestBodyState::Read_Sized;
			m_request_body_state.size = static_cast<ContentLength *>(header)->getLength();
		}
	}
	if (m_request_body_state.state == RequestBodyState::Initial) {
		header = m_request.find_header("Transfer-Encoding");
		if (header) {
			TransferEncoding	*encoding = static_cast<TransferEncoding *>(header);
			if (encoding->count_states() == 1 && encoding->get_state(0).exact_caseins_equals("chunked")) {
				m_request_body_state.state = RequestBodyState::Read_Chunked_Header;
				m_request_body_state.is_chunked = true;
			}
		}
	}
	return (m_request_body_state.state != RequestBodyState::Initial);
}

void	Client::make_autoindex_response() {
	std::ostringstream	text;
	DIR					*dir;

	dir = opendir(m_fs_requested_resource_path.to_string().c_str());
	if (dir) {
		struct dirent	*ent;

		m_response.enable();
		m_response.clear();
		m_response_state.disable_body = false;
		m_response_body.clear();
		m_response.set_status_code(StatusCode::OK);

		text << "<html><head><title>Index " << m_request.get_request_target() << "</title></head><body>" << std::endl;
		text << "<h1>Index: </h1>" << std::endl;
		text << "<ul>" << std::endl;
		while ((ent = readdir(dir))) {
			Path	path(m_request.get_request_target());

			if (ent->d_name[0] == '.' && ent->d_name[1] == 0) {
			} else if (ent->d_name[0] == '.' && ent->d_name[1] == '.' && ent->d_name[2] == 0) {
				path.pop_back();
			} else {
				path.append_segments(ent->d_name);
			}
			text << "<li><a href=\"" << path.to_string() << "\">" << ent->d_name << "</a></li>" << std::endl;
		}
		closedir(dir);
		dir = 0;
		text << "</ul></body></html>" << std::endl;
		m_response_body.append(text.str());
	} else {
		make_errorpage_response(StatusCode::NotFound);
	}
}

Client::StateEnum	Client::send_response() {
	StateEnum	state = State_Response;
	// char		buffer[64];

	// while (recv(m_socket, buffer, sizeof (buffer), 0) > 0)
		// ;
	if (m_response.is_enabled()) {
		if (!m_response_state.is_headers_sended) {
			if (m_location && m_location->getAutoindex() && m_response.get_status_code() == StatusCode::NotFound) {
				struct stat	statbuf;

				if (stat(m_fs_requested_resource_path.to_string().c_str(), &statbuf) == 0) {
					if (S_ISDIR(statbuf.st_mode)) {
						make_autoindex_response();
					}
				}
			}
			if (m_response_state.header_check) {
				if (!m_response.find_header("Date")) {
					m_response.add_header(new Date());
				}
				if (m_response_state.disable_body) {
					m_response.remove_header("Content-Length");
					m_response.remove_header("Content-Type");
					m_response.add_header(new ContentLength(0));
				} else {
					if (!m_response.find_header("Content-Length")) {
						m_response.add_header(new ContentLength(m_response_body.size()));
					}
				}
			}
			if (!m_response_state.disable_body && (m_response.get_status_code() == StatusCode::BadRequest || m_response.get_status_code() == StatusCode::InternalServerError)) {
				if (m_debug_print && g_print) {
					std::cerr << "RESPONSE BODY ===" << std::endl << m_response_body.rdata() << std::endl << "===" << std::endl;
				}
			}

			std::string headers = m_response.to_string();
			int		sended = 0;

			if (m_debug_print && g_print) {
				std::cerr << "RESPONSE ===" << std::endl << headers << "===" << std::endl;
			}

			if ((sended = send(m_socket, headers.c_str(), headers.size(), 0)) < 0) {
				state = State_Finish;
				perror("webserv: Send Response");
			} else {
				if (sended < static_cast<int>(headers.size())) {
					m_response_state.remainer = std::string(headers, sended);
				} else {
					m_response_state.remainer.clear();
					if (m_response_state.disable_body) {
						state = m_response_state.next_state;
					}
				}
			}
			m_response_state.is_headers_sended = true;
		} else if (m_response_state.remainer.size() > 0) {
			int		sended;
			if ((sended = send(m_socket, m_response_state.remainer.c_str(), m_response_state.remainer.size(), 0)) < 0) {
				state = State_Finish;
				perror("webserv: Send Response");
			} else {
				if (sended < static_cast<int>(m_response_state.remainer.size())) {
					m_response_state.remainer = std::string(m_response_state.remainer, sended);
				} else {
					m_response_state.remainer.clear();
					if (m_response_state.disable_body) {
						state = m_response_state.next_state;
					}
				}
			}
		} else if (!m_response_state.disable_body && m_response_state.body_sended < m_response_body.size()) {
			int		sended;
			size_t	start_body_sended = m_response_state.body_sended;

			while (m_response_state.body_sended < m_response_body.size() && (sended = send(m_socket, m_response_body.data() + m_response_state.body_sended, m_response_body.size() - m_response_state.body_sended, 0)) > 0) {
				m_response_state.body_sended += sended;
			}
			if (sended < 0 && m_response_state.body_sended - start_body_sended <= 0) {
				state = State_Finish;
				std::cerr << "webserv: Send Response: connection reset" << std::endl;
			} else {
				if (m_response_state.body_sended >= m_response_body.size()) {
					state = m_response_state.next_state;
					if (m_response.get_status_code() != StatusCode::OK) {
						if (m_debug_print && g_print) {
							std::cerr << "RESPONSE BODY[" << m_response_body.size() << "] ===" << std::endl << m_response_body << std::endl << "===" << std::endl;
						}
					}
				} else if (sended == 0) {
					state = m_response_state.next_state;
				}
			}
		} else {
			if (m_debug_print && g_print) std::cerr << "webserv: Send Response: no route" << std::endl;
			state = m_response_state.next_state;
		}
	} else {
		std::ostringstream	text;

		make_errorpage_response(StatusCode::InternalServerError, "something goes wrong when sending response");
		text << m_response.to_string();
		text << m_response_body;
		std::string	str = text.str(); /* todo: optimize */ //TODO
		if (send(m_socket, str.c_str(), str.size(), 0) < 0) {
			perror("webserv: send");
		}
		state = m_response_state.next_state;
	}
	if (m_debug_print && g_print) std::cerr << "Send Response: Next State " << m_state_to_string[state] << std::endl;
	return (state);
}

bool	Client::read_file(const ViewData &filename, MessageBody &output) {
	char	buffer[1024];
	int		readed;
	int		fd;
	bool	result = false;

	fd = open(filename.to_string().c_str(), O_RDONLY);
	if (fd >= 0) {
		while ((readed = read(fd, buffer, sizeof (buffer))) > 0) {
			output.append(ViewData(buffer, readed));
		}
		close(fd);
		result = true;
	}
	return (result);
}

void	Client::make_errorpage_response(StatusCode code, const std::string &msg) {
	(void)code, (void)msg;
	m_response_state.disable_body = false;
	m_response_body.clear();
	if (m_location) {
		m_response_body.append(m_location->getErrorPage(code, msg));
	} else {
		m_response_body.append(Location::createErrorHTML(code, msg));
	}
	m_response.clear();
	m_response.enable();
	m_response.set_status_code(code);
	m_response.add_header(new ServerHeader());
	m_response.add_header(new ContentLength(m_response_body.size()));
	m_response.add_header(new ContentType("text/html"));
	m_response_state = ResponseState();
}

void	Client::make_unauthorized_response() {
	m_response.clear();
	m_response.enable();
	m_response.set_status_code(StatusCode::Unauthorized);
	m_response.add_header(new WWWAuthenticate(m_location->getRealm()));
	m_response_state.disable_body = true;
	m_response_state = ResponseState();
}

void	Client::make_redirect_response(StatusCode status_code, const std::string &uri) {
	if (status_code != StatusCode::Invalid) {
		m_response.clear();
		m_response.enable();
		m_response_state.disable_body = true;
		m_response.set_status_code(status_code);
		m_response.add_header(new LocationHeader(uri));
		m_response_state = ResponseState();
	} else {
		make_errorpage_response(StatusCode::InternalServerError, "invalid redirect status code");
	}
}

void	Client::make_default_method_body_response(Method method) {
	const Location::MethodBody	&method_body = m_location->getDefaultMethodBody(method);

	if (method_body.ok) {
		m_response.clear();
		m_response.enable();
		m_response.set_status_code(StatusCode::OK);
		m_response.add_header(new ContentLength(method_body.body.size()));
		m_response.add_header(new ContentType("text/plain"));
		m_response_state.disable_body = false;
		m_response_body.clear();
		m_response_body.append(method_body.body);
		m_response_state = ResponseState();
	} else {
		make_errorpage_response(StatusCode::InternalServerError, "invalid default method body");
	}
}

void	Client::make_method_not_allowed_response() {
	make_errorpage_response(StatusCode::MethodNotAllowed);
	if (m_location) {
		const Method::Set	&set = m_location->getMethodSet();
		const Method::Set	&cgi_set = m_location->getCGIMethodSet();
		std::ostringstream	text;
		bool				empty = true;

		for (size_t index = 0; index < Method::Count; index += 1) {
			if (set.consist(index) || cgi_set.consist(index)) {
				if (!empty) {
					text << ", ";
				}
				text << Method(index).to_string();
				empty = false;
			}
		}
		m_response.add_header(new Allow(text.str()));
	}
}

Client::StateEnum	Client::make_continue(StateEnum next_state) {
	StateEnum	state = next_state;

	if (m_request.find_header("Expect")) {
		m_response_state.disable_body = true;
		m_response.clear();
		m_response.enable();
		m_response.set_status_code(StatusCode::Continue);
		m_response_state = ResponseState();
		m_response_state.next_state = next_state;
		m_response_state.header_check = false;
		state = State_Response;
	}
	return (state);
}

bool	Client::is_file_exists(const std::string &path) {
	struct stat	info;
	bool		result = true;

	if (stat(path.c_str(), &info) != 0) {
		result = false;
	} else {
		result = !S_ISDIR(info.st_mode);
	}
	return (result);
}

bool	Client::is_directory(const std::string &path) {
	struct stat	info;
	bool		result = false;

	if (stat(path.c_str(), &info) == 0) {
		result = S_ISDIR(info.st_mode);
	}
	return (result);
}

size_t	Client::get_file_size(const std::string &path) {
	size_t	file_size = 0;
	struct stat	info;

	if (stat(path.c_str(), &info) == 0) {
		file_size = info.st_size;
	}
	return (file_size);
}

bool		Client::is_script_path(const Path &path) {
	bool	result = false;

	if (m_location->hasCGIServ()) for (size_t index = 0; index < path.size(); index += 1) {
		ViewData	view = path[index];
		ViewData	ext = view.subview_move(view.count_chars_until_last('.'));

		ext.move_pointer();
		if (ext.exact_equals(m_location->getCGIextension())) {
			result = true;
			break ;
		}
	}
	return (result);
}

Client::StateEnum	Client::execute_cgi() {
	StateEnum		state = State_Launch_CGI;
	std::string		vars[Location::MAXIMALS];
	std::string		*request_vars = new std::string[m_request.headers_count()];
	std::string		*request_unrecg_vars = new std::string[m_request.unrecognized_headers_count()];
	std::string		*script_filename = new std::string;
	char			**env = new char *[Location::MAXIMALS + m_request.headers_count() + m_request.unrecognized_headers_count() + 3];
	// int				result = -1;
	int				pipe_in[2];
	int				pipe_out[2];

	if (pipe(pipe_in) >= 0) {
		if (pipe(pipe_out) >= 0) {
			size_t env_i = 1;
			env[0] = const_cast<char *>("REDIRECT_STATUS=");
			for (size_t i = 0; i < Location::MAXIMALS; i += 1, env_i += 1) {
				vars[i] += CgiParam::strings[i] + "=" + make_cgi_parameter_value(static_cast<Location::cgi_params>(i));
				if (g_print) std::cerr << "Param[" << i << "]: " << vars[i] << std::endl;
				env[env_i] = const_cast<char *>(vars[i].c_str());
			}
			for (size_t i = 0; i < m_request.headers_count(); i += 1) {
				const std::string	&field_name = m_request.get_header(i)->get_field_name();
				if (ViewData(field_name).exact_caseins_equals("Content-Length") || ViewData(field_name).exact_caseins_equals("Transfer-Encoding") || ViewData(field_name).exact_caseins_equals("Content-Type")) {
					continue ;
				}
				request_vars[i] = "HTTP_" + field_name_to_cgi_param_format(field_name) + "=" + m_request.get_header(i)->construct_field_value();
				if (g_print) std::cerr << "request_vars[" << i << "]: " << request_vars[i] << std::endl;
				env[env_i] = const_cast<char *>(request_vars[i].c_str());
				env_i += 1;
			}
			for (size_t i = 0; i < m_request.unrecognized_headers_count(); i += 1, env_i += 1) {
				request_unrecg_vars[i] = "HTTP_" + field_name_to_cgi_param_format(m_request.get_unrecognized_header_field_name(i).to_string()) + "=" + m_request.get_unrecognized_header_field_value(i).to_string();
				if (g_print) std::cerr << "request_unrecg_vars[" << i << "]: " << request_unrecg_vars[i] << std::endl;
				env[env_i] = const_cast<char *>(request_unrecg_vars[i].c_str());
			}
			script_filename[0] = "SCRIPT_FILENAME=" + m_fs_script_path.to_string();
			env[env_i++] = const_cast<char *>(script_filename->c_str());
			if (g_print) std::cerr << script_filename[0] << std::endl;
			env[env_i] = 0;
			if (0 == (m_cgi.pid = fork())) {
				std::string	script_filename = m_fs_script_path.to_string();
				char	* const args[2] = { const_cast<char *>(script_filename.c_str()), 0 };

				close(pipe_in[1]);
				close(pipe_out[0]);
				if (dup2(pipe_in[0], 0) < 0) {
					std::cerr << "CANNOT DUPLICATE PIPE_IN[0] TO 0" << std::endl;
				}
				if (dup2(pipe_out[1], 1) < 0) {
					std::cerr << "CANNOT DUPLICATE PIPE_OUT[1] TO 1" << std::endl;
				}
				if (g_print) std::cerr << "ExECUTE: " << m_cgi.binary_path << std::endl;
				execve(m_cgi.binary_path.c_str(), args, env);
				perror("webserv: CGI");
				if (g_print) std::cerr << "webserv: CGI: cannot launch CGI script (bin: " << m_cgi.binary_path << "; script: " << m_fs_script_path.to_string() << ")" << std::endl;
				exit(5);
			}
			close(pipe_in[0]);
			close(pipe_out[1]);
			if (m_cgi.pid < 0) {
				perror("webserv: CGI");
				close(pipe_in[1]);
				close(pipe_out[0]);
			} else {
				m_line_buffer.clear();
				m_cgi.remainer.clear();
				if (m_request_body.size() > 0) {
					if (g_print) std::cerr << "REQUEST BODY SIZE " <<  m_request_body.size() << std::endl;
					if (fcntl(pipe_in[1], F_SETFL, O_NONBLOCK) < 0) {
						perror("webserv: CGI");
						make_errorpage_response(StatusCode::InternalServerError, "cannot make cgi input pipe async");
						state = State_Response;
						m_cgi.ok = false;
					} else {
						m_cgi.write_fd = pipe_in[1];
						state = State_CGI_Select;
					}
				} else {
					close(pipe_in[1]);
					m_cgi.write_done = true;
					state = State_CGI_Select;
				}
				if (fcntl(pipe_out[0], F_SETFL, O_NONBLOCK) < 0) {
					perror("webserv: CGI");
					make_errorpage_response(StatusCode::InternalServerError, "cannot make cgi output pipe async");
					state = State_Response;
					m_cgi.ok = false;
				} else {
					m_cgi.read_fd = pipe_out[0];
				}
			}
		} else {
			close(pipe_in[0]);
			close(pipe_in[1]);
		}
	}
	delete[] env;
	delete[] request_vars;
	delete[] request_unrecg_vars;
	delete script_filename;
	return (state);
}

Client::StateEnum	Client::write_cgi() {
	StateEnum	state = State_CGI_Checker;
	int			written = -1;

	if (g_print) std::cerr << "START CGI WRITE" << std::endl;
	while (m_cgi.written < m_request_body.size() && (written = write(m_cgi.write_fd, m_request_body.data() + m_cgi.written, m_request_body.size() - m_cgi.written)) > 0) {
		m_cgi.written += written;
	}
	if (g_print) std::cerr << "END CGI WRITE" << std::endl;
	if (m_cgi.written >= m_request_body.size()) {
		close(m_cgi.write_fd);
		m_cgi.write_fd = -1;
		m_cgi.write_done = true;
	} else if (written == 0) {
		make_errorpage_response(StatusCode::InternalServerError, "CGI write interrupt");
		state = State_Response;
		m_cgi.ok = false;
		close(m_cgi.write_fd);
		m_cgi.write_fd = -1;
	}
	if (g_print) std::cerr << "END WRITE " << m_cgi.write_fd << " Next State " << m_state_to_string[state] << " all_written: " << m_cgi.written << " written: " << written << std::endl;
	return (state);
}

Client::StateEnum	Client::read_cgi_headers() {
	StateEnum	state = State_CGI_Checker;
	int			readed;
	bool		should_exit = false;

	while (!should_exit) {
		ViewData	view(m_line_buffer);
		view.move_pointer(m_cgi.readed);
		int			until_crlf = view.count_chars_until("\r\n");

		while (!should_exit && view.size() > 0 && until_crlf >= 0) {
			if (until_crlf > 0) {
				if (!m_response.add_header(view.subview_trunc(until_crlf))) {
					std::cerr << "webserv: CGI: invalid CGI header: " << view.subview_trunc(until_crlf) << std::endl;
				}
				m_cgi.readed += until_crlf + 2;
				view = ViewData(m_line_buffer).move_pointer(m_cgi.readed);
				until_crlf = view.count_chars_until("\r\n");
			} else if (until_crlf == 0) {
				m_cgi.readed += 2;
				m_cgi.remainer = std::string(m_line_buffer, m_cgi.readed);
				should_exit = true;
				m_cgi.headers_done = true;
			}
		}
		if (!should_exit) {
			m_line_buffer.resize(m_line_buffer.size() + 128);
			readed = read(m_cgi.read_fd, const_cast<char *>(m_line_buffer.data() + (m_line_buffer.size() - 128)), 128);
			if (readed > 0) {
				if (readed < 128) {
					m_line_buffer.resize(m_line_buffer.size() - (128 - readed));
				}
				if (g_print) std::cerr << "READED: " << m_line_buffer.size() << std::endl;
			} else if (readed < 0) {
				m_line_buffer.resize(m_line_buffer.size() - 128);
				should_exit = true;
			} else {
				if (g_print) std::cerr << "cgi end of stream |" << m_line_buffer << "|" << std::endl;
				make_errorpage_response(StatusCode::InternalServerError, "invalid CGI headers");
				state = State_Response;
				m_cgi.ok = false;
				should_exit = true;
			}
		}
	}
	return (state);
}

Client::StateEnum	Client::read_cgi_body() {
	StateEnum	state = State_CGI_Checker;
	int			readed;
	char		buffer[1024];

	if (m_cgi.remainer.size() > 0) {
		m_response_body.append(m_cgi.remainer);
		m_cgi.remainer.clear();
	}
	if (g_print) std::cerr << "START CGI READ" << std::endl;
	while ((readed = read (m_cgi.read_fd, buffer, sizeof (buffer))) > 0) {
		m_response_body.append(ViewData(buffer, readed));
	}
	if (g_print) std::cerr << "END CGI READ bodysize: " << m_response_body.size() << std::endl;
	if (readed < 0) {
		if (g_print) std::cerr << "CGI READ SELECT pid[" << m_cgi.pid << "]" << std::endl;
	} else {
		if (g_print) std::cerr << "CGI READ END size[" << m_response_body.size() << "]" << std::endl;
		m_cgi.body_done = true;
		close(m_cgi.read_fd);
		m_cgi.read_fd = -1;
	}
	return (state);
}

std::string	Client::field_name_to_cgi_param_format(const std::string &str) {
	std::ostringstream	text;

	for (size_t i = 0; i < str.size(); i += 1) {
		if (std::isalpha(str[i])) {
			text << (char) std::toupper(str[i]);
		} else if (str[i] == '-') {
			text << '_';
		} else {
			std::cerr << "disallowed symbol in header field name ('" << str[i] << "')" << std::endl;
		}
	}
	return text.str();
}

std::string	Client::make_cgi_parameter_value(Location::cgi_params param) {
	switch (param) {
		case Location::AUTH_TYPE: {
			if (m_auth.type == Auth::Basic) {
				return "Basic";
			} else if (m_auth.type == Auth::None) {
			} else {
				std::cerr << "webserv: CGI: Not implemented Auth type" << std::endl;
			}
		} break ;
		case Location::CONTENT_LENGTH: {
			Header	*header = m_request.find_header("Content-Length");
			if (header) {
				return static_cast<ContentLength *>(header)->construct_field_value();
			} else {
				std::ostringstream	text;

				text << m_request_body.size();
				return text.str();
			}
		} break ;
		case Location::CONTENT_TYPE: {
			Header	*header = m_request.find_header("Content-Type");
			if (header) {
				return static_cast<ContentType *>(header)->construct_field_value();
			}
		} break ;
		case Location::GATEWAY_INTERFACE: {
			return "CGI/1.1";
		} break ;
		case Location::PATH_INFO: {
			// return m_script_path_info.to_string();
			return m_requested_resource_path.to_string();
		} break ;
		case Location::PATH_TRANSLATED: {
			// return m_script_path_translated.to_string();
			return m_fs_script_path.to_string();
		} break ;
		case Location::QUERY_STRING: {
			return get_query_part(m_request.get_request_target()).to_string();
		} break ;
		case Location::REMOTE_ADDR: {
			return m_info.ip;
		} break ;
		case Location::REMOTE_IDENT: {
			/* todo: */
		} break ;
		case Location::REMOTE_USER: {
			return m_auth.username;
		} break ;
		case Location::REQUEST_METHOD: {
			return m_request.get_method().to_string();
		} break ;
		case Location::REQUEST_URI: {
			return m_request.get_request_target();
		} break ;
		case Location::SCRIPT_NAME: {
			return m_script_name.to_no_pct_string();
		} break ;
		case Location::SERVER_NAME: {
			if (m_server_info->getServerNamesCount() > 0) {
				Header	*header = m_request.find_header("Host");

				if (header) {
					return header->construct_field_value();
				}
			}
		} break ;
		case Location::SERVER_PORT: {
			std::ostringstream	text;

			text << m_server_info->getPort();
			return text.str();
		} break ;
		case Location::SERVER_PROTOCOL: {
			return "HTTP/1.1";
		} break ;
		case Location::SERVER_SOFTWARE: {
			return "webserv/1.0";
		} break ;
		default: {
			std::cerr << "webserv: CGI: Parameter is not implemented" << std::endl;
		};
	}
	return "";
}

bool		Client::make_script_path() {
	bool	result = false;

	if (m_fs_requested_resource_path.size() > 0) {
		Path	path = m_fs_requested_resource_path;
		size_t	count = path.size();

		for (; count > 0; count -= 1) {
			if (path.get_extension().exact_equals(m_location->getCGIextension())) {
				result = true;
				break ;
			} else {
				path.pop_back();
			}
		}
		if (count > 0 && result) {
			if (g_print) std::cerr << "path: " << path << std::endl;
			m_fs_script_path = path;
			if (g_print) std::cerr << "m_fs_script_path: " << m_fs_script_path << std::endl;
			if (m_fs_script_path.size() > 0) {
				m_script_name.append_segments(m_fs_script_path[m_fs_script_path.size() - 1]);
			}
			m_script_path_info = m_fs_requested_resource_path.subtract_from(m_fs_script_path);
			if (g_print) std::cerr << "m_fs_requested_resource_path: " << m_fs_requested_resource_path << std::endl;
			if (g_print) std::cerr << "m_script_path_info: " << m_script_path_info << std::endl;

			if (m_script_path_info.size() > 0) {
				Path	location_path;
				const Location	*location = m_server_info->findLocation(m_script_path_info, location_path);
				Path	subtracted_location = m_script_path_info.subtract_from(location_path);
				if (g_print) std::cerr << "location_path: " << location_path << std::endl;
				if (g_print) std::cerr << "subtracted_location: " << subtracted_location << std::endl;

				m_script_path_translated.construct(location->getRoot());
				m_script_path_translated.append_path(subtracted_location);
			} else {
				m_script_path_translated.clear();
			}
			if (g_print) std::cerr << "m_script_path_translated: " << m_script_path_translated << std::endl;
		} else {
			if (g_print) std::cerr << "webserv: make cgi path: no extension" << std::endl;
		}
	}
	if (!result) {
		size_t index = 0;

		for (; index < m_location->getIndexFilesCount(); index += 1) {
			if (Path(m_location->getIndexFileName(index)).get_extension().exact_equals(m_location->getCGIextension())) {
				break ;
			}
		}
		if (index < m_location->getIndexFilesCount()) {
			m_fs_requested_resource_path.append_segments(m_location->getIndexFileName(index));
			m_fs_requested_resource_path.reduce_dot_segments();
			if (g_print) std::cerr << "1m_fs_requested_resource_path: " << m_fs_requested_resource_path << std::endl;
			result = make_script_path();
		}
	}
	return (result);
}

ViewData	Client::get_query_part(const ViewData &view_) {
	int		until_qm = view_.count_chars_until('?');

	return until_qm >= 0 ? ViewData(view_).move_pointer(until_qm + 1) : ViewData("");
}
