/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:14:13 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:52:23 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int character)
{
	if (character >= 'a' && character <= 'z')
		return (1);
	if (character >= 'A' && character <= 'Z')
		return (2);
	return (0);
}
