# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 14:42:18 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/29 14:46:07 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = likeSed

CPP = clang++

FLAGS = -Wall -Wextra -Werror -o $(NAME)

FILES = main.cpp

OBJ = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all $(NAME) clean fclean re
