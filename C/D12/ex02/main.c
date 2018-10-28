/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 18:07:45 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/23 19:49:24 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "ft_basic.h"

void	ft_multi_arg(char *str, int i)
{
	if (i > 3)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, str, ft_strlen(str));
	write(1, " <==\n", 5);
}

int		ft_nbr_octet(char *str)
{
	int		nbr;
	int		ret;
	int		fd;
	char	buf[2];

	fd = open(str, O_RDONLY);
	nbr = 0;
	if (fd != 1)
	{
		while ((ret = read(fd, buf, 1)))
		{
			buf[ret] = '\0';
			nbr = nbr + ret;
		}
	}
	close(fd);
	return (nbr);
}

void	ft_print(int nbr_octet, char *src)
{
	int		ret;
	int		fd;
	char	buf[2];
	int		i;

	i = 0;
	if ((fd = open(src, O_RDONLY)) == 1)
		return ;
	while ((ret = read(fd, buf, 1)))
	{
		buf[ret] = '\0';
		if (i >= nbr_octet - 1)
			write(1, buf, ft_strlen(buf));
		i++;
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	int		nbr_octet;
	int		i;

	if (argc < 4)
	{
		write(2, "tail: option requires an argument -- c\n", 39);
		return (0);
	}
	if (ft_strcmp(argv[1], "-c") != 0)
		return (0);
	i = 3;
	while (i < argc)
	{
		if (argc > 4)
			ft_multi_arg(argv[i], i);
		nbr_octet = ft_nbr_octet(argv[i]);
		if (argv[2][0] == '+')
			ft_print(ft_atoi(argv[2]), argv[i]);
		else
			ft_print(nbr_octet + 1 - ft_abs(ft_atoi(argv[2])), argv[i]);
		i++;
	}
	return (0);
}
