#include <stdio.h>
#include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_any(char **tab, int (*f)(char*));

int		ft_test(char *str)
{
	if (ft_strcmp(str, "42") == 0)
		return (1);
	else
		return (0);
}

int		main(void)
{
	char	**tab;
	int		length;

	length = 3;
	tab = (char**)malloc(sizeof(char*) * (length + 1));
	tab[0] = "12";
	tab[1] = "42";
	tab[2] = "elsa";
	tab[3] = 0;
	printf("%d\n", ft_any(tab, &ft_test)); 
}
