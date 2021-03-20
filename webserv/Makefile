# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 17:46:01 by tclaudin          #+#    #+#              #
#    Updated: 2021/03/15 13:28:26 by jsandsla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=webserv
TEST=test_webserv

SRC_NAMES=\
Server.cpp\
MessageBody.cpp\
Client.cpp\
StatusCode.cpp\
Method.cpp\
ViewData.cpp\
URI.cpp\
Path.cpp\
BNF.cpp\
HeaderParser.cpp\
Headers/Header.cpp\
HeaderSection/HeaderSection.cpp\
HeaderSection/RequestHeaderSection.cpp\
HeaderSection/ResponseHeaderSection.cpp\
Location.cpp\
ServerInfo.cpp\
Config.cpp\
ErrorInfo.cpp\
main.cpp

SRC=$(addprefix srcs/,$(SRC_NAMES))

OBJ=$(SRC:.cpp=.o)

HEADER=$(SRC:.cpp=.hpp)

all: $(NAME)

CXX=clang++
CXXFLAGS=-Wall -Wextra -Werror -O2

$(NAME): $(OBJ)
	clang++ -Wall -Wextra -Werror -I./srcs -g -O2 -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
