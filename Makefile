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
	make re -C ./games/qix
	make re -C ./games/solar_fox
	make re -C ./games/snake
	make re -C ./games/centipede

graphicals:
	make -C ./lib/my_ncurses

clean:
	make clean -C  ./core
	make clean -C ./lib/my_ncurses

fclean:
	make fclean -C  ./core
	make fclean -C ./lib/my_ncurses
	make fclean -C ./games/qix
	make fclean -C ./games/solar_fox
	make fclean -C ./games/snake
	make fclean -C ./games/centipede


re: fclean all

.PHONY: all clean fclean re
