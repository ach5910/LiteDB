/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:14:51 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/04 19:14:52 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	error(char *msg)
{
	perror(msg);
	exit(0);
}