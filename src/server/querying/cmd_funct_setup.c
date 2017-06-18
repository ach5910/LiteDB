/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_funct_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:29:01 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:57:40 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void		init_command_funct(t_command *command)
{
	command[0] = &ft_select;
	command[1] = &ft_delete;
	command[2] = &ft_insert;
	command[3] = &ft_update;
	command[4] = &ft_create;
	command[5] = &ft_drop;
}

t_command	get_command_funct(int index)
{
	static t_command *command = NULL;

	if (command == NULL)
	{
		command = malloc(sizeof(*command) * 6);
		if (command != NULL)
			init_command_funct(command);
	}
	return (command[index]);
}
