/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 16:58:15 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/08 10:45:23 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int		tab[10];
	int		i;

	if (nb == 0)
		ft_putchar('0');
	else if (nb < 0)
		ft_putchar('-');
	i = 0;
	while (nb >= 1 || nb <= -1)
	{
		if (nb < 0)
		{
			nb = (nb + 1) * -1;
			tab[i] = '0' + nb % 10 + 1;
			nb = nb * -1 - 1;
		}
		else
			tab[i] = '0' + nb % 10;
		nb = nb / 10;
		i++;
	}
	while (i-- >= 0)
		ft_putchar(tab[i]);
}
