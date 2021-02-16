/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:44 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 18:20:51 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// // bureaucrat test
	// {
	// 	std::cout << "____BUREAUCRAT TEST_____" << std::endl;
	// 	try
	// 	{
	// 		Bureaucrat bob("Bob");
	// 		std::cout << bob;
	// 		while (true)
	// 			bob.incGrade();
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}

	// 	try
	// 	{
	// 		Bureaucrat bob("Bob");
	// 		std::cout << bob;
	// 		bob.decGrade();
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}

	// 	Bureaucrat bob("Bob");
	// 	std::cout << bob;

	// 	try
	// 	{
	// 		for (int i = 0; i < 50; i++)
	// 			bob.incGrade();
	// 		std::cout << "All fine" << std::endl;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
		
	// 	std::cout << bob << std::endl;
	// }

	// //form test
	// {
	// 	std::cout << "____FORM TEST_____" << std::endl;
	// 	Bureaucrat bob("Bob");
	// 	for (int i = 0; i < 50; i++)
	// 		bob.incGrade();
	// 	try
	// 	{
	// 		Form form("Justice", 0, 50);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// 	try
	// 	{
	// 		Form form("Justice", 200, 50);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// 	try
	// 	{
	// 		Form form("Justice", 50, 150);
	// 		bob.signForm(form);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// 	try
	// 	{
	// 		Form form("Not Justice", 50, 150);
	// 		bob.signForm(form);
	// 		bob.signForm(form);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// 	try
	// 	{
	// 		Form form("InJustice", 50, 50);
	// 		bob.signForm(form);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;
	// }

	//new form test
	{
		std::cout << "____NEW FORM TEST_____" << std::endl;

		std::srand(std::time(NULL));

		try
		{
			std::cout << std::endl << "____PRESIDENTAL PARDON FORM TEST____" << std::endl;
			Bureaucrat bob("Bob");
			PresidentialPardonForm form;
			std::cout << bob;
			bob.executeForm(form);
			bob.signForm(form);
			for (int i = 0; i < 125; i++)
				bob.incGrade();
			bob.signForm(form);
			bob.executeForm(form);
			for (int i = 0; i < 20; i++)
				bob.incGrade();
			bob.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			std::cout << std::endl << "____ROBOTOMY REQUEST FORM TEST____" << std::endl;
			Bureaucrat jim("Jim");
			RobotomyRequestForm form;
			std::cout << jim;
			jim.executeForm(form);
			jim.signForm(form);
			for (int i = 0; i < 80; i++)
				jim.incGrade();
			jim.signForm(form);
			std::cout << jim;
			jim.executeForm(form);
			for (int i = 0; i < 30; i++)
				jim.incGrade();
			jim.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << std::endl << "____SHRUBBERY CREATION FORM TEST____" << std::endl;

			Bureaucrat john("John");
			ShrubberyCreationForm form;

			std::cout << john;
			john.executeForm(form);
			john.signForm(form);
			for (int i = 0; i < 10; i++)
				john.incGrade();
			john.signForm(form);
			std::cout << john;
			john.executeForm(form);
			for (int i = 0; i < 10; i++)
				john.incGrade();
			john.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		
	}

	return 0;
}
