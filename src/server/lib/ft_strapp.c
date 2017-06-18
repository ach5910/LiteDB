/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:51:13 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:51:14 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

char	*ft_strapp(char const *s1, char const *s2)
{
	char	*res;
	size_t	size1;
	size_t	size2;

	if (!s1 || !*s1)
	{
		return (strdup(s2));
	}
	size1 = strlen(s1);
	size2 = strlen(s2);
	if (!s2)
		return (NULL);
	if (!(res = ft_strnew(size1 + size2 + 1)))
		return (NULL);
	strncpy(res, s1, size1);
	strcpy(res + size1, s2);
	free((void *)s1);
	return (res);
}
