/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:49:04 by gbeh              #+#    #+#             */
/*   Updated: 2021/03/08 13:23:48 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include <unistd.h>

int				**initialise_board(int rows);
int				*initialise_row(int size);
unsigned int	get_row_size(int *row);
void			free_board(int **board);
void			print_board(int **board, char *charset);
void			push_row(int **board, int *row);

typedef	struct	s_cell{
	int value;
	int row;
	int col;
}				t_cell;

#endif
