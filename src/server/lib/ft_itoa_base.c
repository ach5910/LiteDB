/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:51:03 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:51:04 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void		ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}

uintmax_t	ft_pow(int base, int i)
{
	if (i == 0)
		return (1);
	else
		return (base * ft_pow(base, i - 1));
}

char		*ft_itoa_base(uintmax_t g_value, int base, int is_upper)
{
	char	*buf;
	int		size;
	char	*nbr;

	buf = is_upper ? strdup("0123456789ABCDEF") :
		strdup("0123456789abcdef");
	size = 1;
	while (ft_pow(base, size) - 1 < g_value)
		size++;
	nbr = ft_strnew(size);
	while (size-- > 0)
	{
		nbr[size] = buf[g_value % base];
		g_value /= base;
	}
	ft_strdel(&buf);
	return (nbr);
}
