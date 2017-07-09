/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:50:57 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/07 12:51:24 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	resetpiece(t_piece *p)
{
	p->coord[0] = 0;
	p->coord[1] = 0;
}

int		trypiece(t_mat *mat, t_piece *p)
{
	int ret;

	resetpiece(p);
	ret = matfind(mat, p);
	while (ret != 0 && p != 0)
	{
		p->status = 1;
		if (trysize(mat, g_input) == 1)
			return (1);
		if (ret == 0)
		{
			matput(mat, p, '.');
			p->status = 0;
		}
		ret = matfind(mat, p);
	}
	return (0);
}

int		allclear(t_list *lst)
{
	t_piece	*p;

	while (lst != 0)
	{
		p = lst->content;
		if (p->status != 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		trysize(t_mat *mat, t_list *lst)
{
	t_piece	*p;
	t_piece	*calledon;

	calledon = lst->content;
	if (allclear(g_input) == 1)
		return (1);
	while (1)
	{
		p = lst->content;
		if (p->status == 0)
		{
			if ((trypiece(mat, p)) == 1)
				return (1);
		}
		lst = lst->next;
		if (lst == 0)
		{
			lst = g_input;
		}
		if (lst->content == calledon)
		{
			break ;
		}
	}
	return (0);
}

int		resolve(t_list *lst)
{
	t_mat *mat;

	if ((mat = matcreate(setminsize(lst))) == 0)
		return (0);
	while (trysize(mat, lst) == 0)
	{
		if ((mat = ft_reallocmat(mat)) == 0)
			return (0);
	}
	matprint(mat);
	matdel(mat);
	return (1);
}
