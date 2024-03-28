##
## EPITECH PROJECT, 2020
## make
## File description:
## make
##

SRC	=	$(wildcard *.c)

MYLIB	=	-L ./lib -lmy

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

HEADER	=	include

LIB	=	./lib

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C ./lib
	@gcc -o $(NAME) $(OBJ) $(MYLIB) -lncurses

clean:
	@rm -f $(OBJ)
	@rm -r $(HEADER)
	@make clean -C ./lib

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.SILENT: $(OBJ)