/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 09:57:10 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/23 11:41:48 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>

#define SIZE 10

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_print_error(char *argv)
{
	write(1, "cat: ", 5);
	write(1, argv, ft_strlen(argv));
	write(1, ": No such file or directory\n", 28);
}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		ret;
	char	buf[SIZE + 1];

	fd = 0;
	i = 1;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			ft_print_error(argv[i]);
		else
		{
			while ((ret = read(fd, buf, SIZE)) != 0)
			{
				buf[ret] = '\0';
				ft_putstr(buf);
			}
			if (close(fd) == -1)
				return (0);
		}
		i++;
	}
}
