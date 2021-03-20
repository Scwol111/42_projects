#ifndef AcceptLanguage_HPP
#define AcceptLanguage_HPP

#include "Header.hpp"
#include "../ViewData.hpp"
#include <iostream>

class AcceptLanguage : public Header {
private:
	std::string	language;

public:
	AcceptLanguage(const std::string &view): Header("Accept-Language"), language(view) {}
	~AcceptLanguage() {}

	void		parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Accept-Language", view) && view.size() == 0) {
			language = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Accept-Language field_value" << std::endl;
		}
	}
	std::string	construct_field_value() const {
		return language;
	}
	Header		*clone() const {
		return new AcceptLanguage(*this);
	}
};


#endif /* AcceptLanguage_HPP */
