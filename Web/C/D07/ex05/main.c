void	ft_print_words_tables(char **tab);
char	**ft_split_whitespaces(char *str);

int		main(int argc, char **argv)
{
	char	**range;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	range = ft_split_whitespaces(argv[1]);
	ft_print_words_tables(range);
	return (0);
}
