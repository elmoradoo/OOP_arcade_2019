##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile core
##

NAME	=	arcade

DIR 	= 	src/

SRC		=	$(DIR)main.cpp	\
			$(DIR)dlHandler.cpp	\
			# $(DIR)core.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Wall -Wextra -I./include -I../games/qix/include

all:	$(NAME)
$(NAME):	$(OBJ)
	g++ -o ../$(NAME) $(OBJ) -ldl

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all

.PHONY: all clean fclean re