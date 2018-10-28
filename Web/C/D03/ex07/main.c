/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 20:33:40 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/05 10:39:27 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(char *str);

char	*ft_strrev(char *str);

int		main(void)
{
	char	str[] = "trucmucheetmachin42etencoretrucmuche";

	ft_putstr(str);
	ft_putchar('\n');
	ft_putstr(ft_strrev(str));
	return (0);
}
