/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data_to_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:49:58 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:49:59 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	update_data_from_list(void)
{
	while (g_users)
	{
		g_file_data[g_users->index][g_update_column] = strdup(g_update_value);
		g_users = g_users->next;
	}
}

char	*update_data_to_table(void)
{
	FILE	*fp;
	int		i;
	int		j;

	update_data_from_list();
	fp = fopen(str_toupper(g_table->name), "w");
	fprintf(fp, "%d,%d,%d\n", g_max_users, g_last_index, g_max_columns);
	i = -1;
	while (++i < g_max_users)
	{
		j = 0;
		fprintf(fp, "%s", g_file_data[i][j]);
		while (++j < g_max_columns)
			fprintf(fp, ",%s", g_file_data[i][j]);
		fprintf(fp, "\n");
	}
	fclose(fp);
	return ("UPDATED Successfully\n");
}
