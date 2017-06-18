/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:56:35 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 18:01:35 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_operator(char *third)
{
	int i;

	if (third == NULL)
		return (-1);
	i = -1;
	while (++i < OPERATOR_STRING_LIMIT)
	{
		if (strcasecmp(third, g_valid_operator[i]) == 0)
			return (i);
	}
	return (-1);
}
