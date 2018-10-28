#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		*ft_range(int min, int max);

int		main(int argc, char **argv)
{
	int		*tab;
	int		i;

	if (argc != 3)
		return (0);
	i = 0;
	tab = ft_range(atoi(argv[1]), atoi(argv[2]));
	while (i < atoi(argv[2]) - atoi(argv[1]))
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
}
