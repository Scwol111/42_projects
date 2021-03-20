/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BNF.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:27:38 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/15 19:09:41 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BNF_HPP
#define BNF_HPP

#include <string>
#include <vector>
#include <stack>
#include <exception>
#include "ViewData.hpp"

/* Implementation of BNF (https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form) */
/* Its used for parsing CGI Params and will be used for parsing URI */

class BNF {
private:
	struct	InvalidRuleList : std::exception {
		const char	*what() const throw() {
			return "Invalid Rule List";
		}
	};
	struct	RuleNotFound : std::exception {
		std::string	reason;

		RuleNotFound(const std::string &reason) : reason(reason) {}
		~RuleNotFound() throw() {}
		const char	*what() const throw() {
			return reason.c_str();
		}
	};

public:
	struct	ViewTree {
		struct	Node {
			std::string	name;
			ViewData	value;

			Node(): value("") {}

			int					parent;
			std::vector<int>	childs;
		};
		struct	Iter {
			const ViewTree	&tree;
			const Node		*parent;
			std::stack<int>	currents;
			int				current;

			friend struct ViewTree;

			Iter(const ViewTree &tree, const Node *node): tree(tree), parent(node), current(0) {}
			Iter	&operator=(const Iter &it) {
				parent = it.parent;
				currents = it.currents;
				current = it.current;
				return *this;
			}
			Iter		get(const ViewData &, int index = 0) const;
			bool		next();
			bool		prev();
			bool		down();
			bool		up();
			void		unlink();
			const std::string	&name() const;
			const ViewData		&value() const;
			const Node	*get_current() const;
			size_t		get_childs_count() const;
			const Node	*operator->() const;
			operator bool () { return !!parent; }
		};
		struct	Checkpoint {
			ViewTree	&tree;
			size_t		nodes_size;
			int			parent_id;
			size_t		childs_size;
			bool		status;

			friend struct ViewTree;

			Checkpoint(ViewTree &tree, bool status = false)
				: tree(tree)
				, nodes_size(tree.nodes.size())
				, parent_id(tree.stack.top())
				, childs_size(tree.nodes[tree.stack.top()].childs.size())
				, status(status) {}
			~Checkpoint() {
				if (!status) {
					while (tree.stack.top() != parent_id) {
						std::cout << "delete stack " << tree.stack.top() << std::endl;
						tree.stack.pop();
					}
					tree.nodes[parent_id].childs.erase(tree.nodes[parent_id].childs.begin() + childs_size, tree.nodes[parent_id].childs.end());
					tree.nodes.erase(tree.nodes.begin() + nodes_size, tree.nodes.end());
				}
			}
			Checkpoint	&operator=(bool value) {
				status = value;
				return *this;
			}
			operator bool () {
				return status;
			}
		};

		std::vector<Node>	nodes;
		std::stack<int>		stack;
		std::string			emptystring;
		ViewData			emptyview;

		ViewTree(): emptyview("") {}

		bool	empty() const {
			return nodes.empty();
		}
		void	clear() {
			nodes.clear();
			while (stack.size() > 0) {
				stack.pop();
			}
		}
		Iter	begin() const {
			return Iter(*this, &nodes[0]);
		}
		std::string	to_string() const;
		const std::string	&get_empty_string() const {
			return emptystring;
		}
		const ViewData	&get_empty_view() const {
			return emptyview;
		}
	};

private:
	struct Rule {
		struct	Ref {
			bool	is_anon;
			size_t	index;
			BNF		&bnf;

			friend class BNF;

			Ref(const Ref &r): is_anon(r.is_anon), index(r.index), bnf(r.bnf) {}
			Ref(BNF &bnf, size_t index = 0, bool is_anon = false): is_anon(is_anon), index(index), bnf(bnf) {}
			Ref	&operator=(const Ref &r) {
				is_anon = r.is_anon;
				index = r.index;
				return *this;
			}
			const Rule	*operator*() const {
				const Rule	*rule = 0;
				if (is_anon) {
					rule = &bnf.m_anonymous_rules[index].rule;
				} else {
					rule = &bnf.m_entries[index].rule;
				}
				return rule;
			}
			Rule	*operator*() {
				Rule	*rule = 0;
				if (is_anon) {
					rule = &bnf.m_anonymous_rules[index].rule;
				} else {
					rule = &bnf.m_entries[index].rule;
				}
				return rule;
			}
			const Rule	*operator->() const {
				return **this;
			}
			Rule	*operator->() {
				return **this;
			}
		};

		struct	Node {
			enum	EnumType {
				Invalid, RuleType, TermType, TermCaseSensitiveType, CharRangeType,
				CharSeqType, CharSeqCaseSensitiveType
			};

			EnumType	type;
			Ref			rule_ref;
			ViewData	term;
			std::string	range;

			Node(BNF &bnf)
				: type(Invalid)
				, rule_ref(bnf)
				, term("") {}
			Node(BNF &bnf, const ViewData &term)
				: type(TermType)
				, rule_ref(bnf)
				, term(term) {}
			explicit Node(BNF &bnf, const std::string &range)
				: type(TermCaseSensitiveType)
				, rule_ref(bnf)
				, term("")
				, range(range) {}
			Node(const Ref &rule_ref)
				: type(RuleType)
				, rule_ref(rule_ref)
				, term("") {}
			Node(BNF &bnf, char a, char b)
				: type(CharRangeType)
				, rule_ref(bnf)
				, term("") { range += a; range += b; }

			bool	match(ViewData &, ViewTree &) const;
			std::string	get_info() const;
		};
		struct	Sequance {
			struct Point {
				Node		node;
				unsigned	min;
				unsigned	max;
				bool		is_combined;
				bool		is_negated;
				bool		is_list;

				Point(const Node &node, int min = 1, int max = 1)
					: node(node)
					, min(min)
					, max(max)
					, is_combined(false)
					, is_negated(false)
					, is_list(false)
					{}
				std::string	get_prefix() const;
			};

			std::vector<Point>	points;

			bool	match(ViewData &, ViewTree &) const;
		};

		std::vector<Sequance>	seqs;

		bool	match(ViewData &, ViewTree &) const;
	};

private:

	struct	RuleEntry {
		ViewData		name;
		ViewData		elements;
		bool			parsed;
		bool			in_process;
		Rule			rule;

		RuleEntry(const ViewData &name): name(name), elements(""), parsed(false), in_process(false) {}
		bool	operator==(const ViewData &view) const {
			return view.size() == name.size() && view.partial_caseins_equals(name);
		}
		bool	operator!=(const ViewData &view) const {
			return !(*this == view);
		}
	};
	struct	AnonRuleEntry {
		ViewData		content;
		Rule			rule;

		AnonRuleEntry(const ViewData &content): content(content) {}
	};

	std::vector<RuleEntry>		m_entries;
	std::vector<AnonRuleEntry>	m_anonymous_rules;
	bool						m_is_build_process;

	BNF() {}
	BNF(const BNF &);
	BNF	&operator=(const BNF &);
public:
	BNF(ViewData text);
	~BNF() {}

	BNF::ViewTree	make_tree(const std::string &rulename, ViewData &view) const;
	bool			match(const std::string &rulename, ViewData &) const;

	std::string	to_string() const;

private:

	const Rule		*find_rule(const std::string &name) const;
	int				find_rule_index(const ViewData &name);
	std::string		rule_to_string(const Rule &rule) const;

	ViewData::Checkpoint	parse_rulelist(ViewData &);
	ViewData::Checkpoint	parse_rule(ViewData &);
	ViewData::Checkpoint	parse_rulename(ViewData &);
	ViewData::Checkpoint	parse_defined_as(ViewData &, bool &additive);
	ViewData::Checkpoint	parse_elements(ViewData &, size_t i_entry);
	static ViewData::Checkpoint	parse_c_wsp(ViewData &);
	static ViewData::Checkpoint	parse_crlf(ViewData &);
	static ViewData::Checkpoint	parse_c_nl(ViewData &);
	static ViewData::Checkpoint	parse_comment(ViewData &);
	ViewData::Checkpoint	parse_alternation(ViewData &, Rule::Ref &);
	ViewData::Checkpoint	parse_concatenation(ViewData &, Rule::Sequance &);
	ViewData::Checkpoint	parse_combination(ViewData &, Rule::Sequance &);
	ViewData::Checkpoint	parse_repetition(ViewData &, Rule::Sequance::Point &point);
	ViewData::Checkpoint	parse_repeat(ViewData &, Rule::Sequance::Point &point);
	ViewData::Checkpoint	parse_element(ViewData &, Rule::Sequance::Point &point);
	ViewData::Checkpoint	parse_group_option(ViewData &, Rule::Sequance::Point &point);
	ViewData::Checkpoint	parse_char_val(ViewData &, Rule::Sequance::Point &point);
	ViewData::Checkpoint	parse_num_val(ViewData &, Rule::Sequance::Point &point);
	ViewData::Checkpoint	parse_bin_val(ViewData &, Rule::Sequance::Point &point);
	ViewData::Checkpoint	parse_dec_val(ViewData &, Rule::Sequance::Point &point);
	ViewData::Checkpoint	parse_hex_val(ViewData &, Rule::Sequance::Point &point);
	ViewData::Checkpoint	parse_prose_val(ViewData &, Rule::Sequance::Point &point);

	ViewData::Checkpoint	parse_unsigned(ViewData &, unsigned &);
	ViewData::Checkpoint	parse_bin_byte(ViewData &, unsigned char &);
	ViewData::Checkpoint	parse_dec_byte(ViewData &, unsigned char &);
	ViewData::Checkpoint	parse_hex_byte(ViewData &, unsigned char &);

	static ViewData::Checkpoint	parse_WSP_COMMA_WSP(ViewData &view);

	static bool	is_ALPHA(char c);
	static bool	is_BIT(char c);
	static bool	is_CHAR(char c);
	static bool	is_CR(char c);
	static bool	is_LF(char c);
	static bool	is_CTL(char c);
	static bool	is_DIGIT(char c);
	static bool	is_QUOTE(char c);
	static bool	is_DQUOTE(char c);
	static bool	is_BACKTICK(char c);
	static bool	is_START_LITERAL(char c);
	static bool	is_HEXDIG(char c);
	static bool	is_HTAB(char c);
	static bool	is_LWSP(char c);
	static bool	is_OCTET(char c);
	static bool	is_SP(char c);
	static bool	is_VCHAR(char c);
	static bool	is_WSP(char c);

};

extern BNF	g_bnf;

/*
BNF of BNF:

rulelist		=	1*( rule | (*c-wsp c-nl) )
rule			=	rulename defined-as elements c-nl
rulename		=	ALPHA *( ALPHA | DIGIT | %'-_' )
defined-as		=	*c-wsp ('=|' | '=') *c-wsp
elements		=	alternation *c-wsp
c-wsp			=	WSP | c-nl WSP
c-nl			=	comment | CRLF
comment			=	';' *(WSP | VCHAR) CRLF
alternation		=	concatenation *(*c-wsp '|' *c-wsp concatenation)
concatenation	=	combination *(1*c-wsp combination)
combination		=	repetition *( '.' repetition )
repetition		=	['!'] [repeat] element
repeat			=	*DIGIT '*' *DIGIT | *DIGIT '#' *DIGIT | 1*DIGIT
element			=	rulename | group | option | char-val | num-val | prose-val
group			=	'(' *c-wsp alternation *c-wsp ')'
option			=	'[' *c-wsp alternation *c-wsp ']'
char-val		=	START_LITERAL *( (SP | VCHAR).!QUOTE ) QUOTE
num-val			=	'%' (bin-val | dec-val | hex-val | char-val)
bin-val			=	'b' 1*BIT [ 1*('.' 1*BIT) | ('-' 1*BIT) ]
dec-val			=	'd' 1*DIGIT [ 1*('.' 1*DIGIT) | ('-' 1*DIGIT) ]
hex-val			=	'x' 1*HEXDIG [ 1*('.' 1*HEXDIG) | ('-' 1*HEXDIG) ]
prose-val		=	'<' *( (SP | VCHAR).!'>' ) '>'
*/

/*
ALPHA			=	%x41-5A | %x61-7A	; A-Z / a-z
BIT				=	%'01'
CHAR			=	%x01-7F
CR				=	%x0D
CRLF			=	CR LF | LF ; non-standard CRLF
CTL				=	%x00-1F | %x7F ; controls
DIGIT			=	%x30-39	; 0-9
DQUOTE			=	%x22 ; '\"'
QUOTE			=	%x27 ; '\''
BACKTICK		=	%d96 ; '`'
START_LITERAL	=	QUOTE | BACKTICK
HEXDIG			=	DIGIT | %'ABCDEF'
HTAB			=	%x09	; horizontal tab
LF				=	%x0A	; linefeed
LWSP			=	*(WSP | CRLF WSP)
OCTET			=	%x00-ff
SP				=	%x20
VCHAR			=	%x21-7E		; visible characters
WSP				=	SP | HTAB
*/

#endif /* BNF_HPP*/
