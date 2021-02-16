/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:24:39 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/13 18:00:00 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "defines.h"

int			get_next_line(int fd, char **line);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			key_working(int	keycode, t_all *all);
int			key_closing(int key, t_all *all);
int			ft_sc(double x);
int			ft_abs(int x);
int			my_get_img_color(t_image *img, int x, int y);
int			create_screenshot(t_all *all);
int			raycast(t_all *all);
int			raycast_utils(t_all *all, int *col);
int			count_komma(char *str);
int			count_word(char *str);
int			ft_isspace(char c);
int			count_number(char *str);

void		data_free(t_data *data);
void		close_mlx(t_mlx *mlx, t_data *data);
void		*ft_errors_null(char *str);
void		player_free(t_player *pl);
void		free_all_struct(t_all *al);
void		change_position(t_data *data, t_player *pl, short way);
void		change_pov(t_player *pl, short way);
void		change_pos_plus(char next, int *pos, int *map_pos);
void		change_pos_minus(char next, int *pos, int *map_pos);
void		my_mlx_pixel_put(t_image *img, int x, int y, int color);
void		add_sprite(t_ray *ray, t_point *dot, t_pl_po *pl);
void		sprite_utils(t_all *all, t_r_spr *sprt, t_ray *ray, int i);

char		*ft_skip_space(char *str);
char		*ft_next_word(char *str);

double		ft_tan(double angle);
double		ft_cos(double angle);
double		ft_sin(double angle);
double		find_wall_side(double angle, double res, char *ch, char type);
double		ft_sqr(double x);
double		ft_acos(double x);
double		ft_asin(double x);
double		get_angle(double x, double y);
double		ft_sprt_conv(int a);

t_data		*new_data(void);

t_bool		ft_parse(char *fname, t_data *data);
t_bool		valid_map(t_data *data);
t_bool		data_ready_for_map(t_data *dt);
t_bool		data_find_null(t_data *dt);
t_bool		map_input(t_data *data, char *str);
t_bool		ft_errors(char *str);
t_bool		check_sprite(t_ray *ray, t_point *dot);
t_bool		choose_map_error(int player, int err);
t_bool		map_validate_str(char *str);
t_bool		valide_str(char *str);
t_bool		valide_str2(char *str);

t_mlx		*create_mlx(t_data *data);

t_info		*get_texture(t_all *all);

t_player	*create_player(t_data *data);

t_all		*create_all_struct(void);

t_point		map_size(char **map);

t_ray		*ray_create(t_all *all);

t_r_spr		*create_sprite(t_all *all, int *begin);

t_image		*render(t_all *all, t_ray *ray, t_image *img, int col);
t_image		*render_sprite(t_image *img, t_ray *ray, t_all *all);

#endif
