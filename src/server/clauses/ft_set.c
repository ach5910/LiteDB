/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:48:40 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:48:41 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*ft_set(char *input)
{
	char *ret;

	if (!validate_set(input))
		return ("Invalid SET\n");
	input = strtok(NULL, " ");
	g_update_column = validate_column(input) - 1;
	if (g_update_column < 1)
		return ("Invalid Column Value after SET\n");
	input = strtok(NULL, " ");
	if (!validate_equal(input))
		return ("Invalid Equals\n");
	if ((input = strtok(NULL, " ")) == NULL)
		return ("Invalid New Value\n");
	if (input[0] == '\'')
		g_update_value = parse_multitoken_string(input);
	else
		g_update_value = strdup(input);
	if (g_update_value == NULL)
		return ("Error Invalid Single Quote Use\n");
	if (!validate_update_data_type())
		return ("Invalid Data Type or Size\n");
	input = strtok(NULL, " ");
	if ((ret = ft_where(input)) != NULL)
		return (ret);
	return (NULL);
}
