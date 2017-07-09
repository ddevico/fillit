/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			test_overflow2(t_struct *d, int x, int y)
{
	if (y + d->x_piece < d->x_map && x + d->y_piece < d->y_map)
		return (1);
	return (0);
}

void		test_overflow(t_struct *d, int x, int y)
{
	if (y + d->x_piece > d->x_map || x + d->y_piece > d->y_map)
	{
		d->coord_x = 0;
		d->coord_y = 0;
	}
	d->coord_x = x;
	d->coord_y = y;
}

int			countnumber(char *str)
{
	int		c;
	int		nb;

	c = 0;
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb + *str++ - '0';
		if (*str >= '0' && *str <= '9')
			nb = nb * 10;
		c++;
	}
	return (c);
}
