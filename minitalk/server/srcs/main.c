/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:11:41 by tclaudin          #+#    #+#             */
/*   Updated: 2021/08/30 19:28:12 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sigZero(int x)
{
	int	count;
	int	num;

	(void)x;
	count = (g_temp >> 24);
	num = g_temp & 0xFF;
	count++;
	num <<= 1;
	g_temp = (count << 24) | num;
}

void	sigOne(int x)
{
	int	count;
	int	num;

	(void)x;
	count = (g_temp >> 24);
	num = g_temp & 0xFF;
	count++;
	num <<= 1;
	num++;
	g_temp = (count << 24) | num;
}

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_putnbr(int x)
{
	if (x > 0)
		ft_putnbr(x / 10);
	if (x != 0)
		ft_putchar((char)(x % 10 + '0'));
}

int	main(void)
{
	int	count;
	int	num;

	signal(SIGUSR1, sigZero);
	signal(SIGUSR2, sigOne);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		count = g_temp >> 24;
		if (count >= 8)
		{
			num = g_temp & 0xFF;
			ft_putchar(num);
			g_temp = 0;
		}
		usleep(10);
	}
	return (0);
}
