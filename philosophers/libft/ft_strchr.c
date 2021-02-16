/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:34:10 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:21 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *string, int symbol)
{
	char *str;

	str = string;
	while (*str != symbol && *str != 0)
		str++;
	if (*str == symbol)
		return (str);
	return (NULL);
}
