##
## EPITECH PROJECT, 2020
## MY MAKEFILES
## File description:
## the ultimate makefile
##

.RECIPEPREFIX =	-


NAME	=	giantman
OBJECT	=	obj
SOURCES	=	sources

###################
## Compil option ##
###################

CC      =       gcc
CFLAG   =       -W -Wall -Wextra -g3 \
                -Wno-unused-variable \
###########
## imput ##
###########

SH_CLEAN_PATH =	/home/nico/utli_script/mr_clean

DIR_INCLUDE = -I ../include/
DIR_LIB = -L ../lib/c_star/ -lc_star -L ../lib/my/ -lmy

BLACK_LIST_SRC = 

FILE = main.c file_to_tab.c list_tree.c list.c hufman.c concat_params.c decrypto_tree.c error_handling.c\

###########
### OBJ ###
###########

ALL_OBJ =       $(patsubst %.c, $(OBJECT)/%.o, $(SRC))

SRC	=	$(filter-out $(BLACK_LIST_SRC), $(FILE))

############
### RULE ###
############

.PHONY: all re clean folder fclean 
.DEFAULT: all

all:	Folder $(NAME)
-@echo	-e "\e[32mlinking compliete\e[39m"

$(NAME): Form_preCompil subdir $(ALL_OBJ)
-@gcc -o $(NAME) $(ALL_OBJ) $(DIR_LIB)

Folder:	|	$(OBJECT)

subdir:
-@echo -e "\n\e[1;94mLib compilation\e[0m"
-@make -C ../lib/c_star
-@make -C ../lib/my

clean:
-@echo -e "\e[33m-->Cleaning time\e[00m"
-rm -f ./$(OBJECT)/*.o

fclean:	clean
-rm -rf $(OBJECT)
-rm -rf $(NAME)
-make fclean -C ../lib/my
-make fclean -C ../lib/c_star

re:	clean subdir all

###################
### INTERN RULE ###
###################
        ##dialogue rule
Form_preCompil:
-@echo -e "\n\e[1;94mCompilation start\e[0m"

        ##dir generate
$(OBJECT):
-@echo -e "\e[95mOBJ Directory Generate\e[0m"
-@mkdir -p $(OBJECT)

       ##target: $() = destiantion final; depandance: $(sources)/ = fichier de base
$(OBJECT)/%.o	: %.c
-@$(CC) -c -o $@ $< $(CFLAG) $(DIR_INCLUDE)
-@echo -e "\t\e[36mCompilate \e[3;97;4m$@\e[00m; \e[1;92mSUCCES\e[00m"
