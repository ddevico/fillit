/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_fillmap_piece(t_struct *play)
{
	int			i;
	int			j;
	int			k;
	int			l;

	i = 0;
	j = 0;
	k = play->coord_y;
	l = play->coord_x;
	while (i < play->x_piece)
	{
		j = 0;
		while (j < play->y_piece)
		{
			if (play->piece[i][j] != '.')
				play->map[k][l] = play->piece[i][j];
			j++;
			l++;
		}
		l = play->coord_x;
		k++;
		i++;
	}
}

void		ft_remplace_piece(t_struct *play)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < play->x_piece)
	{
		j = 0;
		while (j < play->y_piece)
		{
			if (play->piece[i][j] == '*')
				play->piece[i][j] = 'o';
			j++;
		}
		i++;
	}
}

void		ft_up_piece(t_struct *play)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < play->x_map)
	{
		j = 0;
		while (j < play->y_map)
		{
			if (play->map[i][j] == 'o')
				play->map[i][j] = 'O';
			if (play->map[i][j] == 'x')
				play->map[i][j] = 'X';
			j++;
		}
		i++;
	}
}
