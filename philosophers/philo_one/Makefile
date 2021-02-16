# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 18:42:03 by tclaudin          #+#    #+#              #
#    Updated: 2021/01/23 15:54:14 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

FILES = main ft_atoi utils init sim

SRC = $(addsuffix .c,$(FILES))

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
