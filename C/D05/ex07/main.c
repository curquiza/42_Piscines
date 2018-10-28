#include <stdio.h>
#include <string.h>

int 	ft_strncmp(char *s1, char *s2, unsigned int n);

int		main(void)
{
	char	str1[] = " H";
	char	str2[] = " He";
	int		n;

	n = 3;
	printf("%s %s\n", str1, str2);
	printf("%d \n\n", ft_strncmp(str1, str2, n));
	printf("%s %s\n", str1, str2);
	printf("%d \n", strncmp(str1, str2, n));
	return (0);
}
