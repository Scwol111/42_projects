#ifndef ContentLocation_HPP
#define ContentLocation_HPP

#include "Header.hpp"

class ContentLocation : public Header {
private:
	std::string	location;

public:
	ContentLocation(const std::string &view): Header("Content-Location"), location(view) {}
	~ContentLocation() {}

	void	parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Content-Location", view) && view.size() == 0) {
			location = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Content-Location field_value" << std::endl;
		}
	}
	std::string	construct_field_value() const {
		return location;
	}
	Header	*clone() const {
		return new ContentLocation(*this);
	}
};


#endif /* ContentLocation_HPP */
