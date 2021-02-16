/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:27:35 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/16 15:10:48 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SCALE 64
# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 64
# define MAX_WIDTH 5120
# define MAX_HEIGHT 2880
# define NAME "Cube3D by tclaudin"
# define XPM ".xpm"
# define PNG ".png"
# define BMP ".bmp"
# define FOV 60
# define POV_E 0
# define POV_N 90
# define POV_W 180
# define POV_S 270
# define SPEED 10
# define ROTATION 4
# define MAX_ROT 360
# define MIN_ROT 0
# define TO_PI M_PI / 180.0
# define TO_DE 180.0 / M_PI
# define TO_SC 1.0 / SCALE
# define BLACK 0x0
# define MAX_SPRT 10 * SCALE
# define SAVE "--save"
# define SCREENSHOT "screenshot.bmp"
# define MAP_SYMBOL "012NSWE "

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "colors.h"
# include "structs.h"
# include "errors.h"
# include "../mlx/mlx.h"

#endif
