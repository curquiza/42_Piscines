#include <stdio.h>
#include <string.h>

int		ft_str_is_numeric(char *str);

int		main(void)
{
	char	str1[] = "4578455";

	printf("%s \n", str1);
	printf("%d \n", ft_str_is_numeric(str1));
	return (0);
}
