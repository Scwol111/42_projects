/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:27:11 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:57:18 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *memptr, int val, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		if (*((unsigned char*)memptr + i) == (unsigned char)val)
			return ((void*)(memptr + i));
		i++;
	}
	return (NULL);
}
