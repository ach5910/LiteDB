/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_funct_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:47:57 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/02 19:47:58 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	init_cmp_funct(t_cmp *cmp)
{
	cmp[0] = &cmp_equals;
	cmp[1] = &cmp_less_than;
	cmp[2] = &cmp_greater_than;
}

t_cmp	get_cmp_funct(int index)
{
	static t_cmp *cmp = NULL;

	if (cmp == NULL)
	{
		cmp = malloc(sizeof(*cmp) * 4);
		if (cmp != NULL)
			init_cmp_funct(cmp);
	}
	return (cmp[index]);
}
