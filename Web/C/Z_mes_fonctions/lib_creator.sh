rm -rf libft.a
rm -rf main.c

gcc -Wall -Wextra -Werror -c *c

ar rc libft.a *.o
ranlib libft.a

rm -rf *o
rm -rf a.out
