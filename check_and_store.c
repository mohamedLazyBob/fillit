/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:53:00 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/07/10 17:17:01 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_file(int fd, t_fillit *table, int *n)
{
	int		r;
	int		indice;
	char	buff[22];
	char	last;
	int		nbr;

	indice = 0;
	r = 0;
	last = '\n';
	while ((r = read(fd, buff, 21)) > 0)
	{
		buff[r] = '\0';
		nbr = check_links(buff);
		if (check_form(buff) == 0 || (nbr != 6 && nbr != 8))
			return (0);
		else
			ft_assigne(table, indice++, buff);
		last = buff[20];
		(*n)++;
	}
	if (r <= 0 && last == '\n')
		return (0);
	return (1);
}

void	ft_assigne(t_fillit *table, int i, char *buff)
{
	int		hash_nbr;
	int		j;

	hash_nbr = 0;
	j = 0;
	while (buff[j])
	{
		if (buff[j] == '#')
		{
			table[i].row[hash_nbr] = (j / 5);
			table[i].col[hash_nbr] = (j % 5);
			hash_nbr++;
		}
		j++;
	}
	table[i].alpha = i + 65;
}
