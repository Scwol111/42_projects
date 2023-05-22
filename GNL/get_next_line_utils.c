/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:09:13 by nikita            #+#    #+#             */
/*   Updated: 2020/06/21 12:33:59 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (*(s2 + i) != 0)
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	return (s1);
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*st;
	size_t	i;

	i = -1;
	if (!(st = (void*)malloc(number * size)))
		return (NULL);
	while (++i < number * size)
		*((char*)st + i) = 0;
	return (st);
}

char	*ft_remake(char *str, size_t size)
{
	char *new_str;

	if (!(new_str = (char*)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	ft_strcpy(new_str, str);
	free(str);
	return (new_str);
}
