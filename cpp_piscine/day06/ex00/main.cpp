/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:09:20 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/16 17:28:01 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Convetation.hpp"
#include <cmath>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Convetation rs(argv[1]);
		rs.output();
	}
	else
		std::cerr << "Number of argumnts are not good" << std::endl;
	return 0;
}