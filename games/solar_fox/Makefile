##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compilation
##

NAME	=	../lib_arcade_solarfox.so

SRC	=	src/ngame.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=  -I./include -I../../lib/ -I../ -I../../core/include -Wall -Wextra -fPIC

all: $(NAME)

$(NAME):	$(OBJ)
	g++ -shared  $(OBJ) -o $(NAME)

clean:
	rm -f *.o
	rm -f $(SRC:.cpp=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
