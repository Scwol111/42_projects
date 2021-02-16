/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:50:29 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/26 20:28:18 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Data.Class.hpp"

class Phonebook
{
private:
	static const int max = 8;
	Data data[max];
	int curr;
	void ShowOneUser(int idx);
	void OutputString(std::string str, bool last);
	void SetData(int add, std::string what);
	void megaphone(std::string &str);
	
public:
	Phonebook();
	~Phonebook();
	void AddUser();
	void ShowAllUsers();
	void StartWork();
};

#endif
