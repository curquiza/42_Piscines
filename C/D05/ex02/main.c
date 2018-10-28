#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str);

int		main(void)
{
	char	str[] = "  +2147483647";

	printf("%d\n", '\n');
	printf("%d\n", '\0');
	printf("%d\n", '\t');
	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
	return (0);
}
