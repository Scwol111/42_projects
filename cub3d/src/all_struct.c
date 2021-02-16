/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:25:42 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/19 16:29:49 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_all	*create_all_struct(void)
{
	t_all	*al;

	if (!(al = (t_all*)malloc(sizeof(t_all))))
		return (ft_errors_null(ALLER));
	return (al);
}

void	free_all_struct(t_all *al)
{
	if (al)
	{
		if (al->pl)
			player_free(al->pl);
		if (al->mlx)
			close_mlx(al->mlx, al->data);
	}
}
