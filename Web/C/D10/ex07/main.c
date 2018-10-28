#include <stdio.h>

void	ft_sort_wordtab(char **tab);
char	**ft_split_whitespaces(char *str);
void	ft_print_words_tables(char **tab);

int		main(int argc, char **argv)
{
	char	**tab;

	if (argc != 2)
		return (0);
	tab = ft_split_whitespaces(argv[1]);
	ft_sort_wordtab(tab);
	ft_print_words_tables(tab);
	return (0);
}
