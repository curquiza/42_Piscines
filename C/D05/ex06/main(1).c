#include <stdio.h>
#include <string.h>

char 	ft_strcmp(char *s1, char *s2);

int		main(void)
{
	char	str1[] = "test";
	char	str2[] = "test1";
	char	str3[] = "test";
	char	str4[] = "test1";

	printf("%s %s\n", str1, str2);
	printf("%d \n\n", ft_strcmp(str1, str2));
	printf("%s %s\n", str3, str4);
	printf("%d \n", strcmp(str3, str4));
	return (0);
}
