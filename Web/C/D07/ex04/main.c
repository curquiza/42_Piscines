#include <unistd.h>
#include <stdio.h>


char	**ft_split_whitespaces(char *str);
int		ft_nb_words(char *str);

	
int		main(int argc, char **argv)
{
	//printf("%d", '\v');
	char	**range;
	int		i;
	int		nb_words;

	i = 0;
	if (argc != 2)
		return (0);
	nb_words = ft_nb_words(argv[1]);
	range = ft_split_whitespaces(argv[1]);
	while (range[i] != 0)
	{
		printf("%s\n", range[i]);
		i++;
	}
	//ft_putstr(argv[1]);
	return (0);
}
