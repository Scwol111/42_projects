#ifndef ContentLanguage_HPP
#define ContentLanguage_HPP

#include "Header.hpp"
#include <iostream>

class ContentLanguage : public Header {
private:
	std::string	m_lang;

public:
	ContentLanguage(const std::string &lang): Header("Content-Language"), m_lang(lang) {}
	~ContentLanguage() {}

	void	parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Content-Language", view) && view.size() == 0) {
			m_lang = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Content-Length field_value" << std::endl;
		}
	}

	std::string	construct_field_value() const {
		return m_lang;
	}
	
	Header	*clone() const {
		return new ContentLanguage(*this);
	}
};


#endif /* ContentLanguage_HPP */
