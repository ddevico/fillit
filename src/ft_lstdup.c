/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:42:19 by qviguier          #+#    #+#             */
/*   Updated: 2015/12/15 14:09:37 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*newlst;
	t_list	*node;

	node = ft_lstnew(lst->content, lst->content_size);
	newlst = node;
	while (lst != 0)
	{
		node = ft_lstnew(lst->content, lst->content_size);
		ft_lstappend(newlst, node);
	}
	return (newlst);
}
