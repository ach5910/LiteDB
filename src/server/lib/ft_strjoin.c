/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:51:24 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:51:25 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = ft_strnew(strlen(s1) + strlen(s2) + 1)))
		return (NULL);
	strncpy(res, s1, strlen(s1));
	strcpy(res + strlen(s1), s2);
	return (res);
}
