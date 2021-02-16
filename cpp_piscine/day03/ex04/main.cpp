/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:29:22 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/07 17:33:55 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	FragTrap FRT("Arthas");
	std::cout << std::endl;
	ScavTrap SCV("Uther");
	std::cout << std::endl;
	NinjaTrap NJA("Illidan");
	std::cout << std::endl;
	NinjaTrap NJA1("Leonardo");
	std::cout << std::endl;
	ClapTrap CLP("Common");
	std::cout << std::endl;
	SuperTrap SPR("Arhimonde");
	std::cout << std::endl;

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

	std::cout << std::endl;
	NJA.beRepaired(10);
	std::cout << std::endl;
	NJA.meleeAttack("Father");
	std::cout << std::endl;
	NJA.rangedAttack("Lenin");
	std::cout << std::endl;
	NJA.takeDamage(10);
	std::cout << std::endl;
	NJA.ninjaShoebox(NJA1);
	std::cout << std::endl;
	NJA.ninjaShoebox(FRT);
	std::cout << std::endl;
	NJA.beRecharged(30);
	std::cout << std::endl;
	NJA.ninjaShoebox(SCV);
	std::cout << std::endl;
	NJA.beRecharged(50);
	std::cout << std::endl;
	NJA.ninjaShoebox(CLP);
	std::cout << std::endl;
	NJA.ninjaShoebox(FRT);
	std::cout << std::endl;
	
	std::cout << std::endl;
	SPR.beRepaired(10);
	std::cout << std::endl;
	SPR.meleeAttack("Father");
	std::cout << std::endl;
	SPR.rangedAttack("Lenin");
	std::cout << std::endl;
	SPR.takeDamage(10);
	std::cout << std::endl;
	SPR.vaulthunter_dot_exe("Jaina Praudmur");
	std::cout << std::endl;
	SPR.ninjaShoebox(NJA);
	std::cout << std::endl;

	return 0;
}