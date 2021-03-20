#ifndef ServerHeader_HPP
#define ServerHeader_HPP


#include "Header.hpp"

class ServerHeader : public Header {
private:
	std::string		m_product;

public:
	ServerHeader(): Header("Server"), m_product("webserv/1.0") {}
	ServerHeader(const std::string &product): Header("Server"), m_product(product) {}
	~ServerHeader() {}

	void		parse_field_value(const ViewData &field_value) {
		m_product = field_value.to_string();
	}
	std::string	construct_field_value() const {
		return m_product;
	}
	Header		*clone() const {
		return new ServerHeader(*this);
	}
};


#endif /* ServerHeader_HPP */ 
