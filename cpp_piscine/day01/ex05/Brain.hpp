/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:41:03 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/29 16:24:02 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class Brain
{
private:
	std::string _idea;
	
public:
	Brain();
	~Brain();
	std::string identify();
};
