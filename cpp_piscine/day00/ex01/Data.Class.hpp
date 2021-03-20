/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:56:04 by tclaudin          #+#    #+#             */
/*   Updated: 2021/02/24 19:28:26 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
#include <iostream>

class Data
{
private:

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date; 
	std::string favorite_meal;
	std::string underwear_color; 
	std::string darkest_secret;

public:
	Data();
	~Data();

	void SetFirstName(std::string &str);
	void SetLastName(std::string &str);
	void SetNickname(std::string &str);
	void SetLogin(std::string &str);
	void SetPostalAddress(std::string &str);
	void SetEmailAddress(std::string &str);
	void SetPhoneNumber(std::string &str);
	void SetBirthdayDate(std::string &str);
	void SetFavoriteMeal(std::string &str);
	void SetUnderwearColor(std::string &str);
	void SetDarkestSecret(std::string &str);

	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickname();
	std::string GetLogin();
	std::string GetPostalAddress();
	std::string GetEmailAddress();
	std::string GetPhoneNumber();
	std::string GetBirthdayDate();
	std::string GetFavoriteMeal();
	std::string GetUnderwearColor();
	std::string GetDarkestSecret();

};

#endif
