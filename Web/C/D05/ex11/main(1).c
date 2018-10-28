#include <stdio.h>
#include <string.h>

int		ft_str_is_alpha(char *str);

int		main(void)
{
	char	str1[] = "ddkkd";

	printf("%s \n", str1);
	printf("%d \n", ft_str_is_alpha(str1));
	return (0);
}
