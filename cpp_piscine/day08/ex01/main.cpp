/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:11:06 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/18 16:20:34 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"
#include <vector>

int main()
{
	std::srand(std::time(NULL));
	{
		std::cout << "___STANDART TEST___" << std::endl;
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span:\t" << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:\t" << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "___MAX NUMBER TEST___" << std::endl;
		Span sp = Span(5);
		try
		{
			while (true)
				sp.addNumber(std::rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl << "___LONG TEST___" << std::endl;
		Span sp = Span(20000);
		for (size_t i = 0; i < 20000; i++)
			sp.addNumber(std::rand());
		std::cout << "Shortest span:\t" << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:\t" << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "___EMPTY TEST___" << std::endl;
		Span sp = Span(5);
		try
		{
			std::cout << "Shortest span:\t" << sp.shortestSpan() << std::endl;
			std::cout << "Longest span:\t" << sp.longestSpan() << std::endl;
			std::cout << "No error? Hah" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl << "___ITERATOR TEST___" << std::endl;
		std::vector<int> vc(20);
		Span sp = Span(20);
		for (size_t i; i < vc.size(); i++)
			vc[i] = std::rand() % 100;
		sp.addNumber(vc.begin(), vc.end());
		std::cout << "Shortest span:\t" << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:\t" << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "___NOT ENOUGH TEST___" << std::endl;
		Span sp = Span(5);
		sp.addNumber(5);
		try
		{
			std::cout << "Shortest span:\t" << sp.shortestSpan() << std::endl;
			std::cout << "Longest span:\t" << sp.longestSpan() << std::endl;
			std::cout << "No error? Hah" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}