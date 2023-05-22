/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:28:22 by tclaudin          #+#    #+#             */
/*   Updated: 2021/09/27 19:27:54 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(char *str)
{
	long	temp;

	temp = 0;
	while (str && *str && *str >= '0' && *str <= '9' && temp <= PID_MAX)
	{
		temp *= 10;
		temp += *str - '0';
		str++;
	}
	if (!str || *str != 0 || temp > PID_MAX)
		return (-1);
	return ((int)temp);
}

void	call_kill(int pid, int c)
{
	if (c == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_char(int pid, int c, int count)
{
	if (count < 8)
		send_char(pid, c >> 1, count + 1);
	call_kill(pid, c & 0x1);
	usleep(20);
}

void	send(int pid, char *str)
{
	while (str && *str)
	{
		send_char(pid, *str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
		{
			send(pid, argv[2]);
			send(pid, "\n");
		}
		else
			write(1, "Wrong pid\n", 10);
	}
	else
		write(1, "Wrong number of arguments\n", 26);
	return (0);
}
