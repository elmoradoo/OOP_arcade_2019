##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	=	qix

SRC	=	src/main.cpp	\
		src/qix.cpp	\
		# ../../lib/my_ncurses/my_ncurses.cpp\

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	= -I./include -I../../lib/my_ncurses/include -I../../core/include  -Wall -Wextra -g3

all: $(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
