/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:13:12 by mloh              #+#    #+#             */
/*   Updated: 2021/03/09 22:26:20 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_10queens_test(int board[10], int x, int y)
{
	int i;

	i = -1;
	while (++i < x)
		if (y == board[i] ||
				i + board[i] == x + y ||
				i - board[i] == x - y)
			return (0);
	return (1);
}

void	ft_10queens_loop(int board[10], int *res, int pos)
{
	int i;
	int j;

	if (pos == 10)
	{
		*res += 1;
		j = -1;
		while (++j < 10)
			ft_putchar(board[j] + '0');
		ft_putchar('\n');
	}
	else
	{
		i = -1;
		while (++i < 10)
			if (ft_10queens_test(board, pos, i))
			{
				board[pos] = i;
				ft_10queens_loop(board, res, pos + 1);
			}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		board[10];
	int		i;
	int		res;

	i = -1;
	while (++i < 10)
		board[i] = -1;
	res = 0;
	ft_10queens_loop(board, &res, 0);
	return (res);
}
