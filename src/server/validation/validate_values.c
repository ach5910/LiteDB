/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:01:09 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/02 20:01:11 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_values(char *input)
{
	if (input == NULL)
		return (0);
	if (strcasecmp(input, "VALUES") == 0)
		return (1);
	return (0);
}
