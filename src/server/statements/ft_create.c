/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:59:18 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:59:19 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	add_table_to_list(t_lst **g_tb_list, char *tb_name, char **info,
	int size)
{
	t_table	*tb;
	int		i;

	tb = (t_table*)malloc(sizeof(t_table));
	tb->name = strdup(tb_name);
	tb->size = ft_itoa_base((uintmax_t)(size + 1), 10, 1);
	tb->field = (char**)malloc(sizeof(char*) * size * 4);
	i = -1;
	while (++i < size * 4)
	{
		tb->field[i] = strdup(strtok(info[i / 4], ",="));
		tb->field[++i] = strdup(strtok(NULL, "("));
		tb->field[++i] = strdup(strtok(NULL, "~"));
		tb->field[++i] = strdup(strtok(NULL, "),"));
	}
	f_listaddback(g_tb_list, f_lstnew(tb, sizeof(t_table)));
}

char	*ft_create(char *input)
{
	char	*tb_name;
	char	**field_info;
	int		i;

	if (strcasecmp(input, "TABLE") != 0)
		return ("No Table after Create\n");
	if ((tb_name = strtok(NULL, " \n")) == NULL || (find_table(&g_tb_list,
		tb_name) != NULL))
		return ("Invalid Table Name\n");
	if ((input = strtok(NULL, " \n")) == NULL)
		return ("No fields given\n");
	field_info = (char**)malloc(sizeof(char*) * 16);
	i = 0;
	while (input != NULL)
	{
		field_info[i] = strdup(input);
		input = strtok(NULL, " \n");
		i++;
	}
	if (!validate_formating(field_info, i))
		return ("Improper Formatting\n");
	add_table_to_header_file(tb_name, field_info, i);
	add_table_to_list(&g_tb_list, tb_name, field_info, i);
	create_table_file(tb_name, i);
	return ("Success\n");
}
