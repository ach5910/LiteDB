/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_data_to_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:49:40 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:49:40 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*insert_data_to_table(void)
{
	FILE	*fp;
	int		i;
	int		j;

	fp = fopen(str_toupper(g_table->name), "w");
	fprintf(fp, "%d,%d,%d\n", g_max_users + 1, g_last_index + 1, g_max_columns);
	i = -1;
	while (++i < g_max_users)
	{
		j = 0;
		fprintf(fp, "%s", g_file_data[i][j]);
		while (++j < g_max_columns)
			fprintf(fp, ",%s", g_file_data[i][j]);
		fprintf(fp, "\n");
	}
	j = 0;
	fprintf(fp, "%d,%s", g_last_index + 1, g_new_data[j]);
	while (++j < g_max_columns - 1)
		fprintf(fp, ",%s", g_new_data[j]);
	fprintf(fp, "\n");
	fclose(fp);
	return ("INSERTED Successfully\n");
}
