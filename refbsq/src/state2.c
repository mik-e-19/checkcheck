/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:24:44 by gbeh              #+#    #+#             */
/*   Updated: 2021/03/09 02:51:08 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

int	*initialise_row(int size)
{
	int	*new_row;
	int idx;

	new_row = (int *)malloc(sizeof(*new_row) * (size + 1));
	idx = 0;
	while (idx < size)
	{
		new_row[idx] = 0;
		idx++;
	}
	new_row[idx] = -1;
	return (new_row);
}

int	get_num_rows(int **board)
{
	int num_rows;

	num_rows = 0;
	while (board[num_rows] != 0)
		num_rows++;
	return (num_rows);
}
