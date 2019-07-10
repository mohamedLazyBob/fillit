/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:55:11 by mzaboub           #+#    #+#             */
/*   Updated: 2019/07/09 22:07:50 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_fillit
{
	size_t	row[4];
	size_t	col[4];
	char	alpha;
}				t_fillit;

typedef	struct	s_board_indice
{
	size_t	i;
	size_t	j;
}				t_board_indice;

void			ft_fillit(t_fillit *table, int table_size);
int				ft_check_and_place(char **board, t_board_indice indice,\
		t_fillit colum);
void			ft_remove_titrimino(char **board, t_board_indice indice,\
		t_fillit colum);
int				ft_backtracking(t_fillit *table, int tab_index, int tab_size,\
		char **board);
void			ft_shift_titriminos(t_fillit *table, size_t table_size);
char			**ft_allocate_board(int n);
void			ft_print_board(char **board, int size);
void			ft_free_board(char **board, int size);
void			ft_assigne(t_fillit *table, int i, char *buff);
int				check_char_numbs(char *buff);
int				check_links(char *buff);
int				check_form(char *buff);
int				check_file(int fd, t_fillit *table, int *n);

# define VALID 0
# define NON_VALID 1

#endif
