/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_isdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:52:10 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:52:11 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	str_isdigit(char *input)
{
	int i;

	i = -1;
	while (input[++i])
	{
		if (!isdigit(input[i]) && i != 0 && input[i] != '-')
			return (0);
	}
	return (1);
}
