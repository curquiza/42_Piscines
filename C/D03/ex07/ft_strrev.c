/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 22:36:34 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/05 10:37:37 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strrev(char *str)
{
	char	buffer;
	int		i;
	int		length;

	length = ft_strlen(str);
	i = 0;
	while (i < length)
	{
		buffer = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buffer;
		i++;
		length--;
	}
	return (str);
}
