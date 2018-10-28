#include <stdio.h>
#include <string.h>

char 	*ft_strncpy(char *dest, char *src, unsigned int n);

int		main(void)
{
	char	str1[50] = "clementine";
	char	str2[] = "on";
	char	str3[50] = "clementine";
	char	str4[] = "on";


	printf("%s %s\n", str1, str2);
	ft_strncpy(str1, str2, 5);
	printf("%s %s\n\n", str1, str2);
	printf("%s %s\n", str3, str4);
	strncpy(str3, str4, 5);
	printf("%s %s\n", str3, str4);
	return (0);
}
