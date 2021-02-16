/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:35:23 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/29 13:40:42 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <iostream>

int main()
{
	std::srand(std::time(NULL));
	int max = std::rand() % 20;
	ZombieHorde horde(max);
	horde.SayHello();
	return 0;
}