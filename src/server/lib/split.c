/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:51:59 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 17:52:01 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int		get_word_count(char *str)
{
	int count;
	int i;
	int prev;

	i = 0;
	count = 0;
	prev = 0;
	while (str[i])
	{
		if ((str[i] == '\n' || str[i] == ' ' || str[i] == '\t') && prev == 1)
			prev = 0;
		if ((str[i] != '\n' && str[i] != ' ' && str[i] != '\t') && prev == 0)
		{
			prev = 1;
			count++;
		}
		i++;
	}
	return (count);
}

int		get_word_location(int i, char *str)
{
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
			break ;
		i++;
	}
	return (i);
}

int		get_length(int i, char *str)
{
	int init;

	init = i;
	while (str[i] != '\0' && str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i - init);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	**chstr;

	i = 0;
	k = 0;
	chstr = (char**)malloc(sizeof(char*) * (get_word_count(str) + 1));
	while (i < get_word_count(str))
	{
		j = 0;
		k = get_word_location(k, str);
		size = get_length(k, str);
		chstr[i] = (char*)malloc(sizeof(char) * (size + 1));
		while (j < size)
			chstr[i][j++] = str[k++];
		chstr[i][j] = '\0';
		i++;
	}
	chstr[get_word_count(str)] = 0;
	return (chstr);
}
