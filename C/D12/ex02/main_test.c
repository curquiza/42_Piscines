/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:35:53 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/23 18:06:47 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

#define SIZE 1

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_atoi(char *str)
{
	int		test_neg;
	int		i;
	int		result;

	i = 0;
	test_neg = 1;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		test_neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10;
		result = result + str[i] - 48;
		i++;
	}
	return (test_neg * result);
}

void	ft_print_header(int argc, char *argv)
{
	if (argc > 4)
	{
		write(1, "==> ", 4);
		write(1, argv, ft_strlen(argv));
		write(1, " <==\n", 5);
	}
}

int		ft_read(int argc, char *argv, int fd, int c)
{
	int		ret;
	int		length;
	int		cpt;
	char	buf[SIZE + 1];

	ret = 0;
	ft_print_header(argc, argv);
	length = 0;
	while ((ret = read(fd, buf, SIZE)) != 0)
		length++;
	if(close(fd) == -1)
		return (0);
	fd = open(argv, O_RDONLY);
	cpt = 0;
	while ((ret = read(fd, buf, SIZE)) != 0)
	{
		cpt++;
		buf[ret] = '\0';
		if (cpt > length - c)
			ft_putstr(buf);	
	}
	if(close(fd) == -1)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		c;

	if (argc < 4)
		return (0);
	c = ft_atoi(argv[2]);
	if (c < 0)
		c = c * -1; 
	i = 3;
	while (i < argc)
	{
		if((fd = open(argv[i], O_RDONLY)) == -1)
		{
			write(1, "tail: ", 6);
			write(1, argv[i], ft_strlen(argv[i]));
			write(1, ": No such file or directory\n", 28);
		}
		else
			ft_read(argc, argv[i], fd, c);
		i++;
	}	
	return(0);
}
