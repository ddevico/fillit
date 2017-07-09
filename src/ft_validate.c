/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:22:31 by qviguier          #+#    #+#             */
/*   Updated: 2015/12/10 18:06:21 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(t_piece *p, unsigned char id)
{
	int		i;
	char	chks;

	chks = 3 - id;
	i = 0;
	if (id == 3 || p == 0)
		return (0);
	if (p->pieces[id] + 1 == p->pieces[id + 1])
		i++;
	while (chks != 0)
	{
		if (p->pieces[id] + 5 == p->pieces[id + chks])
		{
			i++;
			break ;
		}
		chks--;
	}
	return (i);
}

int		ft_validate(t_piece *p)
{
	unsigned char	con;
	unsigned char	id;

	con = 0;
	id = 0;
	while (id != 3)
		con += ft_check(p, id++);
	return (con);
}

int		ft_checklst(t_list *lst)
{
	while (lst != 0)
	{
		if (ft_validate(lst->content) < 3)
			return (0);
		lst = lst->next;
	}
	return (1);
}
