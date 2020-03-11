##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compilation
##

CORE	=	arcade

GAME	=	libgames

all: core games graphicals

core:	$(CORE)

$(CORE):
	make -C ./core

games: $(GAME)

$(GAME):
	echo "Build $(GAMESRC)"

graphicals:
	echo "graphicals"

clean:
	make clean -C  ./core

fclean:
	make fclean -C  ./core

re: fclean all

.PHONY: all clean fclean re
