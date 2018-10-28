#include <iostream>
#include <cctype>

char  *str_to_upper(char *str)
{
	int		i;

	for (i = 0; str[i] != '\0'; i++)
		str[i] = toupper(str[i]);
	return (str);
}

int		main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i = 1; i < argc; i++)
			std::cout << str_to_upper(argv[i]);
	}
	std::cout << std::endl;
}