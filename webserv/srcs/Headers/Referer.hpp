#ifndef Referer_HPP
#define Referer_HPP

#include "Header.hpp"

class Referer : public Header {
private:

	std::string m_str;

public:
	Referer(): Header("Referer") {}
	~Referer() {}

	void		parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Referer", view) && view.size() == 0) {
			m_str = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Referer field_value" << std::endl;
		}
	}
	std::string	construct_field_value() const {
		return m_str;
	}
	Header	*clone() const {
		return new Referer(*this);
	}
};


#endif /* Referer_HPP */
