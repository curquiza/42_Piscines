#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int		main(void)
{
	char			str1[40] = "elsaelsa";
	char			str2[] = "auroreetclem";
	char			str3[40] = "elsaelsa";
	char			str4[] = "auroreetclem";
	unsigned int	n;

	n = 9;
	printf("%d\n", ft_strlcpy(str1, str2, n));
	printf("%ld\n", strlcpy(str3, str4, n));
	printf("%s %s\n", str1, str2);
	printf("%s %s\n", str3, str4);
	return (0);
}
