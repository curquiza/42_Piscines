NAME = prog
FLAG = -Wall -Werror -Wextra
SRC = *.c
OBJ = $(SCR:.c=.o)
LIB = ~/mes_fonctions/libft.a
#D_HEADER = 
#D_SRC =

all : $(NAME)

$(NAME) :
	gcc $(FLAG) $(LIB) $(SRC) -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
