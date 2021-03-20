#ifndef RetryAfter_HPP
#define RetryAfter_HPP


#include "Header.hpp"

class RetryAfter : public Header {
private:
	std::string	m_str;

public:
	RetryAfter(): Header("Retry-After") {}
	~RetryAfter() {}

	void		parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Retry-After", view) && view.size() == 0) {
			m_str = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Retry-After field_value" << std::endl;
		}
	}
	std::string	construct_field_value() const {
		return m_str;
	}
	Header	*clone() const {
		return new RetryAfter(*this);
	}
};


#endif /* RetryAfter_HPP */ 
