/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:55:54 by gatan             #+#    #+#             */
/*   Updated: 2021/02/21 12:02:27 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_arr[] = {0, 0, 0, 1};

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(char w, char x, char y, char z)
{
	ft_putchar(w + 48);
	ft_putchar(x + 48);
	ft_putchar(' ');
	ft_putchar(y + 48);
	ft_putchar(z + 48);
	if (!((w == 9) && (x == 8) && (y == 9) && (z == 9)))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	shorten(int i, int j)
{
	g_arr[i] = 0;
	g_arr[j]++;
}

void	ft_print_comb2(void)
{
	while (!((g_arr[0] == 9) && (g_arr[1] == 9)))
	{
		print(g_arr[0], g_arr[1], g_arr[2], g_arr[3]);
		g_arr[3]++;
		if (g_arr[3] % 10 == 0)
		{
			g_arr[3] = 0;
			g_arr[2]++;
			if (g_arr[2] % 10 == 0)
			{
				g_arr[2] = g_arr[0];
				g_arr[1]++;
				if (!(g_arr[1] == 9))
					g_arr[3] = g_arr[1] + 1;
				else
					g_arr[2] = g_arr[0] + 1;
				if (g_arr[1] % 10 == 0)
				{
					shorten(1, 0);
					g_arr[2] = g_arr[0];
					g_arr[3] = g_arr[1] + 1;
				}
			}
		}
	}
}
