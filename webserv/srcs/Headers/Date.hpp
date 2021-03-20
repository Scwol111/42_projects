#ifndef Date_HPP
#define Date_HPP

#include <fstream>
#include <sys/time.h>

#include "Header.hpp"

class Date : public Header {
private:
	std::string m_date;
    	
public:
	Date(): Header("Date") {}
	~Date() {}

	void	parse_field_value(const ViewData &field_value) {
		ViewData	view(field_value);
		if (g_bnf.match("Date", view) && view.size() == 0) {
			m_date = field_value.to_string();
		} else {
			m_status_code = StatusCode::BadRequest;
			std::cerr << "Invalid Date field_value" << std::endl;
		}
	}
    std::string     construct_field_value() const {
	    
	    //Date: Wed, 21 Oct 2015 07:28:00 GMT

	    int i = 0;
		int w = 3;
		int array[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		std::string mon[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		struct timeval tv;
		std::string wek[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};



		gettimeofday(&tv, 0x0);
		long int sec = tv.tv_sec - 1609459200;
		int year = 2021 + sec / 31536000;

		int day = sec/86400 + 1 ;
		const std::string &week = wek[(w + day) % 7];
		while(day > array[i]) {
			day -= array[i];
			i++;
		}
		const std::string &months = mon[i];
		int hours = sec / 3600 % 24;
		int minutes = sec % 3600 / 60;
		int seconds = sec % 60;

		std::ostringstream	text;
		text << week << "," << (day < 10 ? " 0" : " ") << day << " " << months << " " << year << (hours < 10 ? " 0" : " ") << hours << (minutes < 10 ? ":0" : ":") << minutes << (seconds < 10 ? ":0" : ":") << seconds << " GMT";

		return text.str();
    }
	Header	*clone() const {
		return new Date(*this);
	}
};


#endif /* Date_HPP */ 
