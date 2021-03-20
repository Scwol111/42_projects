#ifndef TransferEncoding_HPP
#define TransferEncoding_HPP

#include "Header.hpp"

class TransferEncoding : public Header {
private:
	std::string	states;

public:
	TransferEncoding(): Header("Transfer-Encoding") {}
	TransferEncoding(const ViewData &view): Header("Transfer-Encoding"), states(view.to_string()) {}
	~TransferEncoding() {}


    void		parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Transfer-Encoding", view) && view.size() == 0) {
			states = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Transfer-Encoding field_value" << std::endl;
		}
	}
	std::string	construct_field_value() const {
		return states;
	}
	Header	*clone() const {
		return new TransferEncoding(*this);
	}
	size_t	count_states() const {
		ViewData	view(states);
		BNF::ViewTree	tree = g_bnf.make_tree("Transfer-Encoding", view);
		return (tree.begin().get_childs_count());
	}
	ViewData	get_state(size_t index) const {
		ViewData	view(states), result("");
		BNF::ViewTree	tree = g_bnf.make_tree("Transfer-Encoding", view);
		BNF::ViewTree::Iter	it = tree.begin();
		if (it.get_childs_count() > 0) do {
			if (index == 0) {
				result = it->value;
				break ;
			} else {
				index -= 1;
			}
		} while (it.next());
		return (result);
	}

};


#endif /* TransferEncoding_HPP */
