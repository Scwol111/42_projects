/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:05:26 by tclaudin          #+#    #+#             */
/*   Updated: 2020/11/13 17:55:10 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t i;

	i = -1;
	while (++i < num && *s1 != 0 && *s2 != 0)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s2++;
		s1++;
	}
	if (*s2 != *s1 && i < num)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
