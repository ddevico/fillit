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

static int		find_placepiece(int *y, int *x, int i, t_struct *play)
{
	int		j;
	int		k;
	int		l;

	j = 0;
	l = 0;
	while (j < play->x_piece)
	{
		k = 0;
		while (k < play->y_piece)
		{
			if (play->piece[j][k] == '*')
			{
				if (++l == i)
				{
					*y = j;
					*x = k;
					return (1);
				}
			}
			k++;
		}
		j++;
	}
	return (0);
}

static int		place_piece(int y, int x, int j, t_struct *play)
{
	int	i;
	int	piece_x;
	int	piece_y;
	int	count;

	j = 0;
	count = 0;
	i = 0;
	if (!(x < 0 || x > play->y_map || y < 0 || y < play->x_map))
		return (0);
	while (find_placepiece(&piece_y, &piece_x, ++i, play))
	{
		if (test_overflow2(play, x, y) && y + piece_y >= 0 && y + piece_y
			< play->x_map && x + piece_x >= 0 && x + piece_x < play->y_map)
		{
			if (play->map[y + piece_y][x + piece_x] != '.')
				count++;
		}
		else
			return (0);
		if (count > 1)
			return (0);
	}
	test_overflow(play, x, y);
	return (1);
}

static int		is_test_coord(t_struct *play)
{
	int	piece_x;
	int	piece_y;
	int	i;

	i = 0;
	piece_x = 0;
	piece_y = 0;
	find_placepiece(&piece_y, &piece_x, ++i, play);
	while (!(place_piece(play->coord_y - piece_y, play->coord_x - piece_x, i,
		play)))
	{
		if (!(find_placepiece(&piece_y, &piece_x, ++i, play)))
		{
			return (0);
		}
	}
	return (1);
}

static int		test_case(t_struct *play, int y, int x)
{
	play->coord_x = x;
	play->coord_y = y;
	if (is_test_coord(play))
	{
		ft_remplace_piece(play);
		ft_fillmap_piece(play);
		return (1);
	}
	return (0);
}

void			ft_resolve(t_struct *play)
{
	int		i;
	int		j;

	i = 0;
	ft_up_piece(play);
	while (i < play->x_map)
	{
		j = 0;
		while (j < play->y_map)
		{
			if (play->map[i][j] == play->play1 ||
				play->map[i][j] == ft_toupper((int)play->play1))
			{
				if (test_case(play, i, j))
					return ;
			}
			j++;
		}
		i++;
	}
}
