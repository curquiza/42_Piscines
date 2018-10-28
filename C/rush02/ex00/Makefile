NAME = colle-2
FLAG = -Wall -Werror -Wextra
SRC = colle_2.c ft_basic.c ft_init_colle.c main.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	gcc $(FLAG) -c $(SRC)
	gcc $(FLAG) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
