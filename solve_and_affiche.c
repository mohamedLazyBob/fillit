/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 19:31:52 by mzaboub           #+#    #+#             */
/*   Updated: 2019/07/09 22:55:42 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(t_fillit *table, int table_size)
{
	char	**board;
	int		board_size;

	board_size = 2;
	ft_shift_titriminos(table, table_size);
	while (board_size * board_size < 4 * table_size)
		board_size++;
	board = ft_allocate_board(board_size);
	while (ft_backtracking(table, 0, table_size, board) == NON_VALID)
	{
		ft_free_board(board, board_size);
		board = ft_allocate_board(++board_size);
	}
	ft_print_board(board, board_size);
	ft_free_board(board, board_size + 1);
}

int		ft_check_and_place(char **board, t_board_indice indice, t_fillit colum)
{
	if ((board[indice.i + colum.row[0]] == NULL) ||\
		(board[indice.i + colum.row[1]] == NULL) ||\
		(board[indice.i + colum.row[2]] == NULL) ||\
		(board[indice.i + colum.row[3]] == NULL))
		return (NON_VALID);
	if ((board[indice.i + colum.row[0]][indice.j + colum.col[0]] == '.') &&\
		(board[indice.i + colum.row[1]][indice.j + colum.col[1]] == '.') &&\
		(board[indice.i + colum.row[2]][indice.j + colum.col[2]] == '.') &&\
		(board[indice.i + colum.row[3]][indice.j + colum.col[3]] == '.'))
	{
		board[indice.i + colum.row[0]][indice.j + colum.col[0]] = colum.alpha;
		board[indice.i + colum.row[1]][indice.j + colum.col[1]] = colum.alpha;
		board[indice.i + colum.row[2]][indice.j + colum.col[2]] = colum.alpha;
		board[indice.i + colum.row[3]][indice.j + colum.col[3]] = colum.alpha;
		return (VALID);
	}
	return (NON_VALID);
}

void	ft_remove_titrimino(char **board, t_board_indice indice, t_fillit colum)
{
	board[indice.i + colum.row[0]][indice.j + colum.col[0]] = '.';
	board[indice.i + colum.row[1]][indice.j + colum.col[1]] = '.';
	board[indice.i + colum.row[2]][indice.j + colum.col[2]] = '.';
	board[indice.i + colum.row[3]][indice.j + colum.col[3]] = '.';
}

int		ft_backtracking(t_fillit *table, int tab_index, int tab_size,\
		char **board)
{
	t_board_indice	indice;

	if (tab_index == tab_size)
		return (VALID);
	indice.i = 0;
	while (board[indice.i])
	{
		indice.j = 0;
		while (board[indice.i][indice.j])
		{
			if (ft_check_and_place(board, indice, table[tab_index]) == VALID)
			{
				if (ft_backtracking(table, tab_index + 1, tab_size,\
							board) == VALID)
					return (VALID);
				ft_remove_titrimino(board, indice, table[tab_index]);
			}
			indice.j++;
		}
		indice.i++;
	}
	return (NON_VALID);
}
