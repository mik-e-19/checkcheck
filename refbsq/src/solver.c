/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:47:37 by gbeh              #+#    #+#             */
/*   Updated: 2021/03/09 11:14:31 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int		min(int **b, int row, int col)
{
	int	top_left;
	int	top_right;
	int	bottom_left;
	int	min;

	if (row == 0 || col == 0)
		return (b[row][col] - 1);
	else
	{
		top_left = b[row - 1][col - 1];
		top_right = b[row - 1][col];
		bottom_left = b[row][col - 1];
		min = top_left < top_right ? top_left : top_right;
		min = bottom_left < min ? bottom_left : min;
		return (min);
	}
}

void	draw_square(int **b, t_cell max)
{
	int	row;
	int	col;

	row = max.row;
	while (row > max.row - max.value)
	{
		col = max.col;
		while (col > max.col - max.value)
		{
			if (b[row][col] != 0)
				b[row][col] = 2;
			else
			{
				write(1, "Logic Error: Drawing over obstacle!\n", 36);
				print_board(b, "|-x");
			}
			col--;
		}
		row--;
	}
}

int		**build_soln(int **b)
{
	const int	row_size = get_row_size(b[0]);
	int			**soln;
	int			*new_row;
	int			num_rows;
	int			col;

	num_rows = 0;
	while (b[num_rows] != 0)
		num_rows++;
	soln = initialise_board(num_rows);
	new_row = initialise_row(row_size);
	num_rows = -1;
	while (b[++num_rows] != 0)
	{
		new_row = initialise_row(row_size);
		if (num_rows == 0)
		{
			col = -1;
			while (++col < row_size)
				new_row[col] = b[0][col];
		}
		new_row[0] = b[num_rows][0];
		push_row(soln, new_row);
	}
	return (soln);
}

void	solve_board(int **b)
{
	const int	row_size = get_row_size(b[0]);
	int			**soln;
	t_cell		max;
	int			row;
	int			col;

	max.value = 0;
	soln = build_soln(b);
	row = -1;
	while (b[++row] != 0)
	{
		col = -1;
		while (++col < row_size)
		{
			soln[row][col] = (b[row][col] == 0) ? 0 : min(soln, row, col) + 1;
			if (soln[row][col] > max.value)
			{
				max.value = soln[row][col];
				max.row = row;
				max.col = col;
			}
		}
	}
	free_board(soln);
	draw_square(b, max);
}
