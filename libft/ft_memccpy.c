/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:48:29 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:57:14 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		*((unsigned char*)dest + i) = *((unsigned char*)source + i);
		if (*((unsigned char*)source + i) == (unsigned char)ch)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
