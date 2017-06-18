/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:50:41 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/04 19:50:41 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	help_update(void)
{
	printf("UPDATE changes the data of a record in a g_table. Example:\n\tUPDATE <TABLE NAME> SET <COLUMN NAME> = <NEW VALUE> WHERE <COLUMN NAME> = <EXISTING VALUE>\n");
}
