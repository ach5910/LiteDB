/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:51:50 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:51:52 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	*f_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)dest);
}

t_lst	*f_lstnew(void const *content, size_t content_size)
{
	t_lst	*link;

	if (!(link = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		if (!(link->content = malloc(content_size)))
		{
			free(link);
			return (NULL);
		}
		link->content = f_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}

void	f_lstadd(t_lst **alst, t_lst *new)
{
	new->next = *alst;
	*alst = new;
}

void	f_listaddback(t_lst **stack, t_lst *elem)
{
	t_lst *node;

	if (!*stack)
	{
		f_lstadd(stack, elem);
		return ;
	}
	node = *stack;
	while (node->next)
		node = node->next;
	node->next = elem;
}
