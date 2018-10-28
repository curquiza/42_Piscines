#include <stdio.h>
#include <string.h>

int		ft_str_is_uppercase(char *str);

int		main(void)
{
	char	str1[] = " DHDH DHDi";

	printf("%s \n", str1);
	printf("%d \n", ft_str_is_uppercase(str1));
	return (0);
}
