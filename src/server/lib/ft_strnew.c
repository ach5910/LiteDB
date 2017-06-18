/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:51:34 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:51:35 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}
