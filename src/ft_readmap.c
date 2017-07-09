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

int				ft_readstart(char *s1, char *s2)
{
	int			i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s2[i] != s1[i])
			return (0);
		i++;
	}
	if (s2[i])
		return (0);
	return (1);
}

t_struct		*ft_readpiece(char *line, t_struct *play, int fd)
{
	int			count;
	int			i;

	i = 0;
	line += 6;
	while (*line == ' ')
		line++;
	play->x_piece = ft_atoi(line);
	count = countnumber(line);
	line += count;
	while (*line == ' ')
		line++;
	play->y_piece = ft_atoi(line);
	if (!play->x_piece || !play->y_piece)
		exit(0);
	if (!(play->piece = (char **)malloc(play->x_piece * sizeof(char *))))
		return (NULL);
	while (i < play->x_piece)
	{
		get_next_line(fd, &line);
		play->piece[i] = line;
		i++;
	}
	return (play);
}

t_struct		*ft_readmap(char *line, t_struct *play, int fd)
{
	int			count;
	int			i;

	i = 0;
	line += 7;
	while (*line == ' ')
		line++;
	play->x_map = ft_atoi(line);
	count = countnumber(line);
	line += count;
	while (*line == ' ')
		line++;
	play->y_map = ft_atoi(line);
	if (!play->x_map || !play->y_map)
		exit(0);
	if (!(play->map = (char **)malloc(play->x_map * sizeof(char *))))
		return (NULL);
	get_next_line(fd, &line);
	while (i < play->x_map)
	{
		get_next_line(fd, &line);
		play->map[i] = (line + 4);
		i++;
	}
	return (play);
}
