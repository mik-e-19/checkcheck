/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:45:56 by gbeh              #+#    #+#             */
/*   Updated: 2021/03/09 17:06:13 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	run(int **board, char *chrset)
{
	if (is_valid_board(board))
	{
		solve_board(board);
		print_board(board, chrset);
	}
	else
		write(2, "map error\n", 10);
	free_board(board);
}

int		main(int argc, char **argv)
{
	int		**board;
	char	set[4];
	char	*cset;
	int		idx;

	cset = set;
	if (argc == 1)
	{
		board = read_map(0, &cset);
		run(board, cset);
	}
	else
	{
		idx = 1;
		while (idx < argc)
		{
			board = read_map_file(argv[idx], &cset);
			run(board, cset);
			idx++;
			if (argc > 2 && idx < argc)
				write(1, "\n", 1);
		}
	}
	return (0);
}
