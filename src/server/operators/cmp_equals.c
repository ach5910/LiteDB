/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_equals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:46:28 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/02 19:46:30 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	cmp_equals(char *s1, char *s2)
{
	if (is_sorting_type_char())
	{
		if (strcasecmp(s1, s2) == 0)
			return (1);
		return (0);
	}
	if (atoi(s1) == atoi(s2))
		return (1);
	return (0);
}
