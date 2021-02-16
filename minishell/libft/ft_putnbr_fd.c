/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:38:44 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:08 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fun(int n, int fd)
{
	char	c;

	if (n != 0)
	{
		if (n % 10 < 0)
			c = n % 10 * -1 + '0';
		else
			c = n % 10 + '0';
		ft_fun(n / 10, fd);
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	ft_fun(n, fd);
}
