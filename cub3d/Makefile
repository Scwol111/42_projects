# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 15:32:20 by tclaudin          #+#    #+#              #
#    Updated: 2021/02/15 17:32:03 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FILE = main get_next_line ft_color ft_color2 data_work ft_parse map_work utils\
errors work_mlx keys player all_struct player2 utils2 raycast raycast2 render\
utils3 get_texture sprites screenshot sprite2 utils4

SRC = $(addsuffix .c,$(addprefix ./src/, $(FILE)))

OBJ = $(SRC:.c=.o)

HFILE = cube3d.h colors.h structs.h defines.h errors.h

INCLUDE = $(addprefix ./include/, $(HFILE))

CFLAGS = -Wall -Wextra -Werror -I./include

OGLFLAGS = -Lmlx -lmlx -lm -framework OpenGL -framework AppKit

MLX = libmlx.dylib

LIB = ./libft/libft.a

all:$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C mlx
	mv ./mlx/$(MLX) .
	$(MAKE) -C libft bonus
	$(CC) $(OGLFLAGS) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(MLX)

clean:
	$(MAKE) -C mlx clean
	$(MAKE) -C libft clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME) $(MLX)

re: fclean $(NAME)

bonus: all

norm: normc normh norml

normh:
	norminette $(INCLUDE)

normc:
	norminette $(SRC);

norml:
	$(MAKE) -C libft norm

.PHONY: all clean fclean re norm normc normh norml bonus