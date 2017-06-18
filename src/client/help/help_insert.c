/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:50:28 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/04 19:50:29 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	help_insert(void)
{
	printf("INSERT adds a record to any g_table. Examples:\n\tINSERT INTO <TABLE NAME> VALUES <COLUMN NAME>=char(minlen~maxlen)\n\tINSERT INTO <TABLE NAME> VALUES <COLUMN NAME>=int(minsize~maxsize)\n\tINSERT INTO <TABLE NAME> VALUES <COLUMN NAME>=char(minlen~maxlen) <COLUMN NAME>=int(minsize~maxsize)...\n");
}
