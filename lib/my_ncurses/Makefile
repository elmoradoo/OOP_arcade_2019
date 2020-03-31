##
## EPITECH PROJECT, 2019
## ohnomason
## File description:
## ohnomason.makefile
##

LIBNAME 	= 	lib_arcade_ncurses.so

SRC	= 	my_ncurses.cpp	\

OBJ	= 	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude/ -W -Wall -Wextra -fPIC -lncurses

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	 g++ $(OBJ) -shared -o $(LIBNAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re