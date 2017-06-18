/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_table_header_after_drop.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:49:49 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:49:50 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	rewrite_table_header_after_drop(t_lst **g_tb_list)
{
	FILE	*fp;
	t_lst	*tmp;
	t_table	*cur;
	int		max_size;
	int		i;

	fp = fopen("TABLES", "w");
	tmp = *g_tb_list;
	while (tmp)
	{
		cur = tmp->content;
		fprintf(fp, "%s,%s", cur->name, cur->size);
		max_size = (atoi(cur->size) - 1) * 4;
		i = -1;
		while (++i < max_size)
		{
			fprintf(fp, ",%s=%s(%s~%s)", cur->field[i],
				cur->field[i + 1], cur->field[i + 2], cur->field[i + 3]);
			i += 3;
		}
		fprintf(fp, "\n");
		tmp = tmp->next;
	}
	fclose(fp);
}
