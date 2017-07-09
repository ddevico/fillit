/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:12:51 by ddevico           #+#    #+#             */
/*   Updated: 2015/12/14 12:13:45 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <assert.h>
# include <unistd.h>

int					get_next_line(int const fd, char **line);

#endif
