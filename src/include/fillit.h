/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:53:02 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/07 16:53:43 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef	struct		s_mat
{
	unsigned char	size;
	char			**mat;
}					t_mat;

typedef	struct		s_piece
{
	char			status;
	char			id;
	unsigned char	coord[2];
	unsigned char	size[2];
	unsigned char	pieces[4];
}					t_piece;

extern int		g_size;
extern t_list	*g_input;

void				matprint(t_mat *mat);
int					matfind(t_mat *m, t_piece *p);
void				coordinc(t_piece *p, size_t taille);
void				matput(t_mat *m, t_piece *p, char c);
int					mattry(t_mat *m, t_piece *p);

t_mat				*matcreate(size_t taille);
int					matdel(t_mat *matrice);
t_mat				*ft_reallocmat(t_mat *mat);

int					ft_check(t_piece *p, unsigned char id);
int					ft_checklst(t_list *lst);
int					ft_validate(t_piece *p);

t_list				*ft_checkinput(char *file);

void				lstcenter(t_list *lst);

int					setminsize(t_list *lst);
int					resolve(t_list *lst);
int					trysize(t_mat *mat, t_list *lst);

void				error(int id);
void				error_a(t_list *lst, int id);

#endif
