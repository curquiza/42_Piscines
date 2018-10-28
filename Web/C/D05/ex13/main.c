#include <stdio.h>
#include <string.h>

int		ft_str_is_lowercase(char *str);

int		main(void)
{
	char	str1[] = "\0";

	printf("%s \n", str1);
	printf("%d \n", ft_str_is_lowercase(str1));
	return (0);
}
