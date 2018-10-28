NAME = libft.a
FLAG = -Wall -Werror -Wextra
HEADERS = includes
D_SRC = srcs/
SRC = ft_putstr.c ft_putchar.c ft_strcmp.c ft_strlen.c ft_swap.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : 
	gcc $(FLAG) -c $(addprefix $(D_SRC), $(SRC)) -I $(HEADERS)
	ar rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
