/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:44:15 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:52:50 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reverse(char *str)
{
	short	left;
	short	right;
	char	z;

	left = 0;
	right = ft_strlen(str) - 1;
	if (*str == '-')
		left++;
	while (left < right)
	{
		z = *(str + right);
		*(str + right) = *(str + left);
		*(str + left) = z;
		left++;
		right--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	short	i;
	int		res;

	i = 0;
	str = (char*)malloc(15);
	if (!str)
		return (NULL);
	if (n < 0)
		*(str + i++) = '-';
	if (n == 0)
		*(str + i++) = '0';
	while (n != 0)
	{
		res = n % 10;
		if (res < 0)
			res *= -1;
		*(str + i++) = res + '0';
		n /= 10;
	}
	*(str + i) = 0;
	reverse(str);
	return (str);
}
