/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_board.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:58:19 by mzaboub           #+#    #+#             */
/*   Updated: 2019/07/09 22:55:54 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_shift_titriminos(t_fillit *table, size_t table_size)
{
	size_t	col;
	int		i;
	size_t	row_to_decrease;
	size_t	col_to_decrease;

	col = 0;
	while (col < table_size)
	{
		row_to_decrease = table[col].row[0];
		col_to_decrease = 4;
		i = -1;
		while (++i < 4)
		{
			if (table[col].col[i] < col_to_decrease)
				col_to_decrease = table[col].col[i];
		}
		i = -1;
		while (++i < 4)
		{
			table[col].row[i] = table[col].row[i] - row_to_decrease;
			table[col].col[i] = table[col].col[i] - col_to_decrease;
		}
		col++;
	}
}

char	**ft_allocate_board(int n)
{
	int		i;
	char	**board;

	board = (char**)malloc((n + 1) * sizeof(char*));
	board[n] = NULL;
	i = 0;
	while (i < n)
	{
		board[i] = (char*)malloc((n + 1) * sizeof(char));
		ft_memset((void*)board[i], 46, n);
		board[i][n] = '\0';
		i++;
	}
	return (board);
}

void	ft_print_board(char **board, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &board[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_free_board(char **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}
