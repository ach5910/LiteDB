/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_from.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:48:20 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:48:20 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*ft_from(char *input)
{
	if (validate_from(input) == -1)
		return ("Invalid FROM\n");
	input = strtok(NULL, " \n");
	g_table = find_table(&g_tb_list, input);
	if (g_table == NULL)
		return ("Invalid TABLE\n");
	init_fields(g_table);
	input = strtok(NULL, " \n");
	if (input != NULL)
		return (ft_where(input));
	else
		g_column = -1;
	return (NULL);
}
