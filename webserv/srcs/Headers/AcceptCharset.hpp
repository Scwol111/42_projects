#ifndef AcceptCharset_HPP
#define AcceptCharset_HPP

#include "Header.hpp"
#include "../ViewData.hpp"

class AcceptCharset : public Header {
private:
	std::string	charset;

public:
	AcceptCharset(const std::string &view): Header("Accept-Charset"), charset(view) {}
	~AcceptCharset() {}

    void		parse_field_value(const ViewData &field_value) {
    	ViewData	view(field_value);
    	if (g_bnf.match("Accept-Charset", view) && view.size() == 0) {
	        charset = field_value.to_string();
    	} else {
    		m_status_code = StatusCode::BadRequest;
    		std::cerr << "Invalid Accept-Charset field_value" << std::endl;
    	}
    }
    std::string	construct_field_value() const {
    	return charset;
    }
    Header		*clone() const {
    	return new AcceptCharset(*this);
    }
};


#endif /* AcceptCharset_HPP */
