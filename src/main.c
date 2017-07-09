/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:50:58 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/07 16:14:42 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		g_size;
t_list	*g_input;

void	freelst(t_list *lst)
{
	t_list *prec;

	while (lst != 0)
	{
		prec = lst;
		free(lst->content);
		lst = lst->next;
		free(prec);
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		error(9);
	if ((g_input = ft_checkinput(&argv[1][0])) == 0)
		ft_putendl("returned 0");
	else
	{
		lstcenter(g_input);
		resolve(g_input);
		freelst(g_input);
	}
	return (0);
}

void	error(int id)
{
	int i;

	i = id;
	ft_putendl("error");
	exit(0);
}

void	error_a(t_list *lst, int id)
{
	freelst(lst);
	error(id);
}
