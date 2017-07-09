/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:07:33 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/07 16:41:57 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static int		ft_checkpiece2(char *ret, int i, char *buf, int fd)
{
	*ret = read(fd, buf, 1);
	if (ret <= 0)
		return (0);
	if ((i % 5 == 0 && *buf != '\n')
			|| (i % 5 != 0 && (*buf != '#' && *buf != '.')))
		return (0);
	return (1);
}

int				ft_checkpiece(int fd, t_piece *piece, int i, int id)
{
	char	ret;
	int		res;
	char	buf;

	if (i >= 21 && id == 4)
		return (1);
	else if (i >= 21)
		return (0);
	res = ft_checkpiece2(&ret, i, &buf, fd);
	if (res == 1 && ret != 0)
	{
		if (buf == '#')
		{
			if (id >= 4)
				return (0);
			piece->pieces[id++] = i;
		}
		return (ft_checkpiece(fd, piece, ++i, id));
	}
	else
		return (0);
}

int				ft_filllst(int fd)
{
	t_piece	*piece;
	t_list	*node;
	char	buf;
	int		ret;

	piece = (t_piece *)malloc(sizeof(t_piece));
	if ((ret = ft_checkpiece(fd, piece, 1, 0)) == 0)
	{
		free(piece);
		error_a(g_input->next, 10);
	}
	node = ft_lstnew(piece, sizeof(t_piece));
	free(piece);
	ft_lstappend(g_input, node);
	ret = read(fd, &buf, 1);
	if (ret != 0 && buf == '\n')
		return (ft_filllst(fd));
	else
		return (ret == 0 ? 1 : 0);
}

t_list			*ft_checkinput(char *file)
{
	int		fd;
	t_list	temp;

	g_input = &temp;
	temp.next = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		error(3);
	if (ft_filllst(fd) == 0)
		error(4);
	g_input = g_input->next;
	if (ft_checklst(g_input) == 0)
		error_a(g_input, 5);
	if (close(fd) < 0)
		error_a(g_input, 6);
	return (g_input);
}
