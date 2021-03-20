
#ifndef Path_Hpp
# define Path_Hpp

# include "ViewData.hpp"

# include <vector>
# include <string>

class Path {
private:

	std::vector<ViewData>	m_segments;
	bool	m_is_root;
	bool	m_is_opt_last_slash;

public:
	Path(): m_is_root(true), m_is_opt_last_slash(false) {}
	Path(const ViewData &segments) { construct(segments); }
	Path(const Path &path)
		: m_segments(path.m_segments)
		, m_is_root(path.m_is_root)
		, m_is_opt_last_slash(path.m_is_opt_last_slash)
		{}
	~Path() {}
	Path	&operator=(const Path &path) {
		m_segments = path.m_segments;
		m_is_root = path.m_is_root;
		m_is_opt_last_slash = path.m_is_opt_last_slash;
		return *this;
	}

	std::string		to_string() const;
	std::string		to_no_pct_string() const;

	bool			is_subpath_of(const Path &) const;
	bool			is_intermediate_subpath_of(const Path &intermediate, const Path &) const;
	Path			subtract_from(const Path &) const;

	void			construct(const ViewData &);
	void			append_segments(const ViewData &);
	void			append_path(const Path &);
	void			prepend_segments(const ViewData &);
	void			prepend_path(const Path &);
	size_t			reduce_dot_segments();
	void			clear();

	size_t			size() const;
	const ViewData	&operator[](size_t index) const;
	ViewData		&operator[](size_t index);

	bool			is_root() const;
	void			set_root(bool = true);
	void			set_opt_last_slash(bool = true);

	void			pop_back();

	ViewData		get_extension() const;
};

std::ostream	&operator<<(std::ostream &, const Path &);



#endif /* Path_Hpp */
