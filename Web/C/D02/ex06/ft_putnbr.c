/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 14:28:29 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/04 14:32:35 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_nb_of_char(int nb)
{
	int		count;

	count = 0;
	while (nb / 10 >= 1)
	{
		count++;
		nb = nb / 10;
	}
	return (count + 1);
}

int		ft_pow(int nb1, int nb2)
{
	int		i;
	int		result;

	i = 1;
	result = 1;
	while (i <= nb2)
	{
		result = result * nb1;
		i++;
	}
	return (result);
}

int		ft_putnbr(int nb)
{
	int		i;
	int		nb_of_char;

	i = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	nb_of_char = ft_nb_of_char(nb);
	while (i < nb_of_char)
	{
		ft_putchar('0' + nb / (ft_pow(10, nb_of_char - i)));
		nb = nb % ft_pow(10, nb_of_char - i);
		i++;
	}
	ft_putchar('0' + nb % 10);
	return (0);
}
