#ifndef ALLOW_HPP
#define ALLOW_HPP
//Посылается сервером вместе со статусами 
//405 (серверу метод известен, но он неприменим к конкретному ресурсу,) и 
//501(сервер не распознал указанный клиентом метод), 
//а также в ответе на метод OPTIONS
#include "Header.hpp"
#include "../ViewData.hpp"
#include <iostream>

class Allow : public Header {
private:
	std::string	m_methods;

public:
	Allow(const std::string &view): Header("Allow"), m_methods(view) {}
	~Allow() {}

	void	parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Allow", view) && view.size() == 0) {
			m_methods = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Allow Header" << std::endl;
		}
	}
	std::string	construct_field_value() const {
		return m_methods;
	}
	Header		*clone() const {
		return new Allow(*this);
	}
};


#endif /* ALLOW_HPP */
