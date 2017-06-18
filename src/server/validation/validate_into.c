/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_into.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:00:37 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/02 20:00:38 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_into(char *input)
{
	if (input == NULL)
		return (0);
	if (strcasecmp(input, "INTO") == 0)
		return (1);
	return (0);
}
