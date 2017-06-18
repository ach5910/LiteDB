/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:35:25 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 22:35:25 by bschroed         ###   ########.fr       */
/* ************************************************************************** */

#include "ftdb.h"

void	init_first(void)
{
	if (g_valid_first != NULL)
		return ;
	g_valid_first = malloc(sizeof(char*) * 6);
	g_valid_first[0] = strdup("SELECT");
	g_valid_first[1] = strdup("DELETE");
	g_valid_first[2] = strdup("INSERT");
	g_valid_first[3] = strdup("UPDATE");
	g_valid_first[4] = strdup("CREATE");
	g_valid_first[5] = strdup("DROP");
}

void	init_fields(t_table *g_table)
{
	int temp;
	int i;
	int j;

	j = 0;
	temp = atoi(g_table->size);
	g_valid_field = malloc(sizeof(char*) * (temp + 1));
	g_valid_field[j] = strdup("*");
	g_valid_field[++j] = strdup("ID");
	temp = (temp - 1);
	i = -1;
	while (++i < temp)
		g_valid_field[++j] = strdup(g_table->field[i * 4]);
}

t_table	*create_table_node(char *str)
{
	t_table	*tb;
	int		temp_size;
	int		j;

	tb = (t_table*)malloc(sizeof(t_table));
	tb->name = strdup(strtok(str, ","));
	tb->size = strdup(strtok(NULL, ","));
	temp_size = (atoi(tb->size) - 1) * 4;
	tb->field = (char**)malloc(sizeof(char*) * temp_size);
	j = -1;
	while (++j < temp_size)
	{
		tb->field[j] = strdup(strtok(NULL, ",="));
		tb->field[++j] = strdup(strtok(NULL, "("));
		tb->field[++j] = strdup(strtok(NULL, "~"));
		tb->field[++j] = strdup(strtok(NULL, ")"));
	}
	return (tb);
}

void	init_tables(void)
{
	FILE	*fp;
	char	str[4096];
	t_table	*tb;

	if (g_tb_list != NULL)
		return ;
	fp = fopen("TABLES", "r");
	while (!feof(fp))
	{
		bzero(str, 4096);
		fscanf(fp, "%s\n", str);
		tb = create_table_node(str);
		f_listaddback(&g_tb_list, f_lstnew(tb, sizeof(t_table)));
	}
	fclose(fp);
}
