/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:00:40 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/18 11:25:56 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "Fixed.class.hpp"

template <typename _T>
void ft_print(_T const &x)
{
	std::cout << x << " ";
}

int main()
{
	std::srand(time(NULL));
	{
		std::cout << "___DOUBLE TEST___" << std::endl;
		double arr[20];
		std::cout << "ORG: ";
		for (int i = 0; i < 20; i++)
		{
			arr[i] = std::rand() % 10 + 0.5;
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl << "PRT: ";
		iter(arr, 20, ft_print);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "___INT TEST___" << std::endl;
		int arr[20];
		std::cout << "ORG: ";
		for (int i = 0; i < 20; i++)
		{
			arr[i] = std::rand() % 10;
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl << "PRT: ";
		iter(arr, 20, ft_print);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "___STRING TEST___" << std::endl;
		std::string arr[20];
		std::cout << "ORG: ";
		for (int i = 0; i < 20; i++)
		{
			arr[i] = "Hello";
			arr[i] += (std::rand() % 10 + '0');
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl << "PRT: ";
		iter(arr, 20, ft_print);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "___FIXED CLASS TEST___" << std::endl;
		Fixed arr[20];
		std::cout << "ORG: ";
		for (int i = 0; i < 20; i++)
		{
			arr[i] = Fixed(std::rand() % 10 + 0.5f);
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl << "PRT: ";
		iter(arr, 20, ft_print);
		std::cout << std::endl;
	}
	return 0;
}
