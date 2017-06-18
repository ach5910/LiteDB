/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file_after_delete.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:50:09 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:50:12 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	set_delete_flags(void)
{
	while (g_users)
	{
		g_file_data[g_users->index][0] = strdup("-1");
		g_users = g_users->next;
	}
}

void	write_to_file_after_delete(void)
{
	FILE	*fp;
	int		i;
	int		j;

	fp = fopen(str_toupper(g_table->name), "w");
	fprintf(fp, "%d,%d,%d\n", g_max_users - 1, g_last_index, g_max_columns);
	set_delete_flags();
	i = -1;
	while (++i < g_max_users)
	{
		if (strcasecmp(g_file_data[i][0], "-1"))
		{
			j = 0;
			fprintf(fp, "%s", g_file_data[i][j]);
			while (++j < g_max_columns)
				fprintf(fp, ",%s", g_file_data[i][j]);
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
}
