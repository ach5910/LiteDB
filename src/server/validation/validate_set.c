/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:00:56 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 18:01:48 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_set(char *input)
{
	if (input == NULL)
		return (0);
	if (strcasecmp(input, "SET") == 0)
		return (1);
	return (0);
}
