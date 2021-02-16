/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:02:13 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:59 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *string, int symbol)
{
	char *sv;

	sv = NULL;
	while (*string != 0)
	{
		if (*string == symbol)
			sv = string;
		string++;
	}
	if (*string == symbol)
		sv = string;
	return (sv);
}
