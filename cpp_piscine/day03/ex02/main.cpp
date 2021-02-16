/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:29:22 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/06 18:41:17 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	FragTrap FRT("Arthas");
	ScavTrap SCV("Uther");

	 std::cout << std::endl;
	FRT.beRepaired(10);
	std::cout << std::endl;
	FRT.meleeAttack("Father");
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

	SCV.beRepaired(10);
	std::cout << std::endl;
	SCV.meleeAttack("Father");
	std::cout << std::endl;
	SCV.rangedAttack("Lenin");
	std::cout << std::endl;
	SCV.takeDamage(10);
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		SCV.challengeNewcomer("John Snow");
		std::cout << std::endl;
	}
	return 0;
}