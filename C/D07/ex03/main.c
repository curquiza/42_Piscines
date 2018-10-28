#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_concat_params(int argc, char **argv);

int		ft_strlen(char *str);

int		main(int argc, char **argv)
{
	int		index;

	index = argc;
	printf("%s", ft_concat_params(argc, argv));
	return (0);
}
