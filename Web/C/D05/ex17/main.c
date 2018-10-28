#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, int nb);

int		main(void)
{
	char	str1[34] = "test";
	char	str2[] = "bonjour";
	char	str3[34] = "test";
	char	str4[] = "bonjour";
	int		n;

	n = 6;
	//printf("%s %s\n", str1, str2);
	printf("%s \n", ft_strncat(str1, str2, n));
	printf("%s \n", strncat(str3, str4, n));
	return (0);
}
