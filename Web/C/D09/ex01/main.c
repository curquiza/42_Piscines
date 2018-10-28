#include <stdlib.h>

void	ft_takes_place(int hour);

int		main(int argc, char **argv)
{
	int		index;

	index = argc;
	ft_takes_place(atoi(argv[1]));
	return (0);
}
