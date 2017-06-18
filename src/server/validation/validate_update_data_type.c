/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_update_data_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:01:56 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 18:01:57 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_update_data_type(void)
{
	int i;
	int max_size;

	max_size = atoi(g_table->size) * 4;
	i = -1;
	while (++i < max_size)
	{
		if (strcasecmp(g_table->field[i], g_valid_field[g_update_column + 1])
			== 0)
			break ;
	}
	i++;
	if (strcasecmp(g_table->field[i], "CHAR") == 0)
	{
		return (validate_field_char(g_table->field[i + 1],
			g_table->field[i + 2], g_update_value));
	}
	return (validate_field_int(g_table->field[i + 1],
		g_table->field[i + 2], g_update_value));
}
