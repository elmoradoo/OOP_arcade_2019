##
## EPITECH PROJECT, 2019
## ohnomason
## File description:
## ohnomason.makefile
##

LIBNAME 	= 	../../lib_arcade_opengl.so

SRC	= 	my_opengl.cpp	\

OBJ	= 	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude -I./../ -W -Wall -Wextra -fPIC

LDFLAGS	=	-lSDL -lSDLmain -lSDL_image -lGL -lGLU 

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	g++ -shared $(OBJ) -o $(LIBNAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re