/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_from.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:55:48 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/02 19:55:49 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_from(char *third)
{
	if (third == NULL)
		return (-1);
	if (strcasecmp(third, "FROM") == 0)
		return (1);
	return (-1);
}
