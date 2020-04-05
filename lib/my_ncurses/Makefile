##
## EPITECH PROJECT, 2019
## ohnomason
## File description:
## ohnomason.makefile
##

LIBNAME 	= 	../../lib_arcade_ncurses.so

SRC	= 	my_ncurses.cpp	\

OBJ	= 	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude -I./../ -W -Wall -Wextra -fPIC

LDFLAGS	=	-lncursesw

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	g++ -shared $(OBJ) -o $(LIBNAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re