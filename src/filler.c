/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		print(t_struct *play)
{
	ft_putstr(ft_itoa(play->coord_y));
	ft_putchar(' ');
	ft_putstr(ft_itoa(play->coord_x));
	ft_putchar('\n');
}

static void		init_struct(t_struct *play)
{
	play->x_map = 0;
	play->y_map = 0;
	play->map = NULL;
	play->x_piece = 0;
	play->y_piece = 0;
	play->piece = NULL;
	play->play1 = ' ';
	play->play2 = ' ';
	play->coord_x = 0;
	play->coord_y = 0;
	play->opx = 0;
	play->opy = 0;
	play->i = 0;
	play->j = 0;
	play->player = 0;
	play->form = ' ';
}

t_struct		*declare_player(char *line, t_struct *play)
{
	line += 10;
	play->play1 = 'Z';
	if (play->play1 == 'Z')
	{
		play->play1 = *line == '1' ? 'o' : 'x';
		play->play2 = play->play1 == 'o' ? 'x' : 'o';
	}
	return (play);
}

static void		ft_get_next_line(t_struct *play, int fd)
{
	char		*line;

	while (get_next_line(fd, &line) > 0)
	{
		if ((ft_readstart(line, "$$$")))
			play = declare_player(line, play);
		if ((ft_readstart(line, "Plateau")))
		{
			play = ft_readmap(line, play, fd);
		}
		if ((ft_readstart(line, "Piece")))
		{
			play = ft_readpiece(line, play, fd);
			ft_resolve(play);
			print(play);
		}
	}
}

int				main(void)
{
	t_struct	*play;

	play = (t_struct*)malloc(1 * sizeof(t_struct));
	init_struct(play);
	ft_get_next_line(play, 0);
	return (0);
}
