/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:35:27 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:57:22 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	size_t i;

	i = -1;
	while (++i < num)
	{
		if (*((unsigned char*)memptr1 + i) != *((unsigned char*)memptr2 + i))
			return (*((unsigned char*)memptr1 + i) -
			*((unsigned char*)memptr2 + i));
	}
	return (0);
}
