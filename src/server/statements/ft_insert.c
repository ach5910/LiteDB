/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:59:43 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:59:43 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*ft_insert(char *input)
{
	if (!validate_into(input))
		return ("Invalid INSERT\n");
	input = strtok(NULL, " \n");
	g_table = find_table(&g_tb_list, input);
	if (g_table == NULL)
		return ("Invalid TABLE\n");
	init_fields(g_table);
	input = strtok(NULL, " \n");
	if (!validate_values(input))
		return ("Invalid VALUES\n");
	input = strtok(NULL, " \n");
	if (!parse_values_for_insert(input))
		return ("Error Invalid Values Entered\n");
	if (!validate_new_data())
		return ("Invalid Input Data\n");
	parse_from_table();
	return (insert_data_to_table());
}
