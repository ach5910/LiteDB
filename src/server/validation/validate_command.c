/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:55:12 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/02 19:55:14 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_command(char *first)
{
	int i;

	i = 0;
	if (first == NULL)
		return (-1);
	while (i < 6)
	{
		if (strcasecmp(first, g_valid_first[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}
