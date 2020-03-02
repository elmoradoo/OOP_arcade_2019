##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compilation
##

CORENAME	=	arcade

CORESRC		=	core/main.cpp

GAMESRC		=	games/main.cpp

LIBSRC		=	lib/main.cpp

SRC			=	$(CORESRC)	\
				$(GAMESRC)	\
				$(LIBSRC)	\

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	= -Wall -Wextra -g3

all:
	echo "TODO"

core:
	echo "Build $(CORESRC)"

games:
	echo "Build $(GAMESRC)"

graphicals:
	echo "Build $(LIBSRC)

clean:
	rm -f *.o
	rm -f $(SRC:.cpp=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
