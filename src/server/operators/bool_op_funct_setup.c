/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_op_funct_setup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:56:08 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:56:09 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void		init_bool_funct(t_bool_op *bp)
{
	bp[0] = &bool_op_none;
	bp[1] = &bool_op_and;
	bp[2] = &bool_op_or;
}

t_bool_op	get_bool_funct(int index)
{
	static t_bool_op *bp = NULL;

	if (bp == NULL)
	{
		bp = malloc(sizeof(*bp) * 4);
		if (bp != NULL)
			init_bool_funct(bp);
	}
	return (bp[index]);
}
