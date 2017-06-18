/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_table_to_header_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:49:22 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:49:23 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	add_table_to_header_file(char *tb_name, char **info, int size)
{
	FILE	*fp;
	int		i;

	fp = fopen("TABLES", "a+");
	fprintf(fp, "%s,%d", str_toupper(tb_name), size + 1);
	i = -1;
	while (++i < size)
		fprintf(fp, ",%s", info[i]);
	fprintf(fp, "\n");
	fclose(fp);
}
