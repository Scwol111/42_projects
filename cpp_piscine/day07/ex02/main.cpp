/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:30:40 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/17 19:13:28 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "Fixed.class.hpp"

int main()
{
	{
		std::cout << "___INT TEST___" << std::endl;
		Array<int> arr(20);

		for (size_t i = 0; i < arr.size(); i++)
			arr[i] = i;

		for (size_t i = 0; i < arr.size(); i++)
			std::cout << arr[i] + 5 << " ";
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "___FLOAT TEST___" << std::endl;
		Array<float> arr(20);

		for (size_t i = 0; i < arr.size(); i++)
			arr[i] = i + 0.5;

		for (size_t i = 0; i < arr.size(); i++)
			std::cout << arr[i] + 5 << " ";
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "___OUT OF RANGE TEST___" << std::endl;
		Array<int> arr(20);

		for (size_t i = 0; i < arr.size(); i++)
			arr[i] = i + 0.5;

		try
		{
			arr[25] = 54;
			std::cout << "If you see there, your [] oerator work bad" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl << "___EMPTY TEST___" << std::endl;
		Array<int> arr;

		std::cout << arr.size() << std::endl;

		try
		{
			arr[0] = 54;
			std::cout << "If you see there, your [] oerator work bad" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	{
		std::cout << std::endl << "___MINUS INDEX TEST___" << std::endl;
		Array<int> arr(20);

		std::cout << arr.size() << std::endl;

		try
		{
			arr[-1] = 54;
			std::cout << "If you see there, your [] oerator work bad" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl << "___FIXED CLASS TEST___" << std::endl;
		Array<Fixed> arr(20);

		for (size_t i = 0; i < arr.size(); i++)
			arr[i] = Fixed(i + 0.5f);

		for (size_t i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	return 0;
}