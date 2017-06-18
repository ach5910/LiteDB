/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:59:25 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:59:26 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*ft_delete(char *input)
{
	char *ret;

	if ((ret = ft_from(input)) != NULL)
		return (ret);
	parse_from_table();
	if (!search_table())
		return ("User not found\n");
	write_to_file_after_delete();
	return ("DELETED Succesfully\n");
}
