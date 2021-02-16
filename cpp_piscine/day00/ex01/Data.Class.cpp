/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:56:02 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/26 19:56:36 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.Class.hpp"

Data::Data()
{
}

Data::~Data()
{
}

std::string Data::GetFirstName()
{
	return Data::first_name;
}
std::string Data::GetLastName()
{
	return Data::last_name;
}
std::string Data::GetNickname()
{
	return Data::nickname;
}
std::string Data::GetLogin()
{
	return Data::login;
}
std::string Data::GetPostalAddress()
{
	return Data::postal_address;
}
std::string Data::GetEmailAddress()
{
	return Data::email_address;
}
std::string Data::GetPhoneNumber()
{
	return Data::phone_number;
}
std::string Data::GetBirthdayDate()
{
	return Data::birthday_date;
}
std::string Data::GetFavoriteMeal()
{
	return Data::favorite_meal;
}
std::string Data::GetUnderwearColor()
{
	return Data::underwear_color;
}
std::string Data::GetDarkestSecret()
{
	return Data::darkest_secret;
}

void	Data::SetBirthdayDate(std::string &str)
{
	Data::birthday_date = str;
}

void	Data::SetDarkestSecret(std::string &str)
{
	Data::darkest_secret = str;
}

void	Data::SetEmailAddress(std::string &str)
{
	Data::email_address = str;
}

void	Data::SetFavoriteMeal(std::string &str)
{
	Data::favorite_meal = str;
}

void	Data::SetFirstName(std::string &str)
{
	Data::first_name = str;
}

void	Data::SetLastName(std::string &str)
{
	Data::last_name = str;
}

void	Data::SetLogin(std::string &str)
{
	Data::login = str;
}

void	Data::SetNickname(std::string &str)
{
	Data::nickname = str;
}

void	Data::SetPhoneNumber(std::string &str)
{
	Data::phone_number = str;
}

void	Data::SetPostalAddress(std::string &str)
{
	Data::postal_address = str;
}

void	Data::SetUnderwearColor(std::string &str)
{
	Data::underwear_color = str;
}
