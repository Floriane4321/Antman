##
## EPITECH PROJECT, 2020
## makefile
## File description:
## lib makefile
##

.RECIPEPREFIX = -

NAME = libc_star.a

SRC =	my_lignlen.c count_lign.c\

OBJ = $(SRC:.c=.o)

all:	$(NAME)

re: fclean all

clean:
-@rm -f $(OBJ)

fclean: clean
-rm -f $(NAME)

$(NAME): $(OBJ)
-@ar rc $(NAME) $^

%.o: %.c
-gcc -c $^ -g
