#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int		main(void)
{
	char	str1[34] = "clem";
	char	str2[] = "elsa";
	char	str3[34] = "clem";
	char	str4[] = "elsa";

	printf("%s %s\n", str1, str2);
	printf("%s \n", ft_strcat(str1, str2));
	printf("%s \n", strcat(str3, str4));
	return (0);
}
