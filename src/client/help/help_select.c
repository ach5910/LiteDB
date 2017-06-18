/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:50:17 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/04 19:50:18 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	help_select(void)
{
	printf("SELECT returns a result set of records from one g_table. Examples:\n\tSELECT * FROM <TABLE VALUE>\n\tSELECT <COLUMN VALUE> FROM <TABLE VALUE>\n");
}
