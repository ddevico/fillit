/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MMU-writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:22:17 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/07 12:50:56 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		mattry(t_mat *m, t_piece *p)
{
	char	**mat;
	size_t	size;
	int		id;

	mat = m->mat;
	size = m->size;
	id = 0;
	if (p->coord[1] + p->size[1] > size)
		return (-2);
	if (p->coord[0] + p->size[0] > size)
		return (-1);
	while (id < 4)
	{
		if (mat[((p->pieces[id] % 5 - 1)) + p->coord[0]][((p->pieces[id] / 5)) \
				+ p->coord[1]] != '.')
		{
			return (0);
		}
		id++;
	}
	return (1);
}

void	matput(t_mat *m, t_piece *p, char c)
{
	char	**mat;
	size_t	size;
	int		id;

	id = 0;
	mat = m->mat;
	size = m->size;
	while (id < 4)
	{
		mat[((p->pieces[id] - 1) % 5) + p->coord[0]][((p->pieces[id]) / 5) + \
			p->coord[1]] = c;
		id++;
	}
}

void	coordinc(t_piece *p, size_t size)
{
	p->coord[0] = p->coord[0] + 1;
	if (p->coord[0] >= size)
	{
		p->coord[0] = 0;
		p->coord[1]++;
	}
}

int		checkbelow(t_mat *m, t_piece *p)
{
	char	**mat;
	size_t	size;
	int		id;

	id = 0;
	mat = m->mat;
	size = m->size;
	while (id < 4)
	{
		if (mat[((p->pieces[id] - 1) % 5) + p->coord[0]][((p->pieces[id]) / 5) \
				+ p->coord[1]] != p->id)
			return (0);
		id++;
	}
	return (1);
}

int		matfind(t_mat *m, t_piece *p)
{
	int ret;

	if (checkbelow(m, p) == 1)
	{
		matput(m, p, '.');
		p->status = 0;
		coordinc(p, m->size);
	}
	while (1)
	{
		ret = mattry(m, p);
		if (ret == 1 || ret == -2)
			break ;
		coordinc(p, m->size);
	}
	if (ret == 1)
		matput(m, p, p->id);
	if (ret == -2)
		return (0);
	return (1);
}
