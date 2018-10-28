#include <stdio.h>
#include <string.h>

char 	*ft_strlowcase(char *str);

int		main(void)
{
	char	str1[] = "HeLLo LEs 42 !!!!";

	printf("%s \n", str1);
	printf("%s \n", ft_strlowcase(str1));
	return (0);
}
