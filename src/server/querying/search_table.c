/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:28:44 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:58:58 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	is_sorting_type_char(void)
{
	int i;
	int max_size;

	i = -1;
	max_size = atoi(g_table->size) * 4;
	while (++i)
	{
		if (strcasecmp(g_valid_field[g_column], g_table->field[i]) == 0)
			break ;
	}
	if (strcasecmp(g_table->field[++i], "CHAR") == 0)
		return (1);
	return (0);
}

int	search_table(void)
{
	int			i;
	int			ret;
	t_cmp		cmp1;
	t_cmp		cmp2;
	t_bool_op	bp;

	ret = 0;
	i = 0;
	cmp1 = get_cmp_funct(g_operators);
	cmp2 = get_cmp_funct(g_operators2);
	bp = get_bool_funct(g_bool_oper);
	while (i < g_max_users)
	{
		if (bp(cmp1(g_file_data[i][g_column], g_value),
			cmp2(g_file_data[i][g_column2], g_value2)))
		{
			ft_listaddback(&g_users, ft_lstnew(i));
			ret = 1;
		}
		i++;
	}
	reset_condition_values();
	return (ret);
}
