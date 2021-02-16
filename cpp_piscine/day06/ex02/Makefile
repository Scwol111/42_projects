# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 13:09:24 by tclaudin          #+#    #+#              #
#    Updated: 2021/01/16 19:06:41 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CMP = clang++

NAME = dynamic

FLAGS = -Wall -Wextra -Werror

FILE = main.cpp 

OBJ = $(FILE:.cpp=.o)

all: $(NAME)

%.o: %.cpp *.hpp
	$(CMP) $(FLAGS) -c $<

$(NAME): $(OBJ)
	$(CMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all fclean re clean $(NAME)
