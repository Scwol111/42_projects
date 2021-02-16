/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:42:14 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/29 15:42:38 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void	SedItAll(std::ifstream &ifs, std::ofstream &ofs, std::string &in, std::string &out)
{
	std::string buff;
	size_t start;

	while (std::getline(ifs, buff, '\n'))
	{
		while ((start = buff.find(in)) != std::string::npos)
			buff.replace(start, in.length(), out);
		ofs << buff << std::endl;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::string file_name(argv[1]);

	std::ifstream ifs(file_name);
	if (!ifs.is_open())
	{
		std::cerr << file_name + ": Wrong file name" << std::endl;
		return 1;
	}

	std::ofstream ofs(file_name + ".replace", std::ios_base::out | std::ios_base::trunc);
	if (!ofs.is_open())
	{
		std::cerr << "Cannot create file " + file_name + ".replace" << std::endl;
		return 1;
	}
	std::string in(argv[2]), out(argv[3]);

	SedItAll(ifs, ofs, in, out);

	ifs.close();
	ofs.close();
	return 0;
}