/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:58:50 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:58:51 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*return_entire_table_no_condition(void)
{
	int		i;
	int		j;
	char	buf[4096];

	bzero(buf, sizeof(char) * 4096);
	i = -1;
	while (++i < g_max_users)
	{
		j = -1;
		while (++j < g_max_columns)
			sprintf(EOS(buf), "%s ", g_file_data[i][j]);
		sprintf(EOS(buf), "\n");
	}
	return (strdup(buf));
}

char	*return_entire_column_no_condition(void)
{
	int		i;
	char	buf[4096];

	bzero(buf, sizeof(char) * 4096);
	i = -1;
	while (++i < g_max_users)
		sprintf(EOS(buf), "%s\n", g_file_data[i][g_ret_value - 1]);
	return (strdup(buf));
}

char	*return_queried_rows(void)
{
	int		j;
	char	buf[4096];

	bzero(buf, sizeof(char) * 4096);
	while (g_users)
	{
		j = -1;
		while (++j < g_max_columns)
			sprintf(EOS(buf), "%s ", g_file_data[g_users->index][j]);
		sprintf(EOS(buf), "\n");
		g_users = g_users->next;
	}
	return (strdup(buf));
}

char	*return_queried_columns(void)
{
	char	buf[4096];

	bzero(buf, sizeof(char) * 4096);
	while (g_users)
	{
		sprintf(EOS(buf), "%s\n", g_file_data[g_users->index][g_ret_value - 1]);
		g_users = g_users->next;
	}
	return (strdup(buf));
}

char	*return_data(void)
{
	int		i;
	int		j;
	char	buf[4096];

	bzero(buf, sizeof(char) * 4096);
	if (g_column == -1)
	{
		if (g_ret_value == 0)
			return (return_entire_table_no_condition());
		else
			return (return_entire_column_no_condition());
	}
	else if (g_ret_value == 0)
		return (return_queried_rows());
	return (return_queried_columns());
}
