##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compilation
##

NAME	=	snake

SRC	=	src/snake.cpp	\
		src/snake_class.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=  -I./include -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	g++ $(CPPFLAGS) -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f *.o
	rm -f vgcore*
	rm -f ~*

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
