/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:37:56 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/12 19:44:12 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	mlx_connect(t_all *all)
{
	mlx_hook(all->mlx->mlx_win, 17, 1L << 0, key_closing, all);
	mlx_hook(all->mlx->mlx_win, 2, 1L << 0, key_working, all);
	mlx_loop(all->mlx->mlx_init);
}

int		main(int argc, char *argv[])
{
	t_all	*all;

	if (argc <= 3 && argc > 1)
	{
		if ((all = create_all_struct()))
			if ((all->data = new_data()) && ft_parse(argv[1], all->data))
			{
				if (!(all->mlx = create_mlx(all->data)) ||
				!(all->pl = create_player(all->data)) ||
				!(all->info = get_texture(all)) || !raycast(all))
					return (1);
				if (argc == 2)
					mlx_connect(all);
				else if (ft_strlen(argv[2]) == ft_strlen(SAVE) &&
				ft_strnstr(argv[2], SAVE, ft_strlen(argv[2])))
					create_screenshot(all);
				else
					return (ft_errors(SVERR));
			}
	}
	else
		return (ft_errors(ARRER));
	exit(0);
	return (0);
}
