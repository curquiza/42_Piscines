NAME = prog
FLAG = -Wall -Werror -Wextra
SRC = main.c btree_insert_data.c btree_create_node.c
OBJ = $(SCR:.c=.o)
LIB = ~/mes_fonctions/libft.a
#D_HEADER = 
#D_SRC =

all : $(NAME)

$(NAME) : $(SRC)
	gcc $(FLAG) $(LIB) $(SRC) -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
