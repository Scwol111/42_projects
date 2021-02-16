/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:44 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 15:27:04 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	// bureaucrat test
	{
		std::cout << "____BUREAUCRAT TEST_____" << std::endl;
		try
		{
			Bureaucrat bob("Bob");
			std::cout << bob;
			while (true)
				bob.incGrade();
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
		
		std::cout << bob << std::endl;
	}

	//form test
	{
		std::cout << "____FORM TEST_____" << std::endl;
		Bureaucrat bob("Bob");
		for (int i = 0; i < 50; i++)
			bob.incGrade();
		try
		{
			Form form("Justice", 0, 50);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Form form("Justice", 200, 50);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Form form("Justice", 50, 150);
			bob.signForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Form form("Not Justice", 50, 150);
			bob.signForm(form);
			bob.signForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Form form("InJustice", 50, 50);
			bob.signForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}

	return 0;
}
