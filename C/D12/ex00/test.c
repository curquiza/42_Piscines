#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 100

int		main(void)
{
	int		fd;
	int		ret;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (SIZE + 1));
	fd = open("TRUC", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	if (fd == -1)
	{
		printf("erreur1");
		return (0);
	}
/*	if (write(fd, "truc", 4) == -1)
	{
		printf("erreur2");
		return (0);
	}*/
	ret = read(fd, buffer, SIZE);
	if (ret == -1)
	{
		printf("erreur3");
		return (0);
	}
	buffer[ret] = '\0';
	printf("%s\n", buffer);
	printf("%d", ret);
	if (close(fd) == -1)
	{
		printf("erreur4");
		return (0);
	}
}
