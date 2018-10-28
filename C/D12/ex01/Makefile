NAME = ft_cat
FLAG = -Wall -Werror -Wextra
SRC = main.c
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
