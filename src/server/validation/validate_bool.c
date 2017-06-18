/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:00:17 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 18:00:18 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_bool(char *input)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		if (strcasecmp(g_valid_bool[i], input) == 0)
			return (i + 1);
	}
	return (0);
}
