#include <stdio.h>
#include <string.h>

char 	*ft_strcpy(char *dest, char *src);

int		main(void)
{
	char	str1[40] = "elsa";
	char	str2[] = "auxrore";
	char	str3[40] = "elsa";
	char	str4[] = "auxrore";


	printf("%s %s\n", str1, str2);
	ft_strcpy(str1, str2);
	printf("%s %s\n\n", str1, str2);
	printf("%s %s\n", str3, str4);
	strcpy(str3, str4);
	printf("%s %s\n", str3, str4);
	return (0);
}
