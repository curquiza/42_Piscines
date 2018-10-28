#include <stdio.h>
#include <string.h>

int		ft_str_is_printable(char *str);

int		main(void)
{
	char	str1[] = "d jdjd";

	printf("%s \n", str1);
	printf("%d \n", ft_str_is_printable(str1));
	return (0);
}
