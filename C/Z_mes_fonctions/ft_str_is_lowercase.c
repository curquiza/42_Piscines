/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:41:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/09 17:42:44 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int		ft_str_is_lowercase(char *str)
{
	int		count;
	int		length;

	length = ft_strlen(str);
	count = 0;
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			count++;
		str++;
	}
	if (count == length)
		return (1);
	else
		return (0);
}
