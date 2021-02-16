/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:50:59 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:59:04 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_compare(char c, char const *set)
{
	while (*set != 0)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	left;
	size_t	right;

	left = 0;
	while (*s1 != 0 && ft_compare(*s1, set))
		s1++;
	right = ft_strlen(s1);
	while (right > left && ft_compare(*(s1 + right - 1), set))
		right--;
	str = (char *)malloc(sizeof(*s1) * (right + 1));
	if (!str)
		return (NULL);
	while (left < right)
		*(str + left++) = *(s1++);
	*(str + left) = 0;
	return (str);
}
