#ifndef UserAgent_HPP
#define UserAgent_HPP

#include "Header.hpp"

class UserAgent : public Header {
private:
	
	std::string m_agents;

public:
	UserAgent(): Header("User-Agent") {}
	~UserAgent() {}

	void		parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("User-Agent", view) && view.size() == 0) {
			m_agents = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid User-Agent field_value" << std::endl;
		}
	}
	std::string	construct_field_value() const {
		return m_agents;
	}
	Header	*clone() const {
		return new UserAgent(*this);
	}
};


#endif /* UserAgent_HPP */
