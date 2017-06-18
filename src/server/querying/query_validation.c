/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:58:36 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:58:37 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

// int main(int argc, char **argv){
// 	init_first();
// 	init_tables();
// 	init_operators();
// 	reset_condition_values();
// 	init_bool_operations();
// 	printf("%s\n",strdup(query_validation(argv[1])));
// 	return(0);
// }

char	*query_validation(char *argv)
{
	int			i;
	int			command_index;
	char		*temp;
	t_command	command;

	i = 0;
	temp = strtok(argv, " ");
	command_index = validate_command(temp);
	if (command_index != -1)
	{
		command = get_command_funct(command_index);
		if ((temp = strtok(NULL, " ")) != NULL)
			return (command(temp));
	}
	return ("Error on query Validation\n");
}
