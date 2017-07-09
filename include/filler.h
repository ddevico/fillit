/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:53:02 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/07 16:53:43 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"

typedef struct		s_struct
{
	int				x_map;
	int				y_map;
	char			**map;
	int				x_piece;
	int				y_piece;
	char			**piece;
	char			play1;
	char			play2;
	int				coord_x;
	int				coord_y;
	int				i;
	int				j;
	int				player;
	char			form;
	int				opx;
	int				opy;
}					t_struct;

int					get_next_line(int const fd, char **line);

t_struct			*ft_readpiece(char *line, t_struct *play, int fd);
t_struct			*ft_readmap(char *line, t_struct *play, int fd);
int					ft_readstart(char *s1, char *s2);

int					countnumber(char *str);
void				test_overflow(t_struct *d, int x, int y);
int					test_overflow2(t_struct *d, int x, int y);

void				ft_resolve(t_struct *play);

void				ft_fillmap_piece(t_struct *play);
void				ft_remplace_piece(t_struct *play);
void				ft_up_piece(t_struct *play);

#endif
