/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:07:41 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:28:02 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *string)
{
	size_t len;

	len = 0;
	while (*string != 0)
	{
		len++;
		string++;
	}
	return (len);
}

int		ft_errors(char *line)
{
	write(1, line, ft_strlen(line));
	return (1);
}

void	*ft_errors_null(char *line)
{
	write(1, line, ft_strlen(line));
	return (NULL);
}

void	ft_sleep(int usec)
{
	size_t now;
	size_t times;

	times = ft_gettime();
	while (1)
	{
		now = ft_gettime();
		if (now - times >= (size_t)usec)
			return ;
		usleep(50);
	}
}

size_t	ft_gettime(void)
{
	size_t	res;
	t_times	t;

	gettimeofday(&t, NULL);
	res = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (res);
}
