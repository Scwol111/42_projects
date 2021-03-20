/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ViewData.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:15:48 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/14 13:03:18 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_DATA_HPP
#define VIEW_DATA_HPP

#include <vector>
#include <string>
#include <cstring>

#include <iostream>

#define PRINT_CHECKPOINT 0

#if PRINT_CHECKPOINT
extern bool print_checkpoint;
extern std::string print_indent;
#endif

class ViewData {
private:
	const unsigned char	*data;
	size_t				start;
	size_t				len;

	ViewData();
public:
	ViewData(const std::vector<unsigned char> &vec)
		: data(vec.size() > 0 ? &vec[0] : NULL)
		, start(0), len(vec.size()) {}
	ViewData(const std::string &str)
		: data(reinterpret_cast<const unsigned char *>(str.size() > 0 ? str.c_str() : NULL))
		, start(0), len(str.size()) {}
	ViewData(const unsigned char *raw, size_t len)
		: data(raw), start(0), len(len) {}
	ViewData(const char *str)
		: data(reinterpret_cast<const unsigned char *>(str)), start(0), len(std::strlen(str)) {}
	ViewData(const char *str, size_t len)
		: data(reinterpret_cast<const unsigned char *>(str)), start(0), len(len) {}
	ViewData(const ViewData &v, size_t len): data(v.data), start(v.start), 
		len(std::min(v.start + len, v.len)) {}
	ViewData(const ViewData &v): data(v.data), start(v.start), len(v.len) {}
	~ViewData() {}
	ViewData	&operator=(const ViewData &v) {
		data = v.data;
		start = v.start;
		len = v.len;
		return *this;
	}

	/* Returns -1 if delimiter not found. */
	int					count_chars_until(char delimiter) const;
	int					count_chars_until_not_escaped(char delimiter) const;
	int					count_chars_until(const ViewData &) const;
	int					count_chars_until_last(char delimiter) const;
	int					count_chars_until_some_char(const ViewData &) const;
	int					count_chars_until_not_some_char(const ViewData &) const;
	int					count_chars_until_ws() const;
	const unsigned char	*view() const;
	const char			*view_char() const;
	size_t				size() const;

	bool				operator==(char ch) const;
	bool				operator!=(char ch) const;
	bool				operator==(const ViewData &) const;
	bool				operator!=(const ViewData &) const;

	bool				partial_equals(const ViewData &str) const;
	bool				partial_caseins_equals(const ViewData &str) const;
	bool				exact_equals(const ViewData &str) const;
	bool				exact_caseins_equals(const ViewData &str) const;
	bool				consists_char(char) const;

	/* Returns '\0' if out of bounds. */
	char				operator[](size_t index) const;

	ViewData			&move_pointer(int offset = 1);
	size_t				get_position() const;
	ViewData			&restore_position(size_t position = 0);
	ViewData			&truncate_to(size_t position);

	std::string			to_string() const;
	std::string			to_no_pct_string() const;
	long				to_long(int base = 10) const;
	std::string			substr_until(const std::string &) const;

	bool				skip_ws();

	ViewData			subview_trunc(int size);
	ViewData			subview_move(int size);

public:

	class	Checkpoint {
		ViewData	&view;
		size_t		start;
		bool		status;
		std::string	name;

	public:
		Checkpoint(const Checkpoint &parse)
			: view(parse.view)
			, start(parse.start)
			, status(parse.status)
			, name(parse.name)
			{}
		Checkpoint(ViewData &view, bool status = false, const std::string &name = "unnamed")
			: view(view)
			, start(view.get_position())
			, status(status)
			, name(name)
			{
#if PRINT_CHECKPOINT
				if (print_checkpoint) {
					int size = view.count_chars_until('\n');
					std::cout << print_indent << name << " @" << ViewData(view, size >= 0 ? size : view.size()).to_string() << "@" << std::endl;
					print_indent.push_back('\t');
				}
#endif
			}
		~Checkpoint() {
			if (!status) {
				rewind();
			}
#if PRINT_CHECKPOINT
			if (print_checkpoint) {
				print_indent.pop_back();
				std::cout << print_indent << name << " !!";
				if (!status) {
					std::cout << "cannot";
				}
				std::cout << std::endl;
			}
#endif
		}
		Checkpoint	&operator=(bool value) {
			status = value;
			return *this;
		}
		Checkpoint	&operator=(const Checkpoint &check) {
			status = check.status;
			return *this;
		}
		operator bool () const {
			return status;
		}
		void		rewind() {
			view.restore_position(start);
		}
		size_t		distance() const {
			return (view.get_position() - start);
		}
		size_t		get_position() const {
			return (start);
		}
		ViewData	get_frame_until(size_t pos) const {
			ViewData	iview(view);
			iview.restore_position(start);
			iview.truncate_to(pos);
			return iview;
		}
		ViewData	get_frame() const {
			return get_frame_until(view.get_position());
		}
		const Checkpoint	&frame_to(ViewData &iview) const {
			iview = get_frame();
			return *this;
		}
		const Checkpoint	&position_to(size_t &pos) const {
			pos = start;
			return *this;
		}
	};

};

std::ostream	&operator<<(std::ostream &output, const ViewData &view);

#endif /* VIEW_DATA_HPP */
