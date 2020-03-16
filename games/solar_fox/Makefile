##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compilation
##

NAME	=	solar_fox

SRC	=	src/main.cpp	\
		src/ngame.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=  -I./include -Wall -Wextra -g3

all: $(NAME)

$(NAME):	$(OBJ)
	g++ $(CPPFLAGS) -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f *.o
	rm -f $(SRC:.cpp=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
