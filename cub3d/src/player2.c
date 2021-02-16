/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 19:20:51 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/25 20:13:16 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	change_pos_plus(char next, int *pos, int *map_pos)
{
	*pos += SPEED;
	if (*pos > SCALE)
	{
		if (next == '1' || next == '2')
			*pos = SCALE;
		else
		{
			*pos -= SCALE;
			*map_pos = *map_pos + 1;
		}
	}
}

void	change_pos_minus(char next, int *pos, int *map_pos)
{
	*pos -= SPEED;
	if (*pos < 0)
	{
		if (next == '1' || next == '2')
			*pos = 0;
		else
		{
			*pos += SCALE;
			*map_pos = *map_pos - 1;
		}
	}
}
