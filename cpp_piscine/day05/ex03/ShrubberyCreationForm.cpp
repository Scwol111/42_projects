/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:27:50 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 18:49:28 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery Creation Form", 137, 145)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form("Shrubbery Creation Form", 137, 145, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::ofstream ofs(executor.getName() + "_shrubbery", std::ios_base::out | std::ios_base::trunc);
	if (std::rand() & 0x1)
	{
		std::ifstream ifs("tree_PNG2517.ansi.txt");
		std::string buff;
		while (std::getline(ifs, buff, '\n'))
			ofs << buff << std::endl;
	}
	else
	{
		ofs << 
"    oxoxoo    ooxoo\n" << 
"  ooxoxo oo  oxoxooo\n" << 
" oooo xxoxoo ooo ooox\n" << 
" oxo o oxoxo  xoxxoxo\n" << 
"  oxo xooxoooo o ooo\n" << 
"    ooo\\oo\\  /o/o\n" << 
"        \\  \\/ /\n" << 
"         |   /\n" << 
"         |  |\n" << 
"         | D|\n" << 
"         |  |\n" << 
"         |  |\n" << 
"  ______/____\\____" << std::endl;

	}
}
