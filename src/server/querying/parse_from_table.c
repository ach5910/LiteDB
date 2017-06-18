/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_from_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:23:48 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 16:23:49 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	parse_from_table(void)
{
	FILE	*fp;
	char	str[256];
	char	*tmp;
	int		i;
	int		j;

	j = -1;
	fp = fopen(str_toupper(g_table->name), "r");
	fscanf(fp, "%s\n", str);
	g_max_users = atoi(strtok(str, ","));
	g_last_index = atoi(strtok(NULL, ","));
	g_max_columns = atoi(strtok(NULL, ","));
	g_file_data = (char***)malloc(sizeof(char**) * g_max_users);
	while (fgets(str, 256, fp) != NULL)
	{
		i = -1;
		g_file_data[++j] = (char**)malloc(sizeof(char*) * g_max_columns);
		tmp = strtok(str, ",\n");
		while (tmp != NULL)
		{
			g_file_data[j][++i] = strdup(tmp);
			tmp = strtok(NULL, ",\n");
		}
		bzero(str, sizeof(char) * 256);
	}
	fclose(fp);
}
