/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:13:18 by mloh              #+#    #+#             */
/*   Updated: 2021/02/27 10:53:05 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printnum(int n)
{
	if (n < 10)
	{
		ft_putchar('0');
		ft_putchar(n + '0');
	}
	else
	{
		ft_putchar(n / 10 + '0');
		ft_putchar(n % 10 + '0');
	}
}

void	ft_print_comb2(void)
{
	int num1;
	int num2;

	num1 = 0;
	while (num1 <= 99)
	{
		num2 = num1;
		while (num2 <= 99)
		{
			if (num1 != num2)
			{
				printnum(num1);
				ft_putchar(' ');
				printnum(num2);
				if (num1 != 98 || num2 != 99)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
			++num2;
		}
		++num1;
	}
}
