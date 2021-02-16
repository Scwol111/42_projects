/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:00:46 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:57:32 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	size_t	i;

	if ((destptr != NULL || srcptr != NULL) && num > 0)
	{
		if (destptr > srcptr)
		{
			i = num;
			while (--i > 0)
				*((unsigned char*)destptr + i) = *((unsigned char*)srcptr + i);
			*((unsigned char*)destptr + i) = *((unsigned char*)srcptr + i);
		}
		else
		{
			i = -1;
			while (++i < num)
				*((unsigned char*)destptr + i) = *((unsigned char*)srcptr + i);
		}
	}
	return (destptr);
}
