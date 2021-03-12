/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:50:15 by gbeh              #+#    #+#             */
/*   Updated: 2021/03/09 14:36:48 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

int				**initialise_board(int rows)
{
	int	**board;
	int	idx;

	board = (int **)malloc(sizeof(*board) * (rows + 1));
	idx = 0;
	while (idx < rows + 1)
	{
		board[idx] = 0;
		idx++;
	}
	return (board);
}

unsigned int	get_row_size(int *row)
{
	int	size;

	size = 0;
	while (row[size] != -1)
		size++;
	return (size);
}

void			push_row(int **board, int *row)
{
	int	idx;

	idx = 0;
	while (board[idx] != 0)
		idx++;
	board[idx] = row;
	board[idx + 1] = 0;
}

void			free_board(int **board)
{
	int	idx;

	idx = 0;
	while (board[idx] != 0)
	{
		free(board[idx]);
		idx++;
	}
	free(board);
}

void			print_board(int **board, char *chrset)
{
	const unsigned int	row_size = get_row_size(board[0]);
	unsigned int		row;
	unsigned int		col;

	row = 0;
	while (board[row] != 0)
	{
		col = 0;
		while (col < row_size)
		{
			if (board[row][col] >= 0 && board[row][col] <= 2)
				write(1, &(chrset[board[row][col]]), 1);
			col++;
		}
		if (board[row][col] != -1)
			write(1, "Row is not terminated correctly. Please fix\n", 44);
		write(1, "\n", 1);
		row++;
	}
}
