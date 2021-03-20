#ifndef ContentType_HPP
#define ContentType_HPP

/*MIME-type
map<std::string, std::string> mimeType =    {{ "html", "text/html" },
                                            { "htm", "text/html" },
                                            { "stml", "text/html" },
       mimeType[html]                                     { "css", "text/css" },
                                            { "xml", "text/xml" },
                                            { "rss", "text/xml" },
                                            { "txt", "text/plain" },
                                            { "htc", "text/x-component" },
                                            { "mml", "text/mathml" },
                                            { "gif", "image/gif" },
                                            { "jpeg", "image/jpeg" },
                                            { "jpg", "image/jpeg" },
                                            { "png", "image/png" },
                                            { "ico", "image/x-icon" },
                                            { "jng", "image/x-jng" },
                                            { "wbmp", "image/vnd.wap.wbmp" },
                                            { "js", "application/x-javascript" },
                                            { "jar", "application/java-archive" },
                                            { "war", "application/java-archive" },
                                            { "ear", "application/java-archive" },
                                            { "hqx", "application/mac-binhex40" },
                                            { "pdf", "application/pdf" },
                                            { "cco", "application/x-cocoa" },
                                            { "jardiff", "application/x-java-archive-diff" },
                                            { "jnlp", "application/x-java-jnlp-file" },
                                            { "run", "application/x-makeself" },
                                            { "pl", "application/x-perl" },
                                            { "pm", "application/x-perl" },
                                            { "prc", "application/x-pilot" },
                                            { "pdb", "application/x-pilot" },
                                            { "rar", "application/x-rar-compressed" },
                                            { "rpm", "application/x-redhat-package-manager" },
                                            { "sea", "application/x-sea" },
                                            { "swf", "application/x-shockwave-flash" },
                                            { "sit", "application/x-stuffit" },
                                            { "tcl", "application/x-tcl" },
                                            { "tk", "application/x-tcl" },
                                            { "der", "application/x-x509-ca-cert" },
                                            { "pem", "application/x-x509-ca-cert" },
                                            { "crt", "application/x-x509-ca-cert" },
                                            { "xpi", "application/x-xpinstall" },
                                            { "zip", "application/zip" },
                                            { "deb", "application/octet-stream" },
                                            { "bin", "application/octet-stream" },
                                            { "exe", "application/octet-stream" },
                                            { "dll", "application/octet-stream" },
                                            { "dmg", "application/octet-stream" },
                                            { "eot", "application/octet-stream" },
                                            { "iso", "application/octet-stream" },
                                            { "img", "application/octet-stream" },
                                            { "msi", "application/octet-stream" },
                                            { "msp", "application/octet-stream" },
                                            { "msm", "application/octet-stream" },
                                            { "mp3", "audio/mpeg" },
                                            { "ra", "audio/x-realaudio" },
                                            { "mp3", "audio/mpeg" },
                                            { "mpeg", "video/mpeg" },
                                            { "mpg", "video/mpeg" },
                                            { "mov", "video/quicktime" },
                                            { "flv", "video/x-flv" },
                                            { "avi", "video/x-msvideo" },
                                            { "wmv", "video/x-ms-wmv" },
                                            { "asx", "video/x-ms-asf" },
                                            { "asf", "video/x-ms-asf" },
                                            { "mng", "video/x-mng" }};
*/

#include "Header.hpp"

class ContentType : public Header {
private:
	std::string	type;

public:
	ContentType(const std::string &view): Header("Content-Type"), type(view) {}
	~ContentType() {}

	void	parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Content-Type", view) && view.size() == 0) {
			type = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Content-Type field_value" << std::endl;
		}
	}
	std::string	construct_field_value() const {
		return type;
	}
	Header	*clone() const {
		return new ContentType(*this);
	}
	ViewData	get_type() {
		ViewData		view(type);
		BNF::ViewTree	tree = g_bnf.make_tree("Content-Type", view);
		return (tree.begin().get("mime-type").value());
	}
};


#endif /* ContentType_HPP */
