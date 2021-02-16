/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:23:49 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/18 18:30:30 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <stack>

int main()
{
	{
		std::cout << "___COMMON TEST___" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << ' ';
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "___ITERATOR TEST___" << std::endl;
		MutantStack<int> mstack;
		for (int i = 0; i < 20; i++)
			mstack.push(i);
		for (MutantStack<int>::iterator k = mstack.begin(); k != mstack.end(); k++)
			std::cout << *k + 1 << ' ';
		for (int i = 0; i < 20; i++)
			mstack.pop();
		std::cout << std::endl << "Size: " << mstack.size() << std::endl;
	}
	{
		std::cout << std::endl << "___REVERSE ITERATOR TEST___" << std::endl;
		MutantStack<int> mstack;
		for (int i = 0; i < 20; i++)
			mstack.push(i);
		for (MutantStack<int>::reverse_iterator k = mstack.rbegin(); k != mstack.rend(); k++)
			std::cout << *k + 1 << ' ';
		for (int i = 0; i < 20; i++)
			mstack.pop();
		std::cout << std::endl << "Size: " << mstack.size() << std::endl;
	}
	{
		std::cout << std::endl << "___CONST ITERATOR TEST___" << std::endl;
		MutantStack<int> mstack;
		for (int i = 0; i < 20; i++)
			mstack.push(i);
		for (MutantStack<int>::const_iterator k = mstack.begin(); k != mstack.end(); k++)
			std::cout << *k << ' ';
		for (int i = 0; i < 20; i++)
			mstack.pop();
		std::cout << std::endl << "Size: " << mstack.size() << std::endl;
	}
	{
		std::cout << std::endl << "___CONST REVERSE ITERATOR TEST___" << std::endl;
		MutantStack<int> mstack;
		for (int i = 0; i < 20; i++)
			mstack.push(i);
		for (MutantStack<int>::const_reverse_iterator k = mstack.rbegin(); k != mstack.rend(); k++)
			std::cout << *k << ' ';
		for (int i = 0; i < 20; i++)
			mstack.pop();
		std::cout << std::endl << "Size: " << mstack.size() << std::endl;
	}
	{
		std::cout << std::endl << "___ITERATOR FROM END TEST___" << std::endl;
		MutantStack<int> mstack;
		for (int i = 0; i < 20; i++)
			mstack.push(i);
		for (MutantStack<int>::iterator k = --mstack.end(); k != --mstack.begin(); k--)
			std::cout << *k + 1 << ' ';
		for (int i = 0; i < 20; i++)
			mstack.pop();
		std::cout << std::endl << "Size: " << mstack.size() << std::endl;
	}
	return 0;
}
