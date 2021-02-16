/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:34:20 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/16 18:18:22 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void *serialize(void)
{
	std::srand(time(NULL));
	std::string pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
	char *res = new char[20];
	for (int i = 0; i < 8; i++)
	{
		res[i] = pool[rand() % pool.size()];
		std::cout << res[i];
	}
	int add = rand();
	std::cout << std::endl << add << std::endl;
	*reinterpret_cast<int*>(res + 8) = add;
	for (int i = 0; i < 8; i++)
	{
		res[12 + i] = pool[rand() % pool.size()];
		std::cout << res[12 + i];
	}
	std::cout << std::endl;
	return res;
}

Data * deserialize(void * raw)
{
	Data *data = new Data;

	data->s1 = std::string(reinterpret_cast<char*>(raw), 8);
	data->n = *(reinterpret_cast<int*>(static_cast<char*>(raw) + 8));
	data->s2 = std::string(reinterpret_cast<char*>(raw) + 12, 8);

	return data;
}
