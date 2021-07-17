##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make for call make
##

all:
	make -C antman
	make -C giantman
clean:
	make clean -C antman
	make clean -C giantman

fclean:
	make fclean -C antman
	make fclean -C giantman

re:
	make re -C antman
	make re -C giantman
