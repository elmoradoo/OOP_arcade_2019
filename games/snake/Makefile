##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compilation
##

NAME	=	../lib_arcade_nibbler.so

SRC	=	src/snake.cpp	\
		src/snake_class.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=  -I./include -I../../lib/ -I../ -Wall -Wextra -fPIC

all: $(NAME)

$(NAME):	$(OBJ)
	g++ --shared -o $(NAME) $(OBJ)

clean:
	rm -f src/*.o
	rm -f vgcore*
	rm -f ~*

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
