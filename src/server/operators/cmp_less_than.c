/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_less_than.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:46:55 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/02 19:46:56 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	cmp_less_than(char *s1, char *s2)
{
	if (is_sorting_type_char())
	{
		if (strcasecmp(s1, s2) < 0)
			return (1);
		return (0);
	}
	if (atoi(s1) < atoi(s2))
		return (1);
	return (0);
}
