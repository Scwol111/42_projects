/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:44 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 15:40:40 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bob("Bob");
		std::cout << bob;
		while (true)
			bob.incGrade();
		//bob.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat bob("Bob");
		std::cout << bob;
		bob.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat bob("Bob");
	std::cout << bob;

	try
	{
		for (int i = 0; i < 50; i++)
			bob.incGrade();
		std::cout << "All fine" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << bob;

	return 0;
}
