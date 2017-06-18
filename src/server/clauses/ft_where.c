/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_where.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:48:50 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:48:51 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*condition(char *input, int is_first)
{
	input = strtok(NULL, " \n");
	g_column2 = validate_column(input) - 1;
	if (g_column2 < 0)
		return ("Invalid Column Value after WHERE\n");
	input = strtok(NULL, " \n");
	g_operators2 = validate_operator(input);
	if (g_operators2 == -1)
		return ("Invalid Equals\n");
	if ((input = strtok(NULL, " \n")) == NULL)
		return ("Invalid g_value\n");
	if (input[0] == '\'')
		g_value2 = parse_multitoken_string(input);
	else
		g_value2 = strdup(input);
	if (g_value2 == NULL)
		return ("Error Invalid Single Quote Use\n");
	if (is_first)
	{
		g_column = g_column2;
		g_operators = g_operators2;
		g_value = strdup(g_value2);
		free(g_value2);
	}
	return (NULL);
}

char	*ft_where(char *input)
{
	char *ret;

	printf("%s\n", input);
	if (!validate_where(input))
		return ("Invalid WHERE\n");
	if ((ret = condition(input, 1)) != NULL)
		return (ret);
	if ((input = strtok(NULL, " \n")) == NULL)
		return (NULL);
	if ((g_bool_oper = validate_bool(input)) == 0)
		return ("Invalid Boolean Operator");
	if ((ret = condition(input, 0)) != NULL)
		return (ret);
	if (strtok(NULL, " \n") != NULL)
		return ("Invalid Command, Excessive Input\n");
	return (NULL);
}
