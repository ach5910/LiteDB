/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:59:52 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:59:52 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*ft_select(char *input)
{
	char *ret;

	if ((ret = ft_from(strtok(NULL, " "))) != NULL)
		return (ret);
	if ((g_ret_value = validate_column(input)) == -1)
		return ("Invalid Return Field\n");
	parse_from_table();
	if (g_column != -1 && !search_table())
		return ("User not found\n");
	return (return_data());
}
