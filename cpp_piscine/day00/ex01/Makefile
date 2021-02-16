# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 17:00:59 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/27 19:14:53 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = clang++

FLAGS = -Wall -Wextra -Werror -o $(NAME)

NAME = phonebook

FILE = Phonebook.Class.cpp main.cpp Data.Class.cpp

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