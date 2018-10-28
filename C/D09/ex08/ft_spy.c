/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:52:42 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/12 14:23:39 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (i <= ft_strlen(s1))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_del_spaces(char *str)
{
	int		length;

	length = ft_strlen(str);
	while (str[length] < 33)
		length--;
	str[length + 1] = '\0';
	while (*str < 33)
		str++;
}

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		ft_del_spaces(argv[i]);
		ft_strlowcase(argv[i]);
		if (ft_strcmp(argv[i], "president") == 0
			|| ft_strcmp(argv[i], "attack") == 0
			|| ft_strcmp(argv[i], "powers") == 0)
			count++;
		i++;
	}
	if (count > 0)
		write(1, "Alert!!!\n", 9);
	return (0);
}
