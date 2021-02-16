/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 12:04:07 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/07 14:07:12 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_bool	ft_errors(char *str)
{
	write(1, ERROR, ft_strlen(ERROR));
	write(1, str, ft_strlen(str));
	exit(1);
	return (FALSE);
}

void	*ft_errors_null(char *str)
{
	write(1, ERROR, ft_strlen(ERROR));
	write(1, str, ft_strlen(str));
	exit(1);
	return (NULL);
}

t_bool	choose_map_error(int player, int err)
{
	if (player != 1)
		return (ft_errors(MPPLA));
	if (err > 0)
		return (ft_errors(MPERR));
	return (TRUE);
}
