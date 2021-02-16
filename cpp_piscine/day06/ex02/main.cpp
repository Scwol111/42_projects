/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:36:11 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/16 19:13:57 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

int main()
{
	std::srand(time(NULL));

	Base *p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);

	delete p;
	return 0;
}

Base *generate(void)
{
	int idx = rand() % 3;
	switch (idx)
	{
		case 0:
			std::cout << "Creating:\t\tA class" << std::endl;
			return new A;
			break;
		case 1:
			std::cout << "Creating:\t\tB class" << std::endl;
			return new B;
			break;
		case 2:
			std::cout << "Creating:\t\tC class" << std::endl;
			return new C;
			break;
		default:
			break;
	}
	return NULL;
}

void identify_from_pointer(Base *p)
{
	std::cout << "Pointer:\t";
	if (dynamic_cast<A*>(p))
	{
		std::cout << "finded\tA class" << std::endl;
		return ;
	}

	if (dynamic_cast<B*>(p))
	{
		std::cout << "finded\tB class" << std::endl;
		return ;
	}

	if (dynamic_cast<C*>(p))
	{
		std::cout << "finded\tC class" << std::endl;
		return ;
	}
}

void identify_from_reference(Base &p)
{
	std::cout << "Reference:\t";
	try
	{
		if (&dynamic_cast<A&>(p))
		{
			std::cout << "finded\tA class" << std::endl;
			return ;
		}
	}
	catch(const std::exception& e) {}

	try
	{
		if (&dynamic_cast<B&>(p))
		{
			std::cout << "finded\tB class" << std::endl;
			return ;
		}
	}
	catch(const std::exception& e) {}

	try
	{
		if (&dynamic_cast<C&>(p))
		{
			std::cout << "finded\tC class" << std::endl;
			return ;
		}
	}
	catch(const std::exception& e) {}
}
