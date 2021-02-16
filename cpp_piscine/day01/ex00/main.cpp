/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:14:27 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/29 13:40:55 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

int ponyOnTheStack()
{
	std::cout << "Now you in pony on the STACK function" << std::endl;
	Pony p1, p2;
	std::cout << "All Pony was created" << std::endl;
	p1.ChangeLoyality();
	p2.NationalizeMoney();
	return 0;
}

int ponyOnTheHeap()
{
	std::cout << "Now you in pony on the HEAP function" << std::endl;
	Pony *p1 = new Pony();
	Pony *p2 = new Pony();
	std::cout << "All Pony was created" << std::endl;
	p1->ChangeLoyality();
	delete p1;
	std::cout << "Ah shit, someone dead" << std::endl;
	p2->NationalizeMoney();
	p2->NationalizeMoney();
	delete p2;
	return 0;
}

int main()
{
	std::srand(std::time(NULL));
	std::cout << "Welcome to main. Now you'll see some function with memory allocation" << std::endl;
	ponyOnTheStack();
	std::cout << std::endl << "Ah, here we go again" << std::endl;
	ponyOnTheHeap();
	std::cout << "Finally this ended" << std::endl;
	return 0;
}