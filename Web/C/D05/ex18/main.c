#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int		main(void)
{
	char	str1[40] = "clementine";
	char	str2[] = "elsa";
	char	str3[40] = "clementine";
	char	str4[] = "elsa";
	int		n;
	
	n = 12;
	printf("%s %s\n", str1, str2);
	printf("%d \n", ft_strlcat(str1, str2, n));
	printf("%ld \n", strlcat(str3, str4, n));
	printf("%s\n", str1);
	printf("%s\n", str3);
	return (0);
}
