#ifndef HOST_HPP
#define HOST_HPP

#include "Header.hpp"
#include "../ViewData.hpp"
#include <iostream>

class Host : public Header {
private:
    std::string	m_host;

public:
	Host(const std::string &view): Header("Host"), m_host(view) {}
	~Host() {}

	void		parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Host", view) && view.size() == 0) {
			m_host = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Host Header" << std::endl;
		}    	
#if 0
        std::string field_value1 = field_value.to_string();
        size_t place = 0;
        place = field_value1.find(":");
        if (place) {
            std::string st = field_value1.substr(place + 1);
	        port = std::atoi(st.c_str());
            IP = field_value1.substr(0, place);
        }
        else 
            IP = field_value1;
#endif
	}
    std::string	construct_field_value() const {
	    return m_host;
    }

    Header		*clone() const {
	    return new Host(*this);
    }

};


#endif /* HOST_HPP */
