#ifndef Authorization_HPP
#define Authorization_HPP


#include "Header.hpp"
#include <iostream>

class Authorization : public Header {
private:
	std::string	authorization;

public:
	Authorization(const std::string &view): Header("Authorization"), authorization(view) {}
	~Authorization() {}

    void		parse_field_value(const ViewData &field_value) {
    	ViewData	view(field_value);
    	if (g_bnf.match("Authorization", view) && view.size() == 0) {
    		authorization = field_value.to_string();
    	} else {
    		m_status_code = StatusCode::BadRequest;
    		std::cerr << "Invalid Authorization field_value |" << field_value << "|" << std::endl;
    	}
    }
    std::string	construct_field_value() const {
    	return authorization;
    }
    Header	*clone() const {
    	return new Authorization(*this);
    }
    const std::string	&get_value() const {
    	return authorization;
    }
};


#endif /* Authorization_HPP */
