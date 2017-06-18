/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:49:30 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:49:31 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	create_table_file(char *tb_name, int size)
{
	FILE *fp;

	fp = fopen(str_toupper(tb_name), "w+");
	fprintf(fp, "0,0,%d\n", size + 1);
	fclose(fp);
}
