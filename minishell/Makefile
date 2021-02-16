# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 17:40:25 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/08 16:41:02 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

T_FILES = get_next_line utils ft_env ft_parse ft_specials ft_dq_specials\
ft_specials2 utils2 create_echo create_cd create_env create_exit create_export\
create_pwd create_unset create_another tokens ft_env2 redirects redirects2 \
redirects_dq pipe ft_exit ft_errors

L_FILES = cd echo export error pwd unset export_utils

SRC = $(addprefix ./src/tclaudin/, $(addsuffix .c, $(T_FILES)))\
$(addprefix ./src/loscar/, $(addsuffix .c, $(L_FILES)))\
$(addprefix ./src/, $(addsuffix .c, main))

OBJ = $(SRC:.c=.o)

HFILE = minishell defines structs

INCLUDE = $(addprefix ./include/, $(addsuffix .h, $(HFILE)))

CFLAGS = -Wall -Wextra -Werror -I./include

LIBFT = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

clear: clean

re: fclean all

norm: norml normh normc

normh:
	norminette $(INCLUDE)

normc:
	norminette $(SRC);

norml:
	$(MAKE) -C libft norm

.PHONY: $(NAME) all fclean clean re norm normc normh norml clear
