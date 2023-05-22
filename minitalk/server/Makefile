# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/30 17:06:27 by tclaudin          #+#    #+#              #
#    Updated: 2021/08/30 18:26:23 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

FILES = main

SRC = $(addprefix ./srcs/, $(addsuffix .c, $(FILES)))

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

clear: clean

re: fclean all

.PHONY: all fclean clean re clear
