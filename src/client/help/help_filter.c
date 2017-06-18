/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_filter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:17:42 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/04 19:17:42 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int	help_filter(char *buffer)
{
	int			i;
	t_help		help;
	const char	*helpstrs[6];

	i = 0;
	helpstrs[0] = "help select";
	helpstrs[1] = "help insert";
	helpstrs[2] = "help update";
	helpstrs[3] = "help create";
	helpstrs[4] = "help drop";
	helpstrs[5] = "help delete";
	while (i < 6)
	{
		if (strncmp(buffer, helpstrs[i], strlen(helpstrs[i])) == 0)
		{
			help = get_help_funct(i);
			help();
			return (0);
		}
		i++;
	}
	if (strncmp(buffer, "help", 4) == 0)
	{
		printf("Supported help commands:\nhelp select | help insert | help update | help create | help drop | help delete \n");
		return (0);
	}
	return (1);
}
