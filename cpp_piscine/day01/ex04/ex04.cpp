/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:45:43 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/28 20:01:17 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *po = &str;
	std::string &ref = str;
	//std::string &null_ref;
	std::string *null_po;

	std::cout << "Original: " << str << std::endl;
	std::cout << "Pointer: " << po << std::endl;
	std::cout << "*Pointer: " << *po << std::endl;
	std::cout << "Reference: " << ref << std::endl << std::endl;

	str += ", World";
	//po += ", World";
	ref += ", World";

	std::cout << "Original: " << str << std::endl;
	std::cout << "Pointer: " << po << std::endl;
	std::cout << "*Pointer: " << *po << std::endl;
	std::cout << "Reference: " << ref << std::endl << std::endl;

	//po += 48;
	ref += 48;
	
	std::cout << "Original: " << str << std::endl;
	std::cout << "Pointer: " << po << std::endl;
	std::cout << "*Pointer: " << *po << std::endl;
	std::cout << "Reference: " << ref << std::endl << std::endl;

	//null_ref = str;

	std::cout << "Clear pointer: " << null_po << std::endl;
	//std::cout << "Clear reference: " << null_ref << std::endl;

	return 0;
}
