#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src);

int		main(int argc, char **argv)
{
	if (argc != 2)
		return(0);
	printf("%s\n", strdup(argv[1]));
	printf("%s", ft_strdup(argv[1]));
	return (0);
}
