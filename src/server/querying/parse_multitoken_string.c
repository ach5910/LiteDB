/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multitoken_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:29:39 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 16:29:41 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*parse_multitoken_string(char *input)
{
	char *tmp;

	input++;
	input = ft_strjoin(input, " ");
	tmp = strtok(NULL, "\'\n");
	if (tmp == NULL)
		return (NULL);
	return (ft_strapp(input, tmp));
}
