/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 22:13:01 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/15 12:54:50 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = (int*)malloc(sizeof(int) * (max - min));
	while (i < max - min)
	{
		//*(*range + i) = min + i;
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}

// Dans mon main jai un tableau simple (tab*) et je vais passer en parametre 
// l'adresse de ce tableau (&tab) pour pouvoir modifier le tableau via son adresse
// Cest le meme principe que declarer un int et passer l'adreesse du int en param de la fonction
// pour modifier le int via son adresse.

/*int		ft_ultimate_range(int **range, int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	tab = (int*)malloc(sizeof(int) * (max - min));
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (i);
}*/
