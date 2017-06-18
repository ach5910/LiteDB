/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:57:50 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:57:59 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

t_table	*find_table(t_lst **g_tb_list, char *input)
{
	t_table *t;
	t_lst	*l;

	if (input == NULL)
		return (NULL);
	l = *g_tb_list;
	while (l)
	{
		t = l->content;
		if (strcasecmp(t->name, input) == 0)
			return (t);
		l = l->next;
	}
	return (NULL);
}
