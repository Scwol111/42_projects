/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:50:31 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/27 19:15:43 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.Class.hpp"

Phonebook::Phonebook()
{
	curr = 0;
	for (int i = 0; i < max; i++)
		data[i] = Data();
}

Phonebook::~Phonebook()
{	
}

void	Phonebook::SetData(int add, std::string what)
{
	std::string str;

	std::cout << what;
	std::getline(std::cin, str, '\n');
	while (str == "")
	{
		std::cout << "Wrong input, try another" << std::endl << what;
		std::getline(std::cin, str, '\n');
	}
	switch (add)
	{
		case 1:
			data[curr].SetFirstName(str);
			break;
		case 2:
			data[curr].SetLastName(str);
			break;
		case 3:
			data[curr].SetNickname(str);
			break;
		case 4:
			data[curr].SetLogin(str);
			break;
		case 5:
			data[curr].SetPostalAddress(str);
			break;
		case 6:
			data[curr].SetEmailAddress(str);
			break;
		case 7:
			data[curr].SetPhoneNumber(str);
			break;
		case 8:
			data[curr].SetBirthdayDate(str);
			break;
		case 9:
			data[curr].SetFavoriteMeal(str);
			break;
		case 10:
			data[curr].SetUnderwearColor(str);
			break;
		case 11:
			data[curr].SetDarkestSecret(str);
			break;
	}
}

void	Phonebook::AddUser()
{
	if (curr < max)
	{
		SetData(1, "First name: ");
		SetData(2, "Last name: ");
		SetData(3, "Nickname: ");
		SetData(4, "Login: ");
		SetData(5, "Postal address: ");
		SetData(6, "Email address: ");
		SetData(7, "Phone number: ");
		SetData(8, "Birthday date: ");
		SetData(9, "Favorite meal: ");
		SetData(10, "Underwear color: ");
		SetData(11, "Darkest secret: ");
		curr++;
	}
	else
		std::cout << "The phonebook is full, Sorry =(" << std::endl;
}

void	Phonebook::ShowAllUsers()
{
	std::cout << "#############################################" << std::endl;
	std::cout << "#   Index  |First name| Last name| Nickname #" << std::endl;
	for (int i = 0; i < curr; i++)
	{
		std::cout << "#----------+----------+----------+----------#" << std::endl;
		std::cout << '#';
		std::cout << "         " << i + 1 << '|';
		OutputString(data[i].GetFirstName(), false);
		OutputString(data[i].GetLastName(), false);
		OutputString(data[i].GetNickname(), true);
		std::cout << std::endl;
	}
	std::cout << "#############################################" << std::endl;
	if (curr > 0)
	{
		int idx;
		std::string str;
		std::cout << "For show full information about the user, enter his index" << std::endl << "Index: ";
		std::getline(std::cin, str, '\n');
		if (std::isdigit(str[0]))
			idx = std::stoi(str);
		else
			idx = -1;
		while (!(idx > 0 && idx <= curr))
		{
			std::cout << "Worng index, try another" << std::endl << "Index: ";
			std::getline(std::cin, str, '\n');
			if (std::isdigit(str[0]))
				idx = std::stoi(str);
			else
				idx = -1;
		}
		ShowOneUser(idx - 1);
	}
}

void	Phonebook::OutputString(std::string str, bool last)
{
	if (str.length() > 10)
	{
		for (int j = 0; j < 9; j++)
			std::cout << str[j];
		std::cout << '.';
	}
	else
	{
		for (unsigned long j = 0; j < 10 - str.length(); j++)
			std::cout << ' ';
		std::cout << str;
	}
	if (last)
		std::cout << "#";
	else
		std::cout << '|';
}

void	Phonebook::ShowOneUser(int idx)
{
	std::cout << "First name: " << data[idx].GetFirstName() << std::endl;
	std::cout << "Last name: " << data[idx].GetLastName() << std::endl;
	std::cout << "Nickname: " << data[idx].GetNickname() << std::endl;
	std::cout << "Login: " << data[idx].GetLogin() << std::endl;
	std::cout << "Postal address: " << data[idx].GetPostalAddress() << std::endl;
	std::cout << "Email address: " << data[idx].GetEmailAddress() << std::endl;
	std::cout << "Phone number: " << data[idx].GetPhoneNumber() << std::endl;
	std::cout << "Birthday date: " << data[idx].GetBirthdayDate() << std::endl;
	std::cout << "Favorite meal:" << data[idx].GetFavoriteMeal() << std::endl;
	std::cout << "Underwear color: " << data[idx].GetUnderwearColor() << std::endl;
	std::cout << "Darkest secret: " << data[idx].GetDarkestSecret() << std::endl;
}

void Phonebook::megaphone(std::string &str)
{
	std::string res;

	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
}

void	Phonebook::StartWork()
{
	std::string str;
	bool flag = true;

	while (flag)
	{
		std::cout << "Command: ";
		std::getline(std::cin, str, '\n');
		megaphone(str);
		if (str == "EXIT")
			flag = false;
		else if (str == "ADD")
			AddUser();
		else if (str == "SEARCH")
			ShowAllUsers();
		else
			std::cout << "Unknown command, please use some of this: ADD, SEARCH, EXIT" << std::endl;
	}
}
