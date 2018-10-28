/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 09:47:15 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/18 10:41:00 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*f)(char *, char *))
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = 0;
	if (tab[0] != 0)
	{
		while (tab[i] != 0)
		{
			if (f(tab[i - 1], tab[i]) > 0)
			{
				buffer = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = buffer;
				i = 0;
			}
			i++;
		}
	}
}
