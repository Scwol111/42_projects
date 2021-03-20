/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MessageBody.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:38:36 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/07 13:45:22 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_BODY_HPP
#define MESSAGE_BODY_HPP

#include <vector>
#include <ostream>
#include "ViewData.hpp"

/* Representation of payload of message */

class MessageBody {
private:

	std::vector<unsigned char>	m_data;

	MessageBody(const MessageBody &);
	MessageBody	&operator=(const MessageBody &);
public:
	MessageBody() {}
	~MessageBody() {}

	void	append(const ViewData &view) {
		m_data.insert(m_data.end(), view.view_char(), view.view_char() + view.size());
	}
	void	erase_from_front(size_t count) {
		if (m_data.size() > count) {
			m_data.erase(m_data.begin(), m_data.begin() + count);
		} else {
			m_data.clear();
		}
	}
	void	erase_from_back(size_t count) {
		if (m_data.size() > count) {
			m_data.erase(m_data.end() - count, m_data.end());
		} else {
			m_data.clear();
		}
	}
	void	decompress_gzip_data();
	void	decompress_zlib_data();

	void	clear() {
		m_data.clear();
	}
	unsigned char	*data() {
		return m_data.size() > 0 ? &m_data[0] : NULL;
	}
	const unsigned char	*data() const {
		return m_data.size() > 0 ? &m_data[0] : NULL;
	}
	const std::vector<unsigned char>	&rdata() const {
		return m_data;
	}
	size_t	size() const {
		return m_data.size();
	}


};

std::ostream	&operator<<(std::ostream &output, const MessageBody &);

#endif /* MESSAGE_BODY_HPP */
