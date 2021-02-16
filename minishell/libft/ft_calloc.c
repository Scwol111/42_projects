/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:50:18 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:51:55 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*st;
	size_t	i;

	i = -1;
	st = (void*)malloc(number * size);
	if (!st)
		return (NULL);
	while (++i < number * size)
	{
		*((char*)st + i) = 0;
	}
	return (st);
}
