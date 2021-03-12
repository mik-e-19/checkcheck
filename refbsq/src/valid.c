/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:06:01 by gbeh              #+#    #+#             */
/*   Updated: 2021/03/09 17:07:18 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

int	is_valid_board(int **board)
{
	int	idx;
	int	num_rows;
	int	num_cols;
	int	col;

	num_rows = get_num_rows(board);
	if (num_rows > 0)
	{
		num_cols = get_row_size(board[0]);
		if (num_cols > 0)
		{
			idx = 0;
			while (++idx < num_rows)
			{
				col = get_row_size(board[idx]);
				if (col != num_cols)
					return (0);
			}
			return (1);
		}
	}
	return (0);
}
