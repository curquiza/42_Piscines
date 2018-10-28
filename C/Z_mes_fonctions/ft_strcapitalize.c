/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:46:21 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/10 16:49:28 by curquiza         ###   ########.fr       */
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

int		ft_is_special_char(char c)
{
	if (c < 48 || (c > 59 && c < 64) || (c > 90 && c < 97) || c > 122)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (i < ft_strlen(str))
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (ft_is_special_char(str[i - 1]) == 0)
				str[i] = str[i] + 32;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (ft_is_special_char(str[i - 1]) == 1)
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
