#include <stdio.h>

void	ft_advanced_sort_wordtab(char **tab, int (*f)(char *, char *));
char	**ft_split_whitespaces(char *str);
void	ft_print_words_tables(char **tab);
int		ft_strlen(char *str);

int		ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (s1[length] != '\0')
		length++;
	while (i <= length)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		ft_cmplength(char *s1, char *s2)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	char	**tab;

	if (argc != 2)
		return (0);
	tab = ft_split_whitespaces(argv[1]);
	ft_advanced_sort_wordtab(tab, &ft_strcmp);
	ft_print_words_tables(tab);
	return (0);
}
