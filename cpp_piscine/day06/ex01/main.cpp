/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:31:00 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/16 18:30:11 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "header.hpp"

int main()
{
	Data *p = deserialize(serialize());
	std::cout << std::endl << p->s1 << std::endl;
	std::cout << p->n << std::endl;
	std::cout << p->s2 << std::endl;

	delete p;
	return 0;
}