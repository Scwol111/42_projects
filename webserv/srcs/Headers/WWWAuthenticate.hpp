

#ifndef WWWAuthenticate_HPP
#define WWWAuthenticate_HPP

#include "Header.hpp"
#include <sstream>

class WWWAuthenticate : public Header {
private:
	std::string	m_auth;

public:
	WWWAuthenticate(const ViewData &realm): Header("WWW-Authenticate") {
		std::ostringstream	text;

		text << "Basic realm=\"" << realm << "\"";
		m_auth = text.str();
	}
	~WWWAuthenticate() {}

	void	parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("WWW-Authenticate", view) && view.size() == 0) {
			m_auth = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid WWW-Authenticate field_value" << std::endl;
		}
	}
	std::string	construct_field_value() const {
		return m_auth;
	}
	Header	*clone() const {
		return new WWWAuthenticate(*this);
	}
};



#endif /* WWWAuthenticate_HPP */

