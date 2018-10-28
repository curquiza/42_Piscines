#include <stdio.h>
#include <string.h>

char 	*ft_strupcase(char *str);

int		main(void)
{
	char	str1[] = "Hello les 42 !!!!";

	printf("%s \n", str1);
	printf("%s \n", ft_strupcase(str1));
	return (0);
}
