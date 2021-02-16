/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:32:33 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:30 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*st;
	size_t	i;

	i = 0;
	st = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (st == NULL)
		return (NULL);
	while (*s1 != 0)
		*(st + i++) = *(s1++);
	while (*s2 != 0)
		*(st + i++) = *(s2++);
	*(st + i++) = 0;
	return (st);
}
