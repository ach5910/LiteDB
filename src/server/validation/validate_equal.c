/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_equal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:00:21 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 16:31:06 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_equal(char *input)
{
	if (input == NULL)
		return (0);
	if (strcasecmp(input, "=") == 0)
		return (1);
	return (0);
}
