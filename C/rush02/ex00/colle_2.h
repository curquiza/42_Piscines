/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 15:17:30 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/21 11:52:25 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE_2_H
# define COLLE_2_H

typedef struct s_colle	t_colle;

struct					s_colle
{
	char	up_left;
	char	up_right;
	char	b_left;
	char	b_right;
	char	col;
	char	row;
	int		nb_col;
	int		nb_row;
};

# define SIZE_BUF 100000000
# define SIZE 10

char					*ft_print_line(char char1, char char2, char char3,
										int x);
void					ft_colle(int x, int y, char *str, t_colle colle);
void					ft_calc_row_col(t_colle *colle, char *buffer);
char					**ft_complete_all_colles(int x, int y);
void					ft_find_colle(char *buff, char **str, int x, int y);

#endif
