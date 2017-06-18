/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:55:32 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 18:00:31 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_column(char *second)
{
	int i;

	i = 0;
	if (second == NULL)
		return (-1);
	while (i < atoi(g_table->size) + 1)
	{
		if (strcasecmp(second, g_valid_field[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}
