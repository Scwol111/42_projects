/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:14:42 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/07 14:09:06 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		key_closing(int key, t_all *all)
{
	if (all)
	{
		exit(0);
		free_all_struct(all);
	}
	key += 2;
	key -= 2;
	return (0);
}

int		key_working(int key, t_all *all)
{
	if (all)
	{
		if (key == 0 || key == 13 || key == 1 || key == 2 || key == 123
		|| key == 124 || key == 53)
		{
			if (key == 0 || key == 13 || key == 1 || key == 2)
				change_position(all->data, all->pl, key);
			if (key == 123 || key == 124)
				change_pov(all->pl, key);
			if (key == 53)
			{
				free_all_struct(all);
				exit(0);
			}
			if (!raycast(all))
				return (1);
		}
	}
	return (0);
}
