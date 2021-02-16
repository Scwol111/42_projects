/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:31:01 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/18 14:24:43 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>
#include <deque>


int main()
{
	std::srand(std::time(NULL));
	{
		std::cout << std::endl << "___VECTOR TEST___" << std::endl;
		std::vector<int> vc(20);
		std::cout << "Vector: ";
		for (size_t i = 0; i < vc.size(); i++)
		{
			vc[i] = std::rand() % 100;
			std:: cout << vc[i] << ' ';
		}
		int find = vc[std::rand() % vc.size()];
		std::cout << std::endl << "Find this: " << find << std::endl;
		std::cout << "I'm find: " << *easyfind(vc, find) << std::endl;
	}
	{
		std::cout << std::endl << "___ERROR VECTOR TEST___" << std::endl;
		std::vector<int> vc(20);
		std::cout << "Vector: ";
		for (size_t i = 0; i < vc.size(); i++)
		{
			vc[i] = std::rand() % 100;
			std:: cout << vc[i] << ' ';
		}
		std::cout << std::endl << "Find this: " << 105 << std::endl;
		try
		{
			std::cout << "I'm find: " << *easyfind(vc, 105) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Nothing" << std::endl;
		}
	}
	{
		std::cout << std::endl << "___LIST TEST___" << std::endl;
		std::list<int> ls;
		std::cout << "List: ";
		int find;
		size_t sz = std::rand() % 20;
		for (size_t i = 0; i < 20; i++)
		{
			ls.push_back(std::rand() % 100);
			std:: cout << ls.back() << ' ';
			if (i == sz)
				find = ls.back();
		}
		std::cout << std::endl << "Find this: " << find << std::endl;
		std::cout << "I'm find: " << *easyfind(ls, find) << std::endl;
	}
	{
		std::cout << std::endl << "___ERROR LIST TEST___" << std::endl;
		std::list<int> ls;
		std::cout << "List: ";
		for (size_t i = 0; i < 20; i++)
		{
			ls.push_back(std::rand() % 100);
			std:: cout << ls.back() << ' ';
		}
		std::cout << std::endl << "Find this: " << 105 << std::endl;
		try
		{
			std::cout << "I'm find: " << *easyfind(ls, 105) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Nothing" << std::endl;
		}
	}
	{
		std::cout << std::endl << "___SET TEST___" << std::endl;
		std::set<int> st;
		for (int i = 0; i < 20; i++)
			st.insert(std::rand() % 100);
		std::cout << "Set: ";
		int find;
		size_t sz = std::rand() % st.size();
		size_t i = 0;
		for (std::set<int>::iterator k = st.begin(); k != st.end(); k++, i++)
		{
			std::cout << *k << ' ';
			if (i == sz)
				find = *k;
		}
		std::cout << std::endl << "Find this: " << find << std::endl;
		std::cout << "I'm find: " << *easyfind(st, find) << std::endl;
	}
	{
		std::cout << std::endl << "___ERROR SET TEST___" << std::endl;
		std::set<int> st;
		for (int i = 0; i < 20; i++)
			st.insert(std::rand() % 100);
		std::cout << "Set: ";
		int find;
		size_t sz = std::rand() % st.size();
		size_t i = 0;
		for (std::set<int>::iterator k = st.begin(); k != st.end(); k++, i++)
		{
			std::cout << *k << ' ';
			if (i == sz)
				find = *k;
		}
		std::cout << std::endl << "Find this: " << 105 << std::endl;
		try
		{
			std::cout << "I'm find: " << *easyfind(st, 105) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Nothing" << std::endl;
		}
	}
	{
		std::cout << std::endl << "___DEQEUE TEST___" << std::endl;
		std::deque<int> de(20);
		std::cout << "Deque: ";
		for (size_t i = 0; i < de.size(); i++)
		{
			de[i] = std::rand() % 100;
			std::cout << de[i] << ' ';
		}
		int find = de[std::rand() % de.size()];
		std::cout << std::endl << "Find this: " << find << std::endl;
		std::cout << "I'm find: " << *easyfind(de, find) << std::endl;
	}
	{
		std::cout << std::endl << "___ERROR DEQEUE TEST___" << std::endl;
		std::deque<int> de(20);
		std::cout << "Deque: ";
		for (size_t i = 0; i < de.size(); i++)
		{
			de[i] = std::rand() % 100;
			std::cout << de[i] << ' ';
		}
		std::cout << std::endl << "Find this: " << 105 << std::endl;
		try
		{
			std::cout << "I'm find: " << *easyfind(de, 105) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Nothing" << std::endl;
		}
	}
}
