
#ifndef Expect_Hpp
# define Expect_Hpp

# include "Header.hpp"

class Expect : public Header {
private:
	std::string	value;

public:
	Expect(): Header("Expect") {}
	~Expect() {}

	void		parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Expect", view) && view.size() == 0) {
			value = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Expect field_value" << std::endl;
		}
	}
	std::string		construct_field_value() const {
		return value;
	}
	Header			*clone() const {
		return new Expect(*this);
	}
};





#endif
