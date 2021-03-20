#ifndef Location_HPP
#define Location_HPP

#include "Header.hpp"

class LocationHeader : public Header {
private:
	std::string	m_value;

public:
	LocationHeader(const std::string &value): Header("Location"), m_value(value) {}
	~LocationHeader() {}

	void	parse_field_value(const ViewData &field_value) {
	    ViewData	view(field_value);
	    if (g_bnf.match("Location", view) && view.size() == 0) {
		    m_value = field_value.to_string();
	    } else {
		    m_status_code = StatusCode::BadRequest;
		    std::cerr << "Invalid Location Header" << std::endl;
	    }
	}
	std::string	construct_field_value() const {
	    return m_value;
    }
	Header		*clone() const {
	    return new LocationHeader(*this);
	}
};


#endif /* Location_HPP */ 
