#include <stdio.h>
#include <string.h>

char 	*ft_strstr(char *str, char *to_find);

int		main(void)
{
	char	str1[] = "elsaetclem";
	char	str2[] = "\0";
	char	str3[] = "elsaetclem";
	char	str4[] = "\0";


	printf("%s %s\n", str1, str2);
	printf("%s \n\n", ft_strstr(str1, str2));
	printf("%s %s\n", str3, str4);
	printf("%s \n", strstr(str3, str4));
	return (0);
}
