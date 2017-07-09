/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmu_writer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:26:50 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/04 13:27:18 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	matprint(t_mat *m)
{
	char	**mat;
	size_t	size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mat = m->mat;
	size = m->size;
	while ((size_t)j < size)
	{
		i = 0;
		while ((size_t)i < size)
		{
			ft_putchar(mat[i][j]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
