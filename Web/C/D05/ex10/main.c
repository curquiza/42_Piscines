#include <stdio.h>
#include <string.h>

char 	*ft_strcapitalize(char *str);

int		main(void)
{
	char	str1[] = "heLLo yeye42hdhd lEs 42ii test,teSt-tEst+clem` !!!!";

	printf("%s \n", str1);
	printf("%s \n", ft_strcapitalize(str1));
	return (0);
}
