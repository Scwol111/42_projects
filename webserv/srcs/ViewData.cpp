/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ViewData.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:28:16 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/11 17:44:55 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ViewData.hpp"
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

int					ViewData::count_chars_until(char delimiter) const {
	size_t			count = 0;
	const char	*raw_data = view_char();

	if (raw_data) {
		while (count < size()) {
			if (raw_data[count] == delimiter) {
				break ;
			}
			count += 1;
		}
		if (count >= size()) {
			count = -1;
		}
	} else {
		count = -1;
	}
	return (static_cast<int>(count));
}

int					ViewData::count_chars_until_not_escaped(char delimiter) const {
	size_t		count = 0;
	const char	*raw_data = view_char();

	if (raw_data) {
		while (count < size()) {
			if (raw_data[count] == '\\') {
				count += 1;
			} else if (raw_data[count] == delimiter) {
				break ;
			}
			count += 1;
		}
		if (count >= size()) {
			count = -1;
		}
	} else {
		count = -1;
	}
	return (static_cast<int>(count));
}

int					ViewData::count_chars_until_last(char delimiter) const {
	ViewData	view(*this);
	int		count;
	int		count_last = -1;

	while ((count = view.count_chars_until(delimiter)) >= 0) {
		count_last = count;
		view.move_pointer(count + 1);
	}
	return (count_last);
}

int					ViewData::count_chars_until(const ViewData &view) const {
	int			count = 0;

	if (size() >= view.size()) {
		while (count <= static_cast<int>(size() - view.size())) {
			if (ViewData(*this).move_pointer(count).partial_equals(view)) {
				break ;
			}
			count += 1;
		}
		if (count > static_cast<int>(size() - view.size())) {
			count = -1;
		}
	} else {
		count = -1;
	}
	return (count);
}

int					ViewData::count_chars_until_some_char(const ViewData &view) const {
	int			count = 0;

	while (count < static_cast<int>(size())) {
		if (view.consists_char(view_char()[count])) {
			break ;
		}
		count += 1;
	}
	if (count >= static_cast<int>(size())) {
		count = -1;
	}
	return (count);
}

int					ViewData::count_chars_until_not_some_char(const ViewData &view) const {
	int			count = 0;

	while (count < static_cast<int>(size())) {
		if (!view.consists_char(view_char()[count])) {
			break ;
		}
		count += 1;
	}
	if (count >= static_cast<int>(size())) {
		count = -1;
	}
	return (count);
}

int					ViewData::count_chars_until_ws() const {
	return (count_chars_until_some_char(" \r\n\f\v\t"));
}

const unsigned char	*ViewData::view() const {
	return start < len ? data + start : NULL;
}

const char			*ViewData::view_char() const {
	return reinterpret_cast<const char *>(view());
}

size_t				ViewData::size() const {
	return start <= len ? len - start : 0;
}

bool				ViewData::operator==(char ch) const {
	return *reinterpret_cast<const char *>(data) == ch;
}

bool				ViewData::operator!=(char ch) const {
	return !(*this == ch);
}

bool				ViewData::operator==(const ViewData &view) const {
	return std::string(view_char(), size()) == std::string(view.view_char(), view.size());
}

bool				ViewData::operator!=(const ViewData &view) const {
	return !(*this == view);
}

bool				ViewData::partial_equals(const ViewData &view) const {
	bool	result = false;

	if (size() >= view.size()) {
		result = true;
		for (size_t i = 0; i < view.size(); i += 1) {
			if (view[i] != view_char()[i]) {
				result = false;
				break ;
			}
		}
	}
	return (result);
}

bool				ViewData::partial_caseins_equals(const ViewData &view) const {
	bool	result = false;

	if (size() >= view.size()) {
		result = true;
		for (size_t i = 0; i < view.size(); i += 1) {
			if (tolower(view[i]) != tolower(view_char()[i])) {
				result = false;
				break ;
			}
		}
	}
	return (result);
}

bool				ViewData::exact_equals(const ViewData &view) const {
	return (size() == view.size() && partial_equals(view));
}

bool				ViewData::exact_caseins_equals(const ViewData &view) const {
	return (size() == view.size() && partial_caseins_equals(view));
}

bool				ViewData::consists_char(char ch) const {
	bool	result = false;

	for (size_t index = 0; index < size(); index += 1) {
		if (view_char()[index] == ch) {
			result = true;
		}
	}
	return (result);
}

char				ViewData::operator[](size_t index) const {
	return index < size() ? view_char()[index] : 0;
}

ViewData			&ViewData::move_pointer(int offset) {
	offset = std::min(offset, (int)size());
	offset = std::max(offset, -(int)start);
	start += offset;
	return *this;
}

size_t				ViewData::get_position() const {
	return start;
}

ViewData			&ViewData::restore_position(size_t position) {
	start = std::min(position, len);
	return *this;
}

ViewData			&ViewData::truncate_to(size_t position) {
	len = std::min(position, len);
	return *this;
}

std::string			ViewData::to_string() const {
	return std::string(view_char(), size());
}

std::string			ViewData::to_no_pct_string() const {
	std::ostringstream	text;
	const char	*data = view_char();

	for (size_t i = 0; i < size(); i += 1) {
		if (data[i] == '%') {
			if (size() - i > 2) {
				text << (char) ViewData(data + i + 1, 2).to_long(16);
			}
			i += 2;
		} else {
			text << data[i];
		}
	}
	return text.str();
}

long				ViewData::to_long(int base) const {
	char *val;
	return size() > 0 ? std::strtol(view_char(), &val, base) : 0;
}

std::string			ViewData::substr_until(const std::string &seq) const {
	ViewData	view(*this);
	std::string	result;

	while (view.size() > 0 && !view.partial_equals(seq)) {
		view.move_pointer();
	}
	if (view.size() > 0) {
		result = ViewData(*this).truncate_to(view.get_position()).to_string();
	}
	return (result);
}

bool			ViewData::skip_ws() {
	int		until_not_ws = count_chars_until_not_some_char(" \t\v\f\r\n");

	move_pointer(until_not_ws < 0 ? size() : until_not_ws);
	return (until_not_ws >= 0);
}

ViewData		ViewData::subview_trunc(int size) {
	ViewData	view(*this);

	if (size >= 0) {
		view.truncate_to(get_position() + size);
	}
	return (view);
}

ViewData		ViewData::subview_move(int size) {
	ViewData	view(*this);

	if (size >= 0) {
		view.move_pointer(size);
	} else {
		view.move_pointer(view.size());
	}
	return (view);
}

std::ostream	&operator<<(std::ostream &output, const ViewData &view) {
	output << view.to_string();
	return output;
}
