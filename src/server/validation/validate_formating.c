/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_formating.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:00:53 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 18:00:54 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	validate_formating(char **info, int size)
{
	int		i;
	int		min;
	char	*temp;
	char	*str;

	i = -1;
	while (++i < size)
	{
		str = strdup(info[i]);
		temp = strtok(str, "=");
		if ((temp = strtok(NULL, "(")) == NULL)
			return (0);
		if (strcasecmp(temp, "CHAR") != 0 && strcasecmp(temp, "INT") != 0)
			return (0);
		temp = strtok(NULL, "~");
		if (!str_isdigit(temp))
			return (0);
		min = atoi(temp);
		if ((temp = strtok(NULL, ")")) == NULL)
			return (0);
		if (!str_isdigit(temp) || min > atoi(temp))
			return (0);
		free(str);
	}
	return (1);
}
