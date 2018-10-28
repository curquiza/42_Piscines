/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 21:16:08 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/15 09:53:46 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		length;
	char	*tab;

	length = 0;
	i = 1;
	while (i < argc)
	{
		length = length + ft_strlen(argv[i]) + 1;
		i++;
	}
	tab = (char *)malloc(sizeof(char) * length);
	i = 1;
	while (i < argc)
	{
		tab = ft_strcpy(tab, argv[i]);
		tab = tab + ft_strlen(argv[i]);
		if (i != argc - 1)
			*tab = '\n';
		tab++;
		i++;
	}
	tab = tab - length;
	return (tab);
}
