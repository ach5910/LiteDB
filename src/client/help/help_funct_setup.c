/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funct_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:51:58 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/04 19:51:58 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	init_help_funct(t_help *help)
{
	help[0] = &help_select;
	help[1] = &help_insert;
	help[2] = &help_update;
	help[3] = &help_create;
	help[4] = &help_drop;
	help[5] = &help_delete;
}

t_help	get_help_funct(int index)
{
	static	t_help *help = NULL;

	if (help == NULL)
	{
		help = malloc(sizeof(*help) * 6);
		if (help != NULL)
			init_help_funct(help);
	}
	return (help[index]);
}
