/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:06:55 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/09 17:22:23 by curquiza         ###   ########.fr       */
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

int		ft_str_is_alpha(char *str)
{
	int		count;
	int		length;

	length = ft_strlen(str);
	count = 0;
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			count++;
		str++;
	}
	if (count == length)
		return (1);
	else
		return (0);
}
