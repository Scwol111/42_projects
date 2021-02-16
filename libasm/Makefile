# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 11:55:46 by tclaudin          #+#    #+#              #
#    Updated: 2020/10/23 16:55:29 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJ = $(SRC:.s=.o)

all: $(NAME)

%.o : %.s
	nasm -f macho64 $<

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -rf *write.txt

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	$(CC) -o test main.c $(NAME)
	./test
	rm -rf test

test1:
	$(CC) -o test main.c $(OBJ)
	./test
	rm -rf test

.PHONY: all $(NAME) clean fclean re test