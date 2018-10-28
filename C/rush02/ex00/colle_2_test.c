/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 17:01:23 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/20 21:47:11 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //ATTENTION PRINTF
#include "colle_2.h"

#define SIZE 400

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int index;
	int tab[10];

	index = 0;
	if (nb < 0)
		ft_putchar('-');
	while (index < 10 && (nb >= 10 || nb <= -10))
	{
		tab[index] = (nb % 10);
		nb = nb / 10;
		index++;
	}
	tab[index] = nb;
	while (index >= 0)
	{
		if (tab[index] < 0)
			ft_putchar((tab[index] * -1) + '0');
		else
			ft_putchar(tab[index] + '0');
		index--;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (s1[length] != '\0')
		length++;
	while (i <= length)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_print_line(char char1, char char2, char char3, int x)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * x);
	i = 0;
	while (i < x)
	{
		if (i == 0)
			str[i] = char1;
		else if (i == x - 1)
			str[i] = char3;
		else
			str[i] = char2;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_colle(int x, int y, char *str, t_colle colle)
{
	int 	j;

	j = 0;
	if (x > 0 && y > 0)
	{
		while (j < y)
		{
			if (j == 0)
				str = ft_strcat(str, ft_print_line(colle.up_left, colle.row, colle.up_right, x));
			else if (j == y - 1)
				str = ft_strcat(str, ft_print_line(colle.b_left, colle.row, colle.b_right, x));
			else
				str = ft_strcat(str, ft_print_line(colle.col, ' ', colle.col, x));
			while(*str !='\0')
			   str++;
			*str = '\n';
			j++;
		}
		str++;
		*str = '\0';
	}
}

void	ft_init_colle00(t_colle *colle, int x, int y)
{
	colle->up_left = 'o';
	colle->up_right = 'o';
	colle->b_left = 'o';
	colle->b_right = 'o';
	colle->col = '|';
	colle->row = '-';
	colle->nb_col = x;
	colle->nb_row = y;
}

void	ft_init_colle01(t_colle *colle, int x, int y)
{
	colle->up_left = '/';
	colle->up_right = '\\';
	colle->b_left = '\\';
	colle->b_right = '/';
	colle->col = '*';
	colle->row = '*';
	colle->nb_col = x;
	colle->nb_row = y;
}

void	ft_init_colle02(t_colle *colle, int x, int y)
{
	colle->up_left = 'A';
	colle->up_right = 'A';
	colle->b_left = 'C';
	colle->b_right = 'C';
	colle->col = 'B';
	colle->row = 'B';
	colle->nb_col = x;
	colle->nb_row = y;
}

void	ft_init_colle03(t_colle *colle, int x, int y)
{
	colle->up_left = 'A';
	colle->up_right = 'C';
	colle->b_left = 'A';
	colle->b_right = 'C';
	colle->col = 'B';
	colle->row = 'B';
	colle->nb_col = x;
	colle->nb_row = y;
}

void	ft_init_colle04(t_colle *colle, int x, int y)
{
	colle->up_left = 'A';
	colle->up_right = 'C';
	colle->b_left = 'C';
	colle->b_right = 'A';
	colle->col = 'B';
	colle->row = 'B';
	colle->nb_col = x;
	colle->nb_row = y;
}

void	ft_calc_row_col(t_colle *colle, char *buffer)
{
	int		i;

	i = 0;
	colle->nb_col = 0;
	colle->nb_row = 0;
	while (buffer[i] != '\n')
		i++;
	colle->nb_col = i;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			colle->nb_row = colle->nb_row + 1;
		i++;
	}
}

char	**ft_complete_all_colles(int x, int y)
{
	char	**str;
	t_colle	*colle;
	int		i;

	i = 0;
	colle = (t_colle *)malloc(sizeof(t_colle) * 5);
	str = (char **)malloc(sizeof(char*) * 6);
	ft_init_colle00(colle, x, y);
	ft_init_colle01(colle + 1, x, y);
	ft_init_colle02(colle + 2, x, y);
	ft_init_colle03(colle + 3, x, y);
	ft_init_colle04(colle + 4, x, y);
	while (i <= 4)
	{
		str[i] = (char *)malloc(sizeof(char) * (SIZE + 1));
		ft_colle(x, y, str[i], colle[i]);
		i++;
	}
	return (str);
}


void	ft_find_colle(char *buff, char **str, int x, int y)
{
	int		i;
	int		cpt;

	cpt = 0;
	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(str[i], buff) == 0)
		{
			if (cpt > 0)
				ft_putstr(" || ");
			ft_putstr("[colle-0");
			ft_putnbr(i);
			ft_putstr("] [");
		   	ft_putnbr(x);
			ft_putstr("] [");
		   	ft_putnbr(y);
			ft_putchar(']');
			cpt++;
		}
		i++;	
	}
	if (cpt == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
}

int		main(void)
{
	char	*buf;
	int		ret;
	t_colle	colle_buf;
	char	**all_colles;

	buf = (char *)malloc(sizeof(char) * (SIZE + 1));
	ret = read(0, buf, SIZE);
	if (ret == 0)
	{
		ft_putstr("aucune\n");
		return (0);
	}
	buf[ret] = '\0';	
	ft_calc_row_col(&colle_buf, buf);
	all_colles = ft_complete_all_colles(colle_buf.nb_col, colle_buf.nb_row);

	// TEST du buffer + nb_ligne, nb_col
	/*printf("%s\n", buf);
	printf("%d %d\n", colle_buf.nb_col, colle_buf.nb_row);
	int		i = 0;
	while (i < 5)
	{
		printf("%s\n", all_colles[i]);
		write(1, "\n", 1);
		i++;
	}*/
	
	//TEST de ft_colle -> OK
	/*t_colle	colleTEST;
	char	*STR;
	STR = (char *)malloc(sizeof(char) * (SIZE + 1));
	ft_init_colle00(&colleTEST, 4, 5);
	ft_colle(4, 5, STR, colleTEST);
	printf("%s", STR);*/
	
	ft_find_colle(buf, all_colles, colle_buf.nb_col, colle_buf.nb_row);
	return (0);
}
