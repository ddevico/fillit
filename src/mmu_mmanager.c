/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MMU-Mmanager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:03:23 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/07 12:50:46 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fillmat(t_mat *mat)
{
	size_t	size;
	char	**matrice;
	int		i;
	int		j;

	i = 0;
	j = 0;
	matrice = mat->mat;
	size = mat->size;
	while ((size_t)i < size)
	{
		while ((size_t)j < size)
		{
			matrice[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

t_mat		*matcreate(size_t taille)
{
	t_mat		*matrice;
	size_t		i;

	if (taille == 0)
		return (0);
	i = 0;
	matrice = (t_mat*)malloc(sizeof(t_mat) * 1);
	matrice->size = taille;
	if (!(matrice->mat = (char**)malloc(sizeof(char*) * taille)))
		return (0);
	while (i < matrice->size)
	{
		if (!(matrice->mat[i] = (char*)malloc(sizeof(char) * taille)))
			return (0);
		i++;
	}
	fillmat(matrice);
	return (matrice);
}

int			matdel(t_mat *matrice)
{
	int		i;

	i = 0;
	while (i < matrice->size)
	{
		free(matrice->mat[i]);
		matrice->mat[i] = NULL;
		i++;
	}
	free(matrice->mat);
	free(matrice);
	matrice = NULL;
	return (0);
}

t_mat		*ft_reallocmat(t_mat *matrice)
{
	t_mat	*new;
	char	**mat;
	size_t	size;

	mat = matrice->mat;
	size = matrice->size;
	matdel(matrice);
	new = matcreate(size + 1);
	return (new);
	return (new);
}
