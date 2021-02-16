# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 16:03:03 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/27 19:14:42 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = clang++

FLAGS = -Wall -Wextra -Werror -o $(NAME)

NAME = megaphone

FILE = $(NAME).cpp

OBJ = $(FILE:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CPP) $(FLAGS) $(FILE)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean $(NAME)

.PHONY: all $(NAME) clean fclean re