#ifndef LastModified_HPP
#define LastModified_HPP


#include "Header.hpp"
#include <sys/stat.h>

class LastModified : public Header {
private:
	std::string m_last;
	std::string m_fileName;
	

public:
	LastModified(): Header("Last-Modified") {}
	~LastModified() {}
    
	LastModified(const std::string &fileName)
				: Header("Last-Modified"), m_fileName(fileName) {}

	void		parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Last-Modified", view) && view.size() == 0) {
			m_last = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Last-Modified Header" << std::endl;
		}    	
	}

    std::string     construct_field_value() const {

        struct tm tm_last;
        struct stat buffer;

        std::string last = "Wed, 23 Feb 2021 16:22:00 GMT";
    	last = last.substr(last.find(" ") + 1);
    	memset(&tm_last, 0, sizeof(struct tm));
    	strptime(last.c_str(), "%d %B %Y %H:%M:%S GMT", &tm_last);
   
    	if (stat(m_fileName.c_str(), &buffer) == 0 && !S_ISDIR(buffer.st_mode)) {

			long sec_file = buffer.st_mtimespec.tv_sec - 1609459200;

			{
				
				int i = 0;
				int w = 3;
				int array[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
				std::string mon[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
				std::string wek[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
							
				int year = 2021 + sec_file / 31536000;
				int day = sec_file/86400 + 1 ;
				std::string week = wek[(w + day) % 7];
				while(day > array[i]) {
					day -= array[i];
					i++;
				}
				std:: string months = mon[i];
				int hours = sec_file / 3600 % 24;
				int minutes = sec_file % 3600 / 60;
				int seconds = sec_file % 60;

				std::ostringstream	text;
				text << week << "," << (day < 10 ? " 0" : " ") << day << " " << months << " " << year << (hours < 10 ? " 0" : " ") << hours << (minutes < 10 ? ":0" : ":") << minutes << (seconds < 10 ? ":0" : ":") << seconds << " GMT";

				return text.str();
			}

    	} else {
    		return "";
    	}
    
    }

	
    Header		*clone() const {
	    return new LastModified(*this);
    }
};


#endif /* LastModified_HPP */ 
