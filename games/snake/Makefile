##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compilation
##

NAME	=	snake

SRC	=	src/main.cpp	\
		src/snake_ncurses.cpp	\
		src/snake_class.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=  -I./include -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	g++ $(CPPFLAGS) -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f src/*.o
	rm -f vgcore*
	rm -f ~*

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
