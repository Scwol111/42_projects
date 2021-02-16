/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 15:35:55 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:46 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	str = (char*)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s != 0)
	{
		*(str + i) = f(i, *s);
		i++;
		s++;
	}
	*(str + i) = 0;
	return (str);
}
