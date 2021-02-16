# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 13:09:24 by tclaudin          #+#    #+#              #
#    Updated: 2021/01/16 14:50:53 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CMP = clang++

NAME = convert

FLAGS = -Wall -Wextra -Werror

FILE = main.cpp Convetation.cpp

OBJ = $(FILE:.cpp=.o)

all: $(NAME)

%.o: %.cpp Convetation.hpp
	$(CMP) $(FLAGS) -c $<

$(NAME): $(OBJ)
	$(CMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all fclean re clean $(NAME)
