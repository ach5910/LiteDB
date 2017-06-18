/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values_for_insert.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:20:46 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 16:21:50 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	parse_values_for_insert(char *input)
{
	int i;

	g_new_data = (char**)malloc(sizeof(char*) * atoi(g_table->size));
	i = -1;
	while (input != NULL)
	{
		if (input[0] == '\'')
		{
			if ((g_new_data[++i] = parse_multitoken_string(input)) == NULL)
				return (0);
		}
		else
			g_new_data[++i] = strdup(input);
		input = strtok(NULL, " \n");
	}
	if (i + 2 != atoi(g_table->size))
		return (0);
	return (1);
}
