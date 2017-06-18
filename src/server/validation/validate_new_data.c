/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_new_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:01:18 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 18:01:20 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_field_int(char *min_size, char *max_size, char *input)
{
	int len;
	int i;

	len = strlen(input);
	i = -1;
	while (++i < len)
	{
		if (!isdigit(input[i]) && i != 0 && input[i] != '-')
			return (0);
	}
	if (atoi(input) < atoi(min_size) || atoi(input) > atoi(max_size))
		return (0);
	return (1);
}

int	validate_field_char(char *min_size, char *max_size, char *input)
{
	if (strlen(input) < (size_t)atoi(min_size) || strlen(input) >
		(size_t)atoi(max_size))
		return (0);
	return (1);
}

int	validate_new_data(void)
{
	int size;
	int j;
	int i;

	size = (atoi(g_table->size) - 1) * 4;
	j = -1;
	i = 0;
	while (++j < size)
	{
		if (strcasecmp(g_table->field[++j], "INT") == 0)
		{
			if (!validate_field_int(g_table->field[j + 1], g_table->field[j +
				2], g_new_data[i]))
				return (0);
		}
		else if (strcasecmp(g_table->field[j], "CHAR") == 0)
		{
			if (!validate_field_char(g_table->field[j + 1], g_table->field[j +
				2], g_new_data[i]))
				return (0);
		}
		j += 2;
		i++;
	}
	return (1);
}
