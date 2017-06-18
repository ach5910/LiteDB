/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_less_than.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:46:55 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/02 19:46:56 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	init_bool_operations(void)
{
	if (g_valid_bool != NULL)
		return ;
	g_valid_bool = malloc(sizeof(char*) * 2);
	g_valid_bool[0] = strdup("AND");
	g_valid_bool[1] = strdup("OR");
}

void	reset_condition_values(void)
{
	g_value2 = " ";
	g_operators2 = 0;
	g_column2 = 0;
	g_bool_oper = 0;
}

void	init_operators(void)
{
	if (g_valid_operator != NULL)
		return ;
	g_valid_operator = malloc(sizeof(char*) * 3);
	g_valid_operator[0] = strdup("=");
	g_valid_operator[1] = strdup("<");
	g_valid_operator[2] = strdup(">");
}
