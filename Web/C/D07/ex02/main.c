#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_ultimate_range(int **range, int min, int max);

int		main(int argc, char **argv)
{
	int		nb;
	int		*tab;
	int		i;

	if (argc != 3)
		return (0);
	i = 0;
	tab = NULL;
	nb = 0;
	//tab = (int**)malloc(sizeof(tab) * 220);
	nb  = ft_ultimate_range(&tab, atoi(argv[1]), atoi(argv[2]));
	/*while (i < atoi(argv[2]) - atoi(argv[1]))
	{
		printf("%d ", tab[i]);
		i++;
	}*/
	printf("\n%d", nb);
	return (0);
}
