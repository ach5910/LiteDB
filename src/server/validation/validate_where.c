/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_where.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:01:26 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/02 20:01:27 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_where(char *third)
{
	if (third == NULL)
		return (0);
	if (strcasecmp(third, "WHERE") == 0)
		return (1);
	return (0);
}
