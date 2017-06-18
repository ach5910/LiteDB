/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:00:00 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 18:00:01 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*ft_update(char *input)
{
	char *ret;

	g_table = find_table(&g_tb_list, input);
	if (g_table == NULL)
		return ("Invalid TABLE\n");
	init_fields(g_table);
	input = strtok(NULL, " ");
	if ((ret = ft_set(input)) != NULL)
		return (ret);
	parse_from_table();
	if (!search_table())
		return ("User not found\n");
	return (update_data_to_table());
}
