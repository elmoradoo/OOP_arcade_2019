##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	=	../lib_arcade_centipede.so

SRC	=	src/centipede.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	= -I./include -I../../lib/ -I../ -Wall -Wextra -fPIC

all: $(NAME)

$(NAME):	$(OBJ)
	g++ -shared $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
