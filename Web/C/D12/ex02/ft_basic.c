/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 19:29:33 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/23 19:32:07 by curquiza         ###   ########.fr       */
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

int		ft_abs(int number)
{
	if (number >= 0)
		return (number);
	return (-number);
}
