/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:39:18 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:57:26 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	size_t i;

	i = 0;
	if (destptr != NULL || srcptr != NULL)
		while (i < num)
		{
			*((unsigned char*)destptr + i) = *((unsigned char*)srcptr + i);
			i++;
		}
	return (destptr);
}
