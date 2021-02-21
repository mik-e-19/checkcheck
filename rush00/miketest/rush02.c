/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:52:21 by mloh              #+#    #+#             */
/*   Updated: 2021/02/20 21:21:55 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_hor(int x, char left, char mid, char right)
{
	if (x-- >= 1)
	{
		ft_putchar(left);
		while (x-- >= 2)
		{
			ft_putchar(mid);
		}
		if (x == 0)
		{
			ft_putchar(right);
		}
		ft_putchar('\n');
	}
}

void	print_vert(int x, int y, char down)
{
	int i;

	while (y-- > 2)
	{
		ft_putchar(down);
		i = 2;
		while (x > i++)
		{
			ft_putchar(' ');
		}
		if (--i > y)
		{
			ft_putchar(down);
		}
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x > 0)
	{
		if (y >= 1)
		{
			print_hor(x, 'A', 'B', 'A');
		}
		print_vert(x, y, 'B');
		if (y >= 2)
		{
			print_hor(x, 'C', 'B', 'C');
		}
	}
}
