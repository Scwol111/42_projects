

#include "Method.hpp"

const std::string	Method::strings[Invalid + 1] = {
	"GET", "HEAD", "POST", "PUT", "DELETE", "Invalid",
};

Method::Set::Set() {
	clear();
}

bool	Method::Set::consist(const Method &method) const {
	return (method != Invalid && methods[method]);
}

void	Method::Set::clear() {
	for (size_t index = 0; index < Invalid; index += 1) {
		methods[index] = false;
	}
}

void	Method::Set::set(const Method &method) {
	if (method != Invalid) {
		methods[method] = true;
	}
}

void	Method::Set::unset(const Method &method) {
	if (method != Invalid) {
		methods[method] = false;
	}
}

Method	Method::from_int(int index) {
	return index >= 0 && index < Invalid ? static_cast<EnumType>(index) : Invalid;
}
