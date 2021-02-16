/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:50:18 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:27:07 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_test(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

static char	ft_f(int fl, int *result, char string)
{
	if (fl)
	{
		if (*result * 10 - (string - '0') > 0 && fl)
			return ('z');
		else
			*result = *result * 10 - (string - '0');
	}
	else
	{
		if (*result * 10 + (string - '0') < 0 && !fl)
			return ('n');
		else
			*result = *result * 10 + (string - '0');
	}
	return ('g');
}

int			ft_atoi(const char *string)
{
	int		result;
	short	fl;
	char	test;

	result = 0;
	fl = 0;
	while (*string != 0 && ft_test(*string))
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			fl = 1;
		string++;
	}
	while (*string != 0 && *string >= '0' && *string <= '9')
	{
		test = ft_f(fl, &result, *string);
		if (test == 'z')
			return (0);
		if (test == 'n')
			return (-1);
		string++;
	}
	return (result);
}
