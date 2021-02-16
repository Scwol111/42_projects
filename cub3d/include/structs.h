/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:28:08 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/13 16:33:29 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef short	t_bool;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_po_pl
{
	double x;
	double y;
}				t_pl_po;

typedef struct	s_player
{
	t_pl_po	*pos;
	short	pov;
}				t_player;

typedef struct	s_mlx
{
	void	*mlx_init;
	void	*mlx_win;
	t_bool	can_work;
}				t_mlx;

typedef struct	s_data
{
	int		width;
	int		hight;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		floor_rgb;
	int		ceil_rgb;
	char	**map;
	int		map_size;
	int		map_current_cout;
}				t_data;

typedef struct	s_sprite
{
	double	dist;
	t_pl_po	po;
	t_point	pos;
}				t_sprite;

typedef struct	s_ray
{
	double		dist[MAX_WIDTH];
	char		wall;
	double		angle;
	t_bool		horz;
	t_sprite	sprite[MAX_SPRT];
	int			sprt_count;
	double		proj_pl;
	t_pl_po		point;
	int			end;
	double		angle_plus;
}				t_ray;

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct	s_information
{
	t_image *north;
	t_point no_wh;
	t_image	*south;
	t_point	so_wh;
	t_image	*west;
	t_point	we_wh;
	t_image	*east;
	t_point	ea_wh;
	t_image	*sprite;
	t_point	sp_wh;
}				t_info;

typedef struct	s_all
{
	t_mlx		*mlx;
	t_data		*data;
	t_player	*pl;
	t_info		*info;
	t_image		save;
}				t_all;

typedef struct	s_render_sprite
{
	t_image	*img;
	int		h;
	int		w;
	int		start;
	int		width;
	int		height;
	int		y;
	int		x;
	double	dist;
	double	angle;
}				t_r_spr;

typedef struct	s_render
{
	t_image	*tex;
	int		hei;
	int		clo;
}				t_render;

#endif
