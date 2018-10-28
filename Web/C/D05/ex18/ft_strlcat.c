/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 22:42:55 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/10 12:27:31 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	length_src;
	unsigned int	length_dest;
	unsigned int	i;
	unsigned int	j;

	length_src = ft_strlen(src);
	length_dest = ft_strlen(dest);
	i = length_dest;
	j = 0;
	while (i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (length_src > size)
		return (length_dest + size);
	else
		return (length_dest + length_src);
}
