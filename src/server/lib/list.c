/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:51:42 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:51:43 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

t_list	*ft_lstnew(int index)
{
	t_list	*link;

	if (!(link = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	link->index = index;
	link->next = NULL;
	return (link);
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_listaddback(t_list **alst, t_list *new)
{
	t_list *node;

	if (!*alst)
	{
		ft_lstadd(alst, new);
		return ;
	}
	node = *alst;
	while (node->next)
		node = node->next;
	node->next = new;
}
