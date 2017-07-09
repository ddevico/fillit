/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:24:10 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/07 12:49:23 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	toall(t_piece *piece, int n)
{
	int i;

	i = 0;
	while (i <= 3)
	{
		piece->pieces[i] = (piece->pieces[i] + n);
		i++;
	}
}

static void	setborders(t_piece *piece)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i <= 3)
	{
		if ((n / 5) < (piece->pieces[i] / 5))
			n = (piece->pieces[i]);
		i++;
	}
	piece->size[1] = ((n / 5) + 1);
	i = 0;
	n = 0;
	while (i <= 3)
	{
		if ((n % 5) < (piece->pieces[i] % 5))
			n = (piece->pieces[i]);
		i++;
	}
	piece->size[0] = (n % 5);
}

static void	centerize(t_piece *piece)
{
	int	i;
	int	n;

	i = 0;
	n = 4;
	while (i <= 3)
	{
		if ((n % 5) > (piece->pieces[i] % 5))
			n = (piece->pieces[i]);
		i++;
	}
	toall(piece, -((n % 5) - 1));
	toall(piece, -((piece->pieces[0] / 5) * 5));
}

void		lstcenter(t_list *lst)
{
	int		i;
	t_piece	*p;

	i = 0;
	while (lst != 0)
	{
		p = lst->content;
		centerize(lst->content);
		setborders(lst->content);
		lst = lst->next;
		p->id = 'A' + i;
		p->coord[0] = 0;
		p->coord[1] = 0;
		i++;
	}
}
