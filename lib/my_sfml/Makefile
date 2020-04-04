##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

LIBNAME 	= 	../../lib_arcade_sfml.so

SRC	= 	my_sfml.cpp	\

OBJ	= 	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude -I./../ -W -Wall -Wextra -fPIC

LDFLAGS	=	-lncurses

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	g++ -shared $(OBJ) -o $(LIBNAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re