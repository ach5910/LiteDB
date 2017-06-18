/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:59:36 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:59:36 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int		drop_table_from_list(t_lst **g_tb_list, char *input)
{
	t_lst	*tmp;
	t_lst	*prev;
	t_table	*cur;

	tmp = *g_tb_list;
	prev = NULL;
	while (tmp != NULL)
	{
		cur = tmp->content;
		if (strcasecmp(cur->name, input) == 0)
		{
			if (prev == NULL)
				*g_tb_list = tmp->next;
			else
				prev->next = tmp->next;
			tmp->next = NULL;
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (0);
	return (1);
}

char	*ft_drop(char *input)
{
	if (strcasecmp(input, "TABLE") != 0)
		return ("Error Misspelled Keyword \"TABLE\"\n");
	input = strtok(NULL, " \n");
	if (!drop_table_from_list(&g_tb_list, input))
		return ("Error given g_table name not found\n");
	rewrite_table_header_after_drop(&g_tb_list);
	remove(str_toupper(input));
	return ("Success\n");
}
