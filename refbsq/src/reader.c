/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:49:10 by gbeh              #+#    #+#             */
/*   Updated: 2021/03/09 22:31:58 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	add_map_row(int **board, char *inp, char *cset)
{
	const int	buf_size = slen(inp) - 1;
	int			*row;
	int			idx;

	idx = -1;
	row = initialise_row(buf_size);
	while (++idx < buf_size)
	{
		if (inp[idx] == cset[0])
			row[idx] = 0;
		else if (inp[idx] == cset[1])
			row[idx] = 1;
		else
			row[idx] = -1;
	}
	push_row(board, row);
}

char	*read_row(int fd, int buf_size)
{
	int		idx;
	char	*row;
	char	c;

	idx = 0;
	row = (char *)malloc(sizeof(*row) * (buf_size + 1));
	while (read(fd, &c, 1) && c != '\n')
	{
		row[idx] = c;
		idx++;
		if (idx >= buf_size - 1)
		{
			row = resize_arr(row, buf_size + 1, 2 * buf_size + 1);
			buf_size *= 2;
		}
	}
	row[idx] = c;
	if (c != '\n')
		row[1] = '\0';
	row[idx + 1] = '\0';
	return (row);
}

int		parse_map_args(char *line, char **cset)
{
	const int	line_size = slen(line);
	int			rows;

	if (line_size > 4)
	{
		(*cset)[0] = line[line_size - 3];
		(*cset)[1] = line[line_size - 4];
		(*cset)[2] = line[line_size - 2];
		if ((*cset)[0] != (*cset)[1] && (*cset)[0] != (*cset)[2] &&
				(*cset)[1] != (*cset)[2])
		{
			line[line_size - 4] = '\0';
			rows = ft_atoi(&line);
			if (*line == '\0')
				return (rows);
		}
	}
	return (0);
}

int		**read_map(int fd, char **cset)
{
	int		**board;
	char	*line;
	char	*row;
	int		idx;
	int		rows;

	line = read_row(fd, 13);
	rows = parse_map_args(line, cset);
	free(line);
	board = initialise_board(rows);
	idx = 0;
	while (idx < rows)
	{
		row = read_row(fd, rows);
		if (row == 0)
			idx = rows;
		else
			add_map_row(board, row, *cset);
		if (row != 0)
			free(row);
		idx++;
	}
	if (idx > rows)
		board[0] = 0;
	return (board);
}

int		**read_map_file(char *fname, char **cset)
{
	char	*c;
	int		**board;
	int		fd;
	int		rem;

	c = 0;
	fd = open(fname, O_RDONLY);
	if (fd != -1)
	{
		board = read_map(fd, cset);
		rem = read(fd, c, 1);
		if (rem == 1)
			board[0][0] = -1;
		close(fd);
	}
	else
	{
		board = initialise_board(1);
		board[0] = 0;
	}
	return (board);
}
