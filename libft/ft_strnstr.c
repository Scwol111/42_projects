/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:14:56 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:54 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *fnd, size_t len)
{
	size_t i;
	size_t slen;

	if (*fnd == 0)
		return ((char*)s);
	slen = ft_strlen(fnd);
	i = 0;
	while (*s != 0 && i + slen <= len)
	{
		if (ft_strncmp(s, fnd, slen) == 0)
			return ((char*)s);
		s++;
		i++;
	}
	return (NULL);
}
