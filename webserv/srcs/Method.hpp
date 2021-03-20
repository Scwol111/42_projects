
#ifndef Method_Hpp
# define Method_Hpp

# include <string>

class Method {
public:
	enum EnumType {
		GET, HEAD, POST, PUT, DELETE, Invalid, Count = Invalid,
	};

	class Set {
		bool	methods[Invalid];

	public:
		Set();
		bool	consist(const Method &) const;
		void	clear();
		void	set(const Method &);
		void	unset(const Method &);
	};

private:
	EnumType	type;

	static const std::string	strings[Invalid + 1];

public:
	Method(): type(Invalid) {}
	Method(EnumType type): type(type) {}
	Method(size_t index): type(from_int(index)) {}

	const std::string	&to_string() const {
		return strings[type];
	}

	Method	&operator=(EnumType type) {
		this->type = type;
		return *this;
	}

	bool	operator==(EnumType right) const {
		return (type == right);
	}
	bool	operator!=(EnumType right) const {
		return (type != right);
	}
	operator EnumType() const {
		return type;
	}

	static Method	from_int(int index);
};

#endif /* Method_Hpp */
