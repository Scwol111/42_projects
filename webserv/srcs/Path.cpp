
#include "Path.hpp"
#include <sstream>

std::string	Path::to_string() const {
	std::ostringstream	text;

	if (m_is_root) {
		text << '/';
	}
	for (size_t i = 0; i < m_segments.size(); i += 1) {
		text << m_segments[i];
		if (i + 1 < m_segments.size() || m_is_opt_last_slash) {
			text << '/';
		}
	}
	return text.str();
}

std::string	Path::to_no_pct_string() const {
	std::ostringstream	text;

	if (m_is_root) {
		text << '/';
	}
	for (size_t i = 0; i < m_segments.size(); i += 1) {
		text << m_segments[i].to_no_pct_string();
		if (i + 1 < m_segments.size() || m_is_opt_last_slash) {
			text << '/';
		}
	}
	return text.str();
}

bool		Path::is_subpath_of(const Path &path) const {
	bool	result = false;

	if (m_is_root == path.m_is_root && m_segments.size() <= path.m_segments.size()) {
		result = true;
		for (size_t i = 0; i < m_segments.size(); i += 1) {
			if (!m_segments[i].exact_equals(path.m_segments[i])) {
				result = false;
				break ;
			}
		}
	}
	return (result);
}

bool			Path::is_intermediate_subpath_of(const Path &intermediate, const Path &path) const {
	bool	result = false;

	if (m_is_root == path.is_root()) {
		Path	intermediate_copy(intermediate);
		size_t	levels_down = intermediate_copy.reduce_dot_segments();

		result = true;
		if (levels_down <= size() && (result = size() - levels_down + intermediate_copy.size() <= path.size())) {
			size_t	segment_index = 0;
			for (; segment_index < size() - levels_down; segment_index += 1) {
				if (!m_segments[segment_index].exact_equals(path[segment_index])) {
					result = false;
					break ;
				}
			}
			if (result) {
				for (size_t i = 0; i < intermediate_copy.size(); i += 1, segment_index += 1) {
					if (!intermediate_copy[i].exact_equals(path[segment_index])) {
						result = false;
						break ;
					}
				}
			}
		}
	}
	return (result);
}

Path		Path::subtract_from(const Path &path) const {
	Path	result("");
	size_t	start = path.size();

	if (m_segments.size() >= path.size()) {
		for (size_t i = 0; i < path.size(); i += 1) {
			if (!m_segments[i].exact_equals(path.m_segments[i])) {
				start = i;
				break ;
			}
		}
		if (start < m_segments.size()) {
			result.m_segments.insert(result.m_segments.begin(), m_segments.begin() + start, m_segments.end());
			result.m_is_root = start ? false : m_is_root;
			result.m_is_opt_last_slash = m_is_opt_last_slash;
		}
	}
	return (result);
}

void		Path::construct(const ViewData &view_) {
	ViewData	segments(view_);

	clear();
	if (segments.size() > 0) {
		m_is_root = (segments[0] == '/');
		for (int count = segments.count_chars_until('/'); count >= 0; count = segments.count_chars_until('/')) {
			if (count > 0) {
				m_segments.push_back(ViewData(segments, count));
				segments.move_pointer(count + 1);
				if (segments.size() == 0) {
					m_is_opt_last_slash = true;
				}
			} else {
				segments.move_pointer();
			}
		}
		if (segments.size() > 0) {
			m_segments.push_back(segments);
		}
	}
}

void		Path::append_segments(const ViewData &view_) {
	if (m_segments.size() > 0 || m_is_root) {
		Path	path(view_);
		append_path(path);
	} else {
		construct(view_);
	}
}

void		Path::append_path(const Path &path) {
	if (m_segments.size() > 0 || m_is_root) {
		m_segments.insert(m_segments.end(), path.m_segments.begin(), path.m_segments.end());
		m_is_opt_last_slash = path.m_is_opt_last_slash;
	} else {
		*this = path;
	}
}

void		Path::prepend_segments(const ViewData &view_) {
	if (m_segments.size() > 0 || m_is_root) {
		Path	path(view_);
		prepend_path(path);
	} else {
		construct(view_);
	}
}

void		Path::prepend_path(const Path &path) {
	if (m_segments.size() > 0 || m_is_root) {
		m_segments.insert(m_segments.begin(), path.m_segments.begin(), path.m_segments.end());
		m_is_opt_last_slash = path.m_is_opt_last_slash;
	} else {
		*this = path;
	}
}

size_t		Path::reduce_dot_segments() {
	std::vector<ViewData>	temp;
	size_t					levels_down = 0;
	int						level = 0;

	temp.reserve(m_segments.size());
	for (size_t i = 0; i < m_segments.size(); i += 1) {
		if (m_segments[i].exact_equals(".")) {
			if (i == 0) {
				temp.push_back(m_segments[i]);
			}
		} else if (m_segments[i].exact_equals("..")) {
			if (temp.size() > 0) {
				temp.pop_back();
			}
			level -= 1;
			if (level < 0) {
				levels_down = std::max(levels_down, (size_t) -level);
			}
		} else {
			temp.push_back(m_segments[i]);
			level += 1;
		}
	}
	if (temp.size() != m_segments.size()) {
		m_segments = temp;
	}
	return (levels_down);
}

void		Path::clear() {
	m_segments.clear();
	m_is_root = false;
	m_is_opt_last_slash = false;
}

size_t		Path::size() const {
	return m_segments.size();
}

const ViewData	&Path::operator[](size_t index) const {
	return m_segments[index];
}

ViewData	&Path::operator[](size_t index) {
	return m_segments[index];
}

bool		Path::is_root() const {
	return m_is_root;
}

void		Path::set_root(bool value) {
	m_is_root = value;
}

void		Path::set_opt_last_slash(bool value) {
	m_is_opt_last_slash = value;
}

void		Path::pop_back() {
	if (m_segments.size() > 0) {
		m_segments.pop_back();
	}
}

ViewData	Path::get_extension() const {
	ViewData	view("");

	if (m_segments.size() > 0) {
		ViewData	iview(m_segments[m_segments.size() - 1]);
		int			count_chars = iview.count_chars_until_last('.');

		if (count_chars >= 0) {
			view = iview.move_pointer(count_chars + 1);
		}
	}
	return (view);
}

std::ostream	&operator<<(std::ostream &output, const Path &path) {
	output << path.to_string();
	return (output);
}
