NAME	=	fridge

OBJ	=	$(SRC:.c=.o)

SRC	=	./src/main.c\
		./src/utilities.c\
		./src/recipe/pizza.c\
		./src/recipe/pasta.c\
		./src/save.c\
		./src/basics_cmd/add_fridge.c\
		./src/basics_cmd/disp_fridge.c\
		./src/my_stwa_bis.c\
		./src/parser.c\
		./src/find_cmd.c\
		./src/my_stwa.c\
		./src/utilities2.c

CFLAGS +=	-Wall -Wextra -Wpedantic -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: re fclean clean all
