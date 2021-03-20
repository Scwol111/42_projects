/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BNF.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:56:10 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/14 18:00:07 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BNF.hpp"
#include <climits>
#include <sstream>

BNF	g_bnf(

/* Header */
"header-field	= field-name ':' OWS field-value OWS\n"
"field-name		= token\n"
"field-value	= *field-content ; | obs-fold\n"
"field-content	= field-vchar [ 1*( SP | HTAB ) field-vchar [ SP | HTAB ] ]\n"
"field-vchar	= VCHAR ; | obs-text\n"
" ; obs-fold		= CRLF 1*( SP | HTAB ) ; obsolete by Section 3.2.4\n"

"request-line	=	method SP request-target SP HTTP-version CRLF\n"
"method         = token\n"
"request-target = origin-form\n"
"				| absolute-form\n"
"				| authority-form\n"
"				| asterisk-form\n"
"origin-form    = path-absolute [ '?' query ]\n"
"absolute-form  = absolute-URI\n"
"authority-form = authority\n"
"asterisk-form  = '*'\n"

"HTTP-Version      = `HTTP' '/' version-major '.' version-minor\n"
"version-major = 1*DIGIT\n"
"version-minor = 1*DIGIT\n"

"token          = 1*tchar\n"
"tchar          = QUOTE | %'!#$%&*+-.^_`|~' | DIGIT | ALPHA ; any VCHAR, except delimiters\n"
"quoted-string  = DQUOTE *( qdtext | quoted-pair ) DQUOTE\n"
"qdtext         = HTAB | SP |%x21 | %x23-5B | %x5D-7E | obs-text\n"
"obs-text       = %x80-FF\n"
"comment        = '(' *( ctext | quoted-pair | comment ) ')'\n"
"ctext          = HTAB | SP | %x21-27 | %x2A-5B | %x5D-7E | obs-text\n"
"quoted-pair    = '\\' ( HTAB | SP | VCHAR | obs-text )\n"

// "ALPHA			=	%x41-5A | %x61-7A	; A-Z / a-z\n"
// "DIGIT			=	%x30-39	; 0-9\n"
// "VCHAR			=	%x21-7E		; visible characters\n"
// "HTAB			=	%x09	; horizontal tab\n"
// "SP				=	%x20\n"
// "QUOTE			=	%x27 ; '\''\n"
// "DQUOTE			=	%x22 ; '\"'\n"
// "OWS = *( SP | HTAB )\n"

"Allow			= HTTP-method *(',' OWS HTTP-method)\n"
"HTTP-method	= `GET' | `POST' | `HEAD' | `PUT' | `DELETE' | `CONNECT' | `OPTIONS' | `TRACE' | `PATCH'\n"

"Accept-Charset		=	1#5charset-param\n"
"charset-param		=	charset-tag [';' OWS 'q=' precendence]\n"
"charset-tag		=	charset-name | '*'\n"
"charset-name		=	1*(ALPHA | DIGIT | '-') ; todo: check for actual rule for this\n"
"charset-subtype	=	1*ALPHA\n"

"Accept-Language	=	1#language-param\n"
"language-param		=	language-tag [';q=' precendence]\n"
"language-tag		=	language-type '-' language-subtype | language-type | '*'\n"
"language-type		=	1*ALPHA\n"
"language-subtype	=	1*ALPHA\n"
"precendence		=	'1.0' | '0.' 1*DIGIT\n"

"Content-Language	=	1#language-tag\n"

"realm       = 'realm' '=' realm-value\n"
"realm-value = quoted-string\n"

"Authorization		=	basic-authorization | digest-authorization ; | bearer-authorization\n"

"basic-authorization	= `Basic' OWS basic-credentials\n"
"basic-credentials	=	base64-user-pass\n"
"base64-user-pass	=	1*base64-charset\n"
"base64-charset		=	ALPHA | DIGIT | %'+/='\n"

"digest-authorization	= `Digest' OWS digest-response\n"
"digest-response	= 1#( username | realm | nonce | digest-uri | response |\n"
"					algorithm | cnonce | opaque | message-qop |\n"
"					nonce-count  | auth-param )\n"
"username			= 'username' '=' username-value\n"
"username-value		= quoted-string\n"
"digest-uri			= 'uri' '=' digest-uri-value\n"
"digest-uri-value	= 1*VCHAR ; request-uri   ; As specified by HTTP/1.1\n"
"message-qop		= 'qop' '=' qop-value\n"
"cnonce				= 'cnonce' '=' cnonce-value\n"
"cnonce-value		= nonce-value\n"
"nonce-count		= 'nc' '=' nc-value\n"
"nc-value			= 8LHEX\n"
"response			= 'response' '=' request-digest\n"
"request-digest		= DQUOTE 32LHEX DQUOTE\n"
"LHEX				= %'0123456789abcdef'\n"

"WWW-Authenticate	=	basic-challenge | digest-challenge ; | bearer-challenge\n"
"basic-challenge	=	`Basic' OWS realm\n"
"digest-challenge	=	1#( realm | domain | nonce | opaque | stale | algorithm | qop-options | auth-param )\n"
"domain				=	'domain' '=' DQUOTE URI-asd *(1*SP URI-asd) DQUOTE\n"
"URI-asd				=	1*VCHAR ; todo: absoluteURI | abs_path\n"
"nonce				=	'nonce' '=' nonce-value\n"
"nonce-value		=	quoted-string\n"
"opaque				=	'opaque' '=' quoted-string\n"
"stale				=	'stale' '=' ( 'true' | 'false' )\n"
"algorithm			=	'algorithm' '=' ( 'MD5' | 'MD5-sess' | token )\n"
"qop-options		=	'qop' '=' DQUOTE 1#qop-value DQUOTE\n"
"qop-value			=	'auth' | 'auth-int' | token\n"

"auth-param			=	1*VCHAR ; todo: implement\n"

"Content-Length		=	1*DIGIT\n"

"Content-Location	=	relative_path | absolute_path\n"
"relative_path		=	path_segment *( '/' path_segment) ['/']\n"
"absolute_path		=	'/' relative_path\n"
"path_segment		=	1*(VCHAR.!'/') ; todo: insert actual rule of URL path segment\n"

"mime-type			=	1*unreserved\n"
"mime-subtype		=	1*unreserved\n"
"mime-parameter		=	1*unreserved\n"
"mime-value			=	1*unreserved | quoted-string\n"
"Content-Type		=	mime-type '/' mime-subtype *( ';' OWS mime-parameter [ '=' mime-value ])\n"


"If-Modified-Since	=	day-name ', ' day ' ' month ' ' year hour ':' minute ':' second ' GMT'\n"
"day-name			=	'Mon' | 'Tue' | 'Wed' | 'Thu' | 'Fri' | 'Sat' | 'Sun'\n"
"day				=	%'012' DIGIT | '3' %'01'\n"
"month				=	'Jan' | 'Feb' | 'Mar' | 'Apr' | 'May' | 'Jun' | 'Jul' | 'Aug' | 'Sep' | 'Oct' | 'Nov' | 'Dec'\n"
"year				=	4DIGIT\n"
"hour				=	%'01' DIGIT | '2' %'0123' ; 10-23\n"
"minute				=	%'012345' DIGIT\n"
"second				=	%'012345' DIGIT\n"

"Transfer-Encoding	=	1#( 'chunked' | 'compress' | 'deflate' | 'gzip' | 'identity' )\n"

"Host				=	1*VCHAR\n"

"Status				=	status-code SP reason-phrase\n"
"status-code		=	3DIGIT\n"
"reason-phrase		=	*( HTAB | SP | VCHAR )\n"

"Expect				=	'100-continue'\n"

"User-Agent			=	1*VCHAR [OWS User-Agent]\n"

"Retry-After		=	1*VCHAR [OWS Retry-After]\n"

"Referer		=	1*VCHAR [OWS Referer]\n"

/* URI */


"reserved	= gen-delims | sub-delims\n"
"gen-delims	= %':/?#[]@'\n"
"sub-delims	= QUOTE | %'!$&()*+,;='\n"
"unreserved	= ALPHA | DIGIT | %'-._~'\n"
"pct-encoded = '%' HEXDIG HEXDIG\n"

"URI		= scheme ':' hier-part [ '?' query ] [ '#' fragment ]\n"
"hier-part	= '//' authority path-abempty\n"
"			| path-absolute\n"
"			| path-rootless\n"
"			| path-empty\n"

"scheme		= ALPHA *( ALPHA | DIGIT | %'+-.' )\n"
"authority	= [ userinfo '@' ] host1 [ ':' port ]\n"
"userinfo	= *( unreserved | pct-encoded | sub-delims | ':' )\n"
"host1		= IP-literal | IPv4address | reg-name\n"
"IP-literal	= '[' ( IPv6address | IPvFuture ) ']'\n"
"IPvFuture  = 'v' 1*HEXDIG '.' 1*( unreserved | sub-delims | ':' )\n"
"IPv6address =							 6( h16 ':' ) ls32\n"
"			|						'::' 5( h16 ':' ) ls32\n"
"			| [				  h16 ] '::' 4( h16 ':' ) ls32\n"
"			| [ *1( h16 ':' ) h16 ] '::' 3( h16 ':' ) ls32\n"
"			| [ *2( h16 ':' ) h16 ] '::' 2( h16 ':' ) ls32\n"
"			| [ *3( h16 ':' ) h16 ] '::'    h16 ':'   ls32\n"
"			| [ *4( h16 ':' ) h16 ] '::'			  ls32\n"
"			| [ *5( h16 ':' ) h16 ] '::'			  h16\n"
"			| [ *6( h16 ':' ) h16 ] '::'\n"
"ls32        = ( h16 ':' h16 ) | IPv4address\n"
"          ; least-significant 32 bits of address\n"
"h16         = 1*4HEXDIG\n"
"          ; 16 bits of address represented in hexadecimal\n"
"IPv4address	= dec-octet '.' dec-octet '.' dec-octet '.' dec-octet\n"
"dec-octet	= DIGIT                 ; 0-9\n"
"			| %x31-39 DIGIT         ; 10-99\n"
"			| '1' 2DIGIT            ; 100-199\n"
"			| '2' %x30-34 DIGIT     ; 200-249\n"
"			| '25' %x30-35          ; 250-255\n"
"reg-name	= *( unreserved | pct-encoded | sub-delims )\n"
"port		= *DIGIT\n"
"path-abempty	= *( '/' segment )\n"
"path-absolute	= '/' [ segment-nz *( '/' segment ) ]\n"
"path-noscheme	= segment-nz-nc *( '/' segment )\n"
"path-rootless	= segment-nz *( '/' segment )\n"
"path-empty		= !pchar\n"
"segment		= *pchar\n"
"segment-nz		= 1*pchar\n"
"segment-nz-nc	= 1*( unreserved | pct-encoded | sub-delims | '@' )\n"
"				; non-zero-length segment without any colon ':'\n"
"pchar			= unreserved | pct-encoded | sub-delims | %':@'\n"

"query       = *( pchar | %'/?' )\n"
"fragment    = *( pchar | '/' | '?' )\n"

"URI-reference = URI | relative-ref\n"

"relative-ref  = relative-part [ '?' query ] [ '#' fragment ]\n"
"relative-part = '//' authority path-abempty\n"
"				| path-absolute\n"
"				| path-noscheme\n"
"				| path-empty\n"

"absolute-URI  = scheme ':' hier-part [ '?' query ]\n"

"ALPHA			=	%x41-5A | %x61-7A	; A-Z / a-z\n"
"BIT				=	%'01'\n"
"CHAR			=	%x01-7F\n"
"CR				=	%x0D\n"
"CRLF			=	CR LF | LF ; non-standard CRLF\n"
"STD-CRLF		=	CR LF\n"
"CTL				=	%x00-1F | %x7F ; controls\n"
"DIGIT			=	%x30-39	; 0-9\n"
"DQUOTE			=	%x22 ; '\"'\n"
"QUOTE			=	%x27 ; '\''\n"
"BACKTICK		=	%d96 ; '`'\n"
"START_LITERAL	=	QUOTE | BACKTICK\n"
"HEXDIG			=	DIGIT | %'ABCDEF'\n"
"HTAB			=	%x09	; horizontal tab\n"
"LF				=	%x0A	; linefeed\n"
"LWSP			=	*(WSP | CRLF WSP)\n"
"OCTET			=	%x00-ff\n"
"SP				=	%x20\n"
"OWS			=	*( SP | HTAB )\n"
"VCHAR			=	%x21-7E		; visible characters\n"
"WSP				=	SP | HTAB\n"



/* chunked transfer encoding rfc7230 section 4.1 */
"chunked-body	= *chunk last-chunk trailer-part STD-CRLF\n"
"chunk			= chunk-header chunk-data STD-CRLF\n"
"chunk-header	= chunk-size [ chunk-ext ] STD-CRLF\n"
"chunk-size		= 1*HEXDIG\n"
"last-chunk		= 1*'0' [ chunk-ext ] STD-CRLF\n"
"chunk-data		= 1*OCTET ; will not work\n"

"chunk-ext      = *( ';' chunk-ext-name [ '=' chunk-ext-val ] )\n"
"chunk-ext-name = token\n"
"chunk-ext-val  = token | quoted-string\n"

"trailer-part   = *( header-field CRLF )\n"


	);



BNF::BNF(ViewData rulelist) {
	m_is_build_process = true;
	if (!parse_rulelist(rulelist)) {
		m_is_build_process = false;
		throw InvalidRuleList();
	}
	m_is_build_process = false;
}

std::string	BNF::Rule::Node::get_info() const {
	std::ostringstream	text;

	switch(type) {
		case RuleType: {
			if (rule_ref.is_anon) {
				text << rule_ref.bnf.m_anonymous_rules[rule_ref.index].content.to_string();
			} else {
				text << rule_ref.bnf.m_entries[rule_ref.index].name.to_string();
			}
		} break ;
		case Rule::Node::CharSeqType:
			text << '%';
		case TermType: {
			text << '\'' << term.to_string() << '\'';
		} break ;
		case Rule::Node::CharSeqCaseSensitiveType:
			text << '%';
			if (term.size() == 0) {
				text << "`'";
				break ;
			}
		case Rule::Node::TermCaseSensitiveType: {
			if (term.size() > 0) {
				text << '`' << term.to_string() << '\'';
			} else {
				text << "%x";
				for (size_t i = 0; i < range.size(); i += 1) {
					unsigned char	ch = range[i];
					if (i) {
						text << '.';
					}
					text << "0123456789abcdef"[(ch >> 4) & 0xF];
					text << "0123456789abcdef"[ch & 0xF];
				}
			}
		} break ;
		case Rule::Node::CharRangeType: {
			text << "%x";
			text << "0123456789abcdef"[(unsigned char)range[0] >> 4];
			text << "0123456789abcdef"[(unsigned char)range[0] & 0xF];
			text << '-';
			text << "0123456789abcdef"[(unsigned char)range[1] >> 4];
			text << "0123456789abcdef"[(unsigned char)range[1] & 0xF];
		} break ;
		default: break ;
	}
	return text.str();
}

std::string		BNF::Rule::Sequance::Point::get_prefix() const {
	std::ostringstream	result;

	if (is_combined) {
		result << '.';
	}
	if (is_negated) {
		result << '!';
	}
	if (min == max && min != 1) {
		result << min;
	} else if (min != 1 || max != 1) {
		if (min == 0 && max == 1 && node.rule_ref.is_anon) {
		} else {
			if (min > 0) {
				result << min;
			}
			result << (is_list ? '#' : '*');
			if (max < 0xFFFFFFFF) {
				result << max;
			}
		}
	}
	return result.str();
}

bool	BNF::Rule::Node::match(ViewData &view, ViewTree &tree) const {
	ViewData::Checkpoint	result(view, false, "Node::match!" + get_info());

	switch (type) {
		case RuleType: {
			result = rule_ref->match(view, tree);
		} break ;
		case CharSeqType: {
			for (size_t i = 0; i < term.size(); i += 1) {
				if (std::tolower(term[i]) == std::tolower(view[0])) {
					result = true;
					view.move_pointer();
					break ;
				}
			}
		} break ;
		case CharSeqCaseSensitiveType: {
			for (size_t i = 0; i < term.size(); i += 1) {
				if (term[i] == view[0]) {
					result = true;
					view.move_pointer();
					break ;
				}
			}
		} break ;
		case TermType: {
			if (term.size() > 0) {
				result = view.partial_caseins_equals(term);
				if (result) {
					view.move_pointer(term.size());
				}
			} else {
				result = view.size() == 0;
			}
		} break ;
		case TermCaseSensitiveType: {
			ViewData	iview(term);
			if (iview.size() == 0) {
				iview = ViewData(range);
			}
			result = view.partial_equals(iview);
			if (result) {
				view.move_pointer(iview.size());
			}
		} break ;
		case CharRangeType: {
			if ((result = view.size() > 0 &&
					(unsigned char)view[0] >= (unsigned char)range[0] &&
					(unsigned char)view[0] <= (unsigned char)range[1])) {
				view.move_pointer();
			}
		} break ;
		default: break ;
	}
	return (result);
}

bool	BNF::Rule::Sequance::match(ViewData &view, ViewTree &tree) const {
	ViewData::Checkpoint	result(view, true, "Sequance::match");

	for (size_t i_point = 0; result && i_point < points.size(); i_point += 1) {
		bool					first_viewed = false;
		ViewData				start_view(view);
		ViewData				end_view(view);

		do {
			const Point	&point = points[i_point];

			view = start_view;

			{
				tree.nodes.push_back(ViewTree::Node());
				ViewTree::Node	&node = tree.nodes.back();
				node.name = point.get_prefix() + point.node.get_info();
				node.parent = tree.stack.top();
				tree.nodes[node.parent].childs.push_back(tree.nodes.size() - 1);
				tree.stack.push(tree.nodes.size() - 1);

				unsigned		counter = 0;
				while (counter < point.max) {
					if (!(result = point.node.match(view, tree))) {
						break ;
					}
					counter += 1;
					if (counter < point.max && point.is_list && !parse_WSP_COMMA_WSP(view)) {
						break ;
					}
				}
				if (counter >= point.min) {
					result = true;
				}
			}

			ViewTree::Node	&node = tree.nodes[tree.stack.top()];
			tree.stack.pop();
			if (point.is_negated) {
				result = !result;
			}

			if (!first_viewed) {
				first_viewed = true;
				end_view = view;
			}

			node.value = ViewData(start_view).truncate_to(view.get_position());

		} while (result && i_point + 1 < points.size() && points[i_point + 1].is_combined && ++i_point);

		view = end_view;

	}
	return (result);
}

bool	BNF::Rule::match(ViewData &view, ViewTree &tree) const {
	ViewData::Checkpoint	result(view, true, "Rule::match");

	for (size_t seq_i = 0; seq_i < seqs.size(); seq_i += 1) {
		const Sequance	&seq = seqs[seq_i];
		ViewTree::Checkpoint	checkpoint(tree);
		if ((checkpoint = result = seq.match(view, tree))) {
			break ;
		}
	}
	return (result);
}

BNF::ViewTree		BNF::make_tree(const std::string &rulename, ViewData &view) const {
	ViewTree	tree;
	const Rule	*rule;
	bool		result = false;

	rule = find_rule(rulename);
	if (rule) {
		tree.nodes.push_back(ViewTree::Node());
		tree.nodes.back().name = rulename;
		ViewData	start_view = view;
		tree.stack.push(0);
		result = rule->match(view, tree);
		tree.stack.pop();
		if (!result) {
			tree.nodes.clear();
		} else {
			tree.nodes[0].value = ViewData(start_view).truncate_to(view.get_position()).to_string();
		}
	}
	return (tree);
}

bool				BNF::match(const std::string &rulename, ViewData &view) const {
	return (!make_tree(rulename, view).empty());
}

bool		BNF::ViewTree::Iter::next() {
	bool	result = false;

	if (parent && current + 1 < static_cast<int>(parent->childs.size())) {
		current += 1;
		result = true;
	}
	return (result);
}

bool		BNF::ViewTree::Iter::prev() {
	bool	result = false;

	if (parent && current > 0 && parent->childs.size() > 0) {
		current -= 1;
		result = true;
	}
	return (result);
}

bool		BNF::ViewTree::Iter::down() {
	bool	result = false;

	if (parent && current < static_cast<int>(parent->childs.size()) && tree.nodes[parent->childs[current]].childs.size() > 0) {
		parent = &tree.nodes[parent->childs[current]];
		currents.push(current);
		current = 0;
		result = true;
	}
	return (result);
}

bool		BNF::ViewTree::Iter::up() {
	bool	result = false;

	if (parent && !currents.empty()) {
		parent = &tree.nodes[parent->parent];
		current = currents.top();
		currents.pop();
		result = true;
	}
	return (result);
}

BNF::ViewTree::Iter	BNF::ViewTree::Iter::get(const ViewData &name, int index) const {
	Iter	it = *this;
	bool	found = false;
	int		appearence = 0;

	if (parent) do {
		ViewData	iview(it->name);
		if (iview.size() == name.size() && iview.partial_caseins_equals(name)) {
			if (appearence == index) {
				found = true;
				break ;
			}
			appearence += 1;
		}
	} while (it.next());
	return (found ? Iter(tree, it.get_current()) : Iter(tree, NULL));
}

void			BNF::ViewTree::Iter::unlink() {
	if (parent) {
		const_cast<Node *>(parent)->childs.erase(parent->childs.begin() + current);
		*this = Iter(tree, parent);
	}
}

const std::string	&BNF::ViewTree::Iter::name() const {
	return parent ? parent->name : tree.emptystring;
}

const ViewData	&BNF::ViewTree::Iter::value() const {
	return parent ? parent->value : tree.emptyview;
}

const BNF::ViewTree::Node	*BNF::ViewTree::Iter::get_current() const {
	return parent ? &tree.nodes[parent->childs[current]] : NULL;
}

size_t			BNF::ViewTree::Iter::get_childs_count() const {
	return parent ? parent->childs.size() : 0;
}

const BNF::ViewTree::Node	*BNF::ViewTree::Iter::operator->() const {
	return get_current();
}

std::string	BNF::ViewTree::to_string() const {
	std::ostringstream	text;
	std::string			indent;

	if (!empty()) {
		int		until_nl = ViewData(nodes[0].value).count_chars_until('\n');
		text << nodes[0].name << " @" << (until_nl >= 0 ? ViewData(nodes[0].value, until_nl).to_string() : nodes[0].value) << (until_nl >= 0 ? "~~~" : "@") << std::endl;
		indent += '\t';
		Iter	it = begin();
		bool	ok = false;
		do {
			do {
				do {
					until_nl = ViewData(it->value).count_chars_until('\n');
					text << indent << it->name << " @" << (until_nl >= 0 ? ViewData(it->value, until_nl).to_string() : it->value) << (until_nl >= 0 ? "~~~" : "@") << std::endl;
					if ((ok = it.down())) {
						indent += '\t';
					}
				} while (ok);
				ok = it.next();
			} while (ok);
			bool	iok;
			do {
				if ((ok = iok = it.up())) {
					indent.pop_back();
					iok = !it.next();
					ok = !iok;
				}
			} while (iok);
		} while (ok);
	}
	return text.str();
}

const BNF::Rule		*BNF::find_rule(const std::string &name) const {
	int		index = 0;
	const Rule	*rule = 0;

	for (; index < static_cast<int>(m_entries.size()); index += 1) {
		if (name.size() == m_entries[index].name.size() && 
			ViewData(name).partial_caseins_equals(m_entries[index].name)) {
			break ;
		}
	}
	if (index < static_cast<int>(m_entries.size())) {
		rule = &m_entries[index].rule;
	}
	return (rule);
}

int					BNF::find_rule_index(const ViewData &name) {
	int		index = 0;

	for (; index < static_cast<int>(m_entries.size()); index += 1) {
		if (name.size() == m_entries[index].name.size() && 
			name.partial_caseins_equals(m_entries[index].name)) {
			break ;
		}
	}
	if (index < static_cast<int>(m_entries.size())) {
		if (!m_entries[index].parsed) {
			ViewData	view(m_entries[index].elements);
			if (!m_entries[index].in_process && !parse_elements(view, index)) {
				index = -1;
			}
		}
	} else {
		index = -1;
	}
	return (index);
}

std::string		BNF::to_string() const {
	std::ostringstream	text;

	for (size_t i_entry = 0; i_entry < m_entries.size(); i_entry += 1) {
		const RuleEntry	&entry = m_entries[i_entry];
		if (entry.parsed) {
			text << entry.name.to_string() << " = ";
			text << rule_to_string(entry.rule);
			text << "\n";
		}
	}
	return text.str();
}

std::string		BNF::rule_to_string(const Rule &rule) const {
	std::ostringstream	text;

	for (size_t i_seq = 0; i_seq < rule.seqs.size(); i_seq += 1) {
		const Rule::Sequance	&seq = rule.seqs[i_seq];

		if (i_seq) {
			text << " | ";
		}
		for (size_t i_point = 0; i_point < seq.points.size(); i_point += 1) {
			const Rule::Sequance::Point	&point = seq.points[i_point];
			bool	optional = point.min == 0 && point.max == 1 && point.node.rule_ref.is_anon;

			if (i_point && !point.is_combined) {
				text << ' ';
			}
			text << point.get_prefix();
			const Rule::Node	&node = point.node;
			switch (node.type) {
				case Rule::Node::RuleType: {
					if (node.rule_ref.is_anon) {
						text << (optional ? '[' : '(') << ' ';
						text << rule_to_string(**node.rule_ref);
						text << ' ' << (optional ? ']' : ')');
					} else {
						text << m_entries[node.rule_ref.index].name.to_string();
					}
				} break ;
				case Rule::Node::CharSeqType:
					text << '%';
				case Rule::Node::TermType: {
					text << '\'' << node.term.to_string() << '\'';
				} break;
				case Rule::Node::CharSeqCaseSensitiveType:
					text << '%';
					if (node.term.size() == 0) {
						text << "`'";
						break ;
					}
				case Rule::Node::TermCaseSensitiveType: {
					if (node.term.size() > 0) {
						text << '`' << node.term.to_string() << '\'';
					} else {
						text << "%x";
						for (size_t i = 0; i < node.range.size(); i += 1) {
							unsigned char	ch = node.range[i];
							if (i) {
								text << '.';
							}
							text << "0123456789abcdef"[(ch >> 4) & 0xF];
							text << "0123456789abcdef"[ch & 0xF];
						}
					}
				} break ;
				case Rule::Node::CharRangeType: {
					text << "%x";
					text << "0123456789abcdef"[(unsigned char)node.range[0] >> 4];
					text << "0123456789abcdef"[(unsigned char)node.range[0] & 0xF];
					text << '-';
					text << "0123456789abcdef"[(unsigned char)node.range[1] >> 4];
					text << "0123456789abcdef"[(unsigned char)node.range[1] & 0xF];
				} break ;
				default: break ;
			}
		}
	}
	return text.str();
}

ViewData::Checkpoint	BNF::parse_rulelist(ViewData &view) {
	ViewData::Checkpoint	result(view, true, "parse_rulelist");
	// RuleEntry				*entry = 0;

	if (parse_c_wsp(view)) {
		while (parse_c_wsp(view));
		result = parse_c_nl(view);
	}
	while (result && view.size() > 0) {
		ViewData				rulename(view);
		bool					additive = false;
		if ((result = parse_rulename(view).frame_to(rulename) && parse_defined_as(view, additive))) {
			std::vector<RuleEntry>::iterator	it = std::find(m_entries.begin(), m_entries.end(), rulename);
			ViewData::Checkpoint				elements(view, true, "parse_rulelist::elements");
			size_t								end_pos = view.get_position();
			while (view.size() > 0 && !(parse_c_nl(view).position_to(end_pos) && !is_WSP(view[0]))) {
				if (is_START_LITERAL(view[0])) do {
					view.move_pointer();
				} while(view.size() > 0 && view[0] != '\'');
				view.move_pointer();
			}
			if (it == m_entries.end()) {
				m_entries.push_back(RuleEntry(rulename));
				it = m_entries.end() - 1;
			} else if (!additive) {
				result = false;
			}
			if (result && !additive) {
				it->elements = elements.get_frame_until(end_pos);
			}
		} else break ;
	}
#if 1
	if (result) {
		result.rewind();
		while (result && view.size() > 0 && (result = parse_rule(view))) {
			bool	ok;
			do {
				ViewData::Checkpoint	iresult(view, false, "parse_rulelist::iresult");
				while (parse_c_wsp(view));
				ok = iresult = parse_c_nl(view);
			} while (ok);
		}
	}
#else
	{
		for (size_t i = 0; i < m_entries.size(); i += 1) {
			std::cout << m_entries[i].name.to_string() << "!!" << m_entries[i].elements.to_string() << "!!" << std::endl;
		}
	}
#endif
	return (result);
}

ViewData::Checkpoint	BNF::parse_rule(ViewData &view) {
	ViewData::Checkpoint	result(view, false, "parse_rule");
	ViewData				iview(view);

	if ((result = parse_rulename(view).frame_to(iview))) {
		bool	additive = false;
		if ((result = parse_defined_as(view, additive))) {
			size_t	i_entry = 0;
			for (; i_entry < m_entries.size(); i_entry += 1) {
				if (m_entries[i_entry].name.size() == iview.size() &&
					ViewData(m_entries[i_entry].name).partial_caseins_equals(iview)) {
					break ;
				}
			}
			if (i_entry >= m_entries.size()) {
				result = false;
			} else {
				if (additive && !m_entries[i_entry].parsed) {
					result = false;
				} else if (!additive && m_entries[i_entry].parsed) {
					view.move_pointer(m_entries[i_entry].elements.size());
					result = true;
				} else {
					result = parse_elements(view, i_entry).frame_to(iview) && parse_c_nl(view);
					if (result && !additive) {
						m_entries[i_entry].elements = iview;
					}
				}
			}
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_rulename(ViewData &view) {
	ViewData::Checkpoint	result(view, false, "parse_rulename");

	if (is_ALPHA(view[0])) {
		view.move_pointer();
		while (is_ALPHA(view[0]) || is_DIGIT(view[0]) || view[0] == '-' || view[0] == '_') {
			view.move_pointer();
		}
		result = true;
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_defined_as(ViewData &view, bool &additive) {
	ViewData::Checkpoint	result(view, false, "parse_defined_as");

	while (parse_c_wsp(view));
	result = true;
	if (view.partial_equals("=|")) {
		additive = true;
		view.move_pointer(2);
	} else if (view[0] == '=') {
		view.move_pointer();
	} else {
		result = false;
	}
	while (result && parse_c_wsp(view));
	return (result);
}

ViewData::Checkpoint	BNF::parse_elements(ViewData &view, size_t i_entry) {
	ViewData::Checkpoint	result(view, false, "parse_elements");

	if (!m_entries[i_entry].in_process) {
		m_entries[i_entry].in_process = true;
		Rule::Ref	ref(*this, i_entry, false);
		result = parse_alternation(view, ref);
		m_entries[i_entry].in_process = false;
		if (result) {
			m_entries[i_entry].parsed = true;
			while (parse_c_wsp(view)) ;
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_c_wsp(ViewData &view) {
	ViewData::Checkpoint	result(view, false, "parse_c_wsp");

	if (is_WSP(view[0])) {
		view.move_pointer();
		result = true;
	} else if (parse_c_nl(view) && is_WSP(view[0])) {
		view.move_pointer();
		result = true;
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_crlf(ViewData &view) {
	ViewData::Checkpoint	result(view, false, "parse_crlf");

	if ((is_CR(view[0]) && is_LF(view[1])) || is_LF(view[0])) {
		view.move_pointer(1 + !is_LF(view[0]));
		result = true;
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_c_nl(ViewData &view) {
	ViewData::Checkpoint	result(view, false, "parse_c_nl");

	if ((result = parse_crlf(view))) {
	} else if ((result = parse_comment(view))) {
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_comment(ViewData &view) {
	ViewData::Checkpoint	result(view, false, "parse_comment");

	if (view[0] == ';') {
		view.move_pointer();
		while (is_WSP(view[0]) || is_VCHAR(view[0])) {
			view.move_pointer();
		}
		result = parse_crlf(view);
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_alternation(ViewData &view, Rule::Ref &rule_ref) {
	ViewData::Checkpoint	result(view, false, "parse_alternation");

	Rule::Sequance	seq;
	result = parse_concatenation(view, seq);
	if (result) {
		bool	ok;

		rule_ref->seqs.push_back(seq);
		do {
			ViewData::Checkpoint	iresult(view, false, "parse_alternation::iresult");
			while (parse_c_wsp(view)) ;
			if ((ok = (view[0] == '|'))) {
				view.move_pointer();
				while (parse_c_wsp(view)) ;
				Rule::Sequance	iseq;
				if ((ok = iresult = parse_concatenation(view, iseq))) {
					rule_ref->seqs.push_back(iseq);
				}
			}
		} while (ok);
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_concatenation(ViewData &view, Rule::Sequance &seq) {
	ViewData::Checkpoint	result(view, false, "parse_concatenation");

	result = parse_combination(view, seq);
	if (result) {
		bool	ok;

		do {
			ViewData::Checkpoint	iresult(view, false, "parse_concatenation::iresult");

			ok = false;
			iresult = parse_c_wsp(view);
			if (iresult) {
				while (parse_c_wsp(view)) ;
				if (view[0] != '|') {
					ok = iresult = parse_combination(view, seq);
				}
			}
		} while (ok);
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_combination(ViewData &view, Rule::Sequance &seq) {
	ViewData::Checkpoint	result(view, false, "parse_combination");

	Rule::Sequance::Point	point(*this);
	result = parse_repetition(view, point);
	if (result) {
		bool	ok;

		seq.points.push_back(point);
		do {
			ViewData::Checkpoint	iresult(view, false, "parse_combination::iresult");

			ok = false;
			if ((iresult = view[0] == '.')) {
				view.move_pointer();
				Rule::Sequance::Point	ipoint(*this);
				ipoint.is_combined = true;
				if ((ok = iresult = parse_repetition(view, ipoint))) {
					seq.points.push_back(ipoint);
				}
			}
		} while (ok);
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_repetition(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_repetition");

	if (view[0] == '!') {
		view.move_pointer();
		point.is_negated = true;
	}
	parse_repeat(view, point);
	result = parse_element(view, point);
	return (result);
}

ViewData::Checkpoint	BNF::parse_repeat(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_repeat");
	// unsigned				value = (unsigned) -1;
	bool					first_parsed = false;

	result = true;
	if (is_DIGIT(view[0])) {
		first_parsed = result = parse_unsigned(view, point.min);
	}
	if (result) {
		point.is_list = (view[0] == '#');
		if (view[0] == '*' || point.is_list) {
			view.move_pointer();
			if (!first_parsed) {
				point.min = 0;
			}
			if (is_DIGIT(view[0])) {
				result = parse_unsigned(view, point.max);
			} else {
				point.max = 0xFFFFFFFF;
			}
		} else if (first_parsed) {
			point.max = point.min;
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_element(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_element");
	ViewData				iview(view);

	if (parse_rulename(view).frame_to(iview)) {
		int		rule = find_rule_index(iview);
		if (rule >= 0) {
			result = true;
			point.node = Rule::Node(Rule::Ref(*this, (size_t)rule));
		} else {
			if (m_is_build_process) {
				throw RuleNotFound("Cannot find the rule: " + iview.to_string());
			}
		}
	} else if ((result = parse_group_option(view, point))) {
	} else if ((result = parse_char_val(view, point))) {
	} else if ((result = parse_num_val(view, point))) {
	} else if ((result = parse_prose_val(view, point))) {
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_group_option(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_group");
	char	type[2] = {'(', ')'};

	if (view[0] == '[') {
		type[0] = '[';
		type[1] = ']';
	}
	if (view[0] == type[0]) {
		view.move_pointer();
		while (parse_c_wsp(view)) ;
		int		parant_count = 1;
		size_t	end_pos = 0;
		while (view[end_pos] && parant_count > 0) {
			if (is_START_LITERAL(view[end_pos])) do {
				end_pos += 1;
			} while(view[end_pos] && view[end_pos] != '\'');
			parant_count += (view[end_pos] == type[0]);
			parant_count -= (view[end_pos] == type[1]);
			end_pos += 1;
		}
		if (parant_count == 0) {
			m_anonymous_rules.push_back(AnonRuleEntry(""));
			Rule::Ref	rule_ref(*this, m_anonymous_rules.size() - 1, true);
			ViewData	iview(view, end_pos - 1);
			if ((result = parse_alternation(iview, rule_ref))) {
				view.restore_position(iview.get_position());
				while (parse_c_wsp(view)) ;
				if ((result = (view[0] == type[1]))) {
					view.move_pointer();
					point.node = Rule::Node(rule_ref);
					result.frame_to(m_anonymous_rules[rule_ref.index].content);
					if (type[0] == '[') {
						point.min = 0;
						point.max = 1;
					}
				} else {
					m_anonymous_rules.pop_back();
				}
			} else {
				m_anonymous_rules.pop_back();
			}
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_char_val(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_char_val");
	bool	is_casesens = is_BACKTICK(view[0]);

	if (is_QUOTE(view[0]) || is_BACKTICK(view[0])) {
		view.move_pointer();
		ViewData::Checkpoint	literal(view, true, "parse_char_val::literal");
		while (((view[0] >= 0x20 && view[0] <= 0x26) || (view[0] >= 0x28 && view[0] <= 0x7E))) {
			view.move_pointer();
		}
		if (is_QUOTE(view[0])) {
			point.node = Rule::Node(*this, literal.get_frame());
			if (is_casesens) {
				point.node.type = Rule::Node::TermCaseSensitiveType;
			}
			view.move_pointer();
			result = true;
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_num_val(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_num_val");

	if (view[0] == '%') {
		view.move_pointer();
		if ((result = parse_bin_val(view, point))) {
		} else if ((result = parse_dec_val(view, point))) {
		} else if ((result = parse_hex_val(view, point))) {
		} else if ((result = parse_char_val(view, point))) {
			if (point.node.type == Rule::Node::TermCaseSensitiveType) {
				point.node.type = Rule::Node::CharSeqCaseSensitiveType;
			} else {
				point.node.type = Rule::Node::CharSeqType;
			}
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_bin_val(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_bin_val");

	if (view[0] == 'b' && is_BIT(view[1])) {
		unsigned char	byte;
		std::string		term;

		view.move_pointer();
		if ((result = parse_bin_byte(view, byte))) {
			if (view[0] == '-') {
				unsigned char	rbyte;
				view.move_pointer();
				if ((result = parse_bin_byte(view, rbyte))) {
					point.node = Rule::Node(*this, (char)byte, (char)rbyte);
				}
			} else do {
				term += (char)byte;
				if (view[0] == '.' && is_BIT(view[1])) {
					view.move_pointer();
				} else {
					point.node = Rule::Node(*this, term);
					break ;
				}
			} while ((result = parse_bin_byte(view, byte)));
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_dec_val(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_dec_val");

	if (view[0] == 'd' && is_DIGIT(view[1])) {
		unsigned char	byte;
		std::string		term;

		view.move_pointer();
		if ((result = parse_dec_byte(view, byte))) {
			if (view[0] == '-') {
				unsigned char	rbyte;
				view.move_pointer();
				if ((result = parse_dec_byte(view, rbyte))) {
					point.node = Rule::Node(*this, (char)byte, (char)rbyte);
				}
			} else do {
				term += (char)byte;
				if (view[0] == '.' && is_DIGIT(view[1])) {
					view.move_pointer();
				} else {
					point.node = Rule::Node(*this, term);
					break ;
				}
			} while ((result = parse_dec_byte(view, byte)));
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_hex_val(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_hex_val");

	if (view[0] == 'x' && is_HEXDIG(view[1])) {
		unsigned char	byte;
		std::string		term;

		view.move_pointer();
		if ((result = parse_hex_byte(view, byte))) {
			if (view[0] == '-') {
				unsigned char	rbyte;
				view.move_pointer();
				if ((result = parse_hex_byte(view, rbyte))) {
					point.node = Rule::Node(*this, (char)byte, (char)rbyte);
				}
			} else do {
				term += (char)byte;
				if (view[0] == '.' && is_HEXDIG(view[1])) {
					view.move_pointer();
				} else {
					point.node = Rule::Node(*this, term);
					break ;
				}
			} while ((result = parse_hex_byte(view, byte)));
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_prose_val(ViewData &view, Rule::Sequance::Point &point) {
	ViewData::Checkpoint	result(view, false, "parse_prose_val");

	static_cast<void>(point);
	if (view[0] == '<') {
		view.move_pointer();
		while ((view[0] >= 0x20 && view[0] <= 0x3D) || (view[0] >= 0x3F && view[0] <= 0x7E)) {
			view.move_pointer();
		}
		if (view[0] == '>') {
			view.move_pointer();
			result = true;
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_unsigned(ViewData &view, unsigned &value) {
	ViewData::Checkpoint	result(view, false, "parse_unsigned");

	if (is_DIGIT(view[0])) {
		result = true;
		unsigned long long lvalue = 0;
		while (result.distance() < 10 && is_DIGIT(view[0])) {
			lvalue *= 10;
			lvalue += view[0] - '0';
			view.move_pointer();
		}
		if (is_DIGIT(view[0]) || lvalue <= UINT_MAX) {
			value = lvalue;
		} else {
			result = false;
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_bin_byte(ViewData &view, unsigned char &value) {
	ViewData::Checkpoint	result(view, false, "parse_bin_byte");

	if (is_BIT(view[0])) {
		result = true;
		unsigned lvalue = 0;
		while (result.distance() < 8 && is_BIT(view[0])) {
			lvalue *= 2;
			lvalue += view[0] - '0';
			view.move_pointer();
		}
		if (is_BIT(view[0]) || lvalue <= UCHAR_MAX) {
			value = lvalue;
		} else {
			result = false;
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_dec_byte(ViewData &view, unsigned char &value) {
	ViewData::Checkpoint	result(view, false, "parse_dec_byte");

	if (is_DIGIT(view[0])) {
		result = true;
		unsigned lvalue = 0;
		while (result.distance() < 3 && is_DIGIT(view[0])) {
			lvalue *= 10;
			lvalue += view[0] - '0';
			view.move_pointer();
		}
		if (is_DIGIT(view[0]) || lvalue <= UCHAR_MAX) {
			value = lvalue;
		} else {
			result = false;
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_hex_byte(ViewData &view, unsigned char &value) {
	ViewData::Checkpoint	result(view, false, "parse_hex_byte");

	if (is_HEXDIG(view[0])) {
		result = true;
		unsigned lvalue = 0;
		while (result.distance() < 2 && is_HEXDIG(view[0])) {
			lvalue *= 16;
			lvalue += is_DIGIT(view[0]) ? view[0] - '0' : (view[0] >= 'A' && view[0] <= 'F' ? view[0] - 'A' : view[0] - 'a') + 10;
			view.move_pointer();
		}
		if (is_HEXDIG(view[0]) || lvalue <= UCHAR_MAX) {
			value = lvalue;
		} else {
			result = false;
		}
	}
	return (result);
}

ViewData::Checkpoint	BNF::parse_WSP_COMMA_WSP(ViewData &view) {
	ViewData::Checkpoint	result(view, false, "parse_WSP_COMMA_WSP");

	while (is_WSP(view[0])) {
		view.move_pointer();
	}
	if (view[0] == ',') {
		view.move_pointer();
		while (is_WSP(view[0])) {
			view.move_pointer();
		}
		result = true;
	}
	return (result);
}

bool	BNF::is_ALPHA(char c) {
	return ((c >= 0x41 && c <= 0x5A) || (c >= 0x61 && c <= 0x7A));
}

bool	BNF::is_BIT(char c) {
	return (c == '0' || c == '1');
}

bool	BNF::is_CHAR(char c) {
	return (c >= 0x01 && c <= 0x7F);
}

bool	BNF::is_CR(char c) {
	return (c == 0x0D);
}

bool	BNF::is_LF(char c) {
	return (c == 0x0A);
}

bool	BNF::is_CTL(char c) {
	return (c >= 0x00 && c <= 0x1F);
}

bool	BNF::is_DIGIT(char c) {
	return (c >= 0x30 && c <= 0x39);
}

bool	BNF::is_QUOTE(char c) {
	return (c == 0x27);
}

bool	BNF::is_DQUOTE(char c) {
	return (c == 0x22);
}

bool	BNF::is_BACKTICK(char c) {
	return (c == 96);
}

bool	BNF::is_START_LITERAL(char c) {
	return (is_QUOTE(c) || is_BACKTICK(c));
}

bool	BNF::is_HEXDIG(char c) {
	return (is_DIGIT(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

bool	BNF::is_HTAB(char c) {
	return (c == 0x09);
}

bool	BNF::is_OCTET(char c) {
	return ((unsigned char)c >= 0x00 && (unsigned char)c <= 0xFF);
}

bool	BNF::is_SP(char c) {
	return (c == 0x20);
}

bool	BNF::is_VCHAR(char c) {
	return (c >= 0x21 && c <= 0x7E);
}

bool	BNF::is_WSP(char c) {
	return (is_SP(c) || is_HTAB(c));
}

