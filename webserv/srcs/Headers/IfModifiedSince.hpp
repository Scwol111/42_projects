#ifndef IfModifiedSince_HPP
#define IfModifiedSince_HPP


#include "Header.hpp"

class IfModifiedSince : public Header {
private:
	std::string	m_modified;

public:
	IfModifiedSince(const std::string &viev): Header("If-Modified-Since"), m_modified(viev) {}
	~IfModifiedSince() {}

   	void	parse_field_value(const ViewData &field_value) {
	    ViewData	view(field_value);
	    if (g_bnf.match("If-Modified-Since", view) && view.size() == 0) {
		    m_modified = field_value.to_string();
	    } else {
		    m_status_code = StatusCode::BadRequest;
		    std::cerr << "Invalid If-Modified-Since Header" << std::endl;
	    }
	}
	std::string	construct_field_value() const {
	    return m_modified;
    }
	Header		*clone() const {
	    return new IfModifiedSince(*this);
	}
};


#endif /* IfModifiedSince_HPP */ 
