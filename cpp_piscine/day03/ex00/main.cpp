/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:29:22 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/06 13:51:17 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	FragTrap FRT("Arthas");

	std::cout << std::endl;
	FRT.beRepaired(10);
	std::cout << std::endl;
	FRT.meleeAttack("Father1");
	std::cout << std::endl;
	FRT.rangedAttack("Lenin");
	std::cout << std::endl;
	FRT.takeDamage(10);
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		FRT.vaulthunter_dot_exe("John Snow");
		std::cout << std::endl;
	}
	FRT.beRecharged(25);
	std::cout << std::endl;
	FRT.vaulthunter_dot_exe("John Cena");
	std::cout << std::endl;
	return 0;
}